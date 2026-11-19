// ============================================================================
//  ESP-BOY  -  DOCK MODE  (video composito sul giallo RCA, UN SOLO PIN)
//  256x240, B/N a 6 grigi, PAL 50 Hz (312 righe progressive)
//  Nessuna libreria extra. Funziona con il core ESP32 3.x.
//
//  Come funziona: il pin e' pilotato da SPI2 (HSPI) a 40 MHz con DMA, come
//  flusso a 1 bit. Ogni pixel e' 1 byte = 8 bit a densita' di impulsi
//  (0..8 uni su 8): la densita' diventa tensione grazie al filtro RC.
//
//  COLLEGAMENTO (1 pin, 1 resistore, 1 condensatore):
//
//      GPIO13 ---[ 130 Ohm ]---+---> centrale RCA giallo
//                              |
//                          [ 470 pF ]
//                              |
//      GND --------------------+---> calza RCA giallo
//
//  (130 Ohm: va bene anche 120 o 150. Condensatore: 330..680 pF, ceramico.)
//  Livelli con TV da 75 Ohm: sync 0V, nero 0.30V, bianco ~1.05V.
//
//  SKETCH STANDALONE: niente riga OTA (non parte dal launcher/multitool).
//  Partition scheme: Minimal SPIFFS (APP con OTA) va bene.
// ============================================================================

#include <Adafruit_GFX.h>
#include "driver/spi_master.h"
#include "esp_heap_caps.h"
#include "freertos/FreeRTOS.h"
#include "freertos/task.h"

// ----------------------------- PARAMETRI ------------------------------------
#define PIN_VIDEO        13     // MOSI di HSPI (pin nativo: 40 MHz garantiti)
#define PIN_SD_CS         5
#define PIN_TFT_CS       15
#define VID_FIRST_LINE   46     // riga TV da cui parte l'immagine (sposta su/giu')
// ----------------------------------------------------------------------------

#define VID_W            256
#define VID_H            240
#define BYTES_PER_LINE   320    // 2560 bit a 40 MHz = 64.0 us
#define HEAD_BYTES        52    // sync (24) + back porch (28)
#define SYNC_BYTES        24    // ~4.8 us
#define FRAME_LINES      312
#define VSYNC_LINES        3
#define VSYNC_LOW_BYTES  296    // impulso largo di vsync
#define FRAME_BYTES      (FRAME_LINES * BYTES_PER_LINE)

#define LV_BLACK          2     // 2/8 di densita' = 0.30 V
#define LV_WHITE          7     // 7/8 di densita' = ~1.05 V

static uint8_t *g_frame = nullptr;
static uint8_t  g_pat[9];
static spi_device_handle_t g_spi = nullptr;
static spi_transaction_t   g_trans[2];
static volatile uint32_t   g_frames = 0;

static void videoTask(void *) {
  for (int i = 0; i < 2; i++) {
    memset(&g_trans[i], 0, sizeof(spi_transaction_t));
    g_trans[i].length = (size_t)FRAME_BYTES * 8;
    g_trans[i].tx_buffer = g_frame;
    spi_device_queue_trans(g_spi, &g_trans[i], portMAX_DELAY);
  }
  for (;;) {
    spi_transaction_t *r = nullptr;
    if (spi_device_get_trans_result(g_spi, &r, portMAX_DELAY) == ESP_OK && r) {
      g_frames++;
      spi_device_queue_trans(g_spi, r, portMAX_DELAY);
    }
  }
}

static inline uint8_t colorToPat(uint16_t c) {
  uint16_t r = (c >> 11) << 3;
  uint16_t g = ((c >> 5) & 63) << 2;
  uint16_t b = (c & 31) << 3;
  uint16_t y = (r * 77 + g * 150 + b * 29) >> 8;     // 0..255
  return g_pat[LV_BLACK + ((y * 6) >> 8)];           // livelli 2..7
}

static inline uint8_t *rowPtr(int y) {
  return g_frame + (VID_FIRST_LINE + y) * BYTES_PER_LINE + HEAD_BYTES;
}

class DockVideo : public Adafruit_GFX {
public:
  DockVideo() : Adafruit_GFX(VID_W, VID_H) {}

  bool begin() {
    g_frame = (uint8_t *)heap_caps_malloc(FRAME_BYTES, MALLOC_CAP_DMA);
    if (!g_frame) return false;

    // pattern a densita' k/8, bit distribuiti uniformemente (MSB = primo bit)
    for (int k = 0; k <= 8; k++) {
      uint8_t b = 0;
      for (int i = 0; i < 8; i++) {
        int bit = ((i + 1) * k) / 8 - (i * k) / 8;
        b |= (uint8_t)(bit << (7 - i));
      }
      g_pat[k] = b;
    }

    for (int line = 0; line < FRAME_LINES; line++) {
      uint8_t *L = g_frame + line * BYTES_PER_LINE;
      if (line < VSYNC_LINES) {
        memset(L, 0x00, VSYNC_LOW_BYTES);
        memset(L + VSYNC_LOW_BYTES, g_pat[LV_BLACK], BYTES_PER_LINE - VSYNC_LOW_BYTES);
      } else {
        memset(L, 0x00, SYNC_BYTES);
        memset(L + SYNC_BYTES, g_pat[LV_BLACK], BYTES_PER_LINE - SYNC_BYTES);
      }
    }

    spi_bus_config_t bus = {};
    bus.mosi_io_num = PIN_VIDEO;
    bus.miso_io_num = -1;
    bus.sclk_io_num = -1;
    bus.quadwp_io_num = -1;
    bus.quadhd_io_num = -1;
    bus.max_transfer_sz = FRAME_BYTES;
    if (spi_bus_initialize(SPI2_HOST, &bus, SPI_DMA_CH_AUTO) != ESP_OK) return false;

    spi_device_interface_config_t dev = {};
    dev.clock_speed_hz = 40 * 1000 * 1000;
    dev.mode = 0;
    dev.spics_io_num = -1;
    dev.queue_size = 2;
    dev.flags = SPI_DEVICE_HALFDUPLEX | SPI_DEVICE_NO_DUMMY;
    if (spi_bus_add_device(SPI2_HOST, &dev, &g_spi) != ESP_OK) return false;

    xTaskCreatePinnedToCore(videoTask, "video", 4096, nullptr,
                            configMAX_PRIORITIES - 2, nullptr, 0);
    return true;
  }

  // attende la fine del frame (inizio vblank): disegnare subito dopo
  void waitFrame() {
    uint32_t f = g_frames;
    uint32_t t = millis();
    while (g_frames == f && millis() - t < 100) delay(1);
  }

  void drawPixel(int16_t x, int16_t y, uint16_t c) override {
    if (x < 0 || y < 0 || x >= _width || y >= _height) return;
    int16_t px = x, py = y;
    switch (rotation) {
      case 1: px = WIDTH - 1 - y; py = x; break;
      case 2: px = WIDTH - 1 - x; py = HEIGHT - 1 - y; break;
      case 3: px = y; py = HEIGHT - 1 - x; break;
    }
    rowPtr(py)[px] = colorToPat(c);
  }

  void fillRect(int16_t x, int16_t y, int16_t w, int16_t h, uint16_t c) override {
    if (rotation) { Adafruit_GFX::fillRect(x, y, w, h, c); return; }
    if (x < 0) { w += x; x = 0; }
    if (y < 0) { h += y; y = 0; }
    if (x + w > VID_W) w = VID_W - x;
    if (y + h > VID_H) h = VID_H - y;
    if (w <= 0 || h <= 0) return;
    uint8_t v = colorToPat(c);
    for (int yy = y; yy < y + h; yy++) memset(rowPtr(yy) + x, v, w);
  }

  void drawFastHLine(int16_t x, int16_t y, int16_t w, uint16_t c) override { fillRect(x, y, w, 1, c); }
  void drawFastVLine(int16_t x, int16_t y, int16_t h, uint16_t c) override { fillRect(x, y, 1, h, c); }
  void fillScreen(uint16_t c) override { fillRect(0, 0, _width, _height, c); }
};

DockVideo dock;

// -------------------------------- DEMO --------------------------------------
static int bx = 30, by = 170, bdx = 3, bdy = 2;

static void drawTestCard() {
  dock.fillScreen(0x0000);
  dock.drawRect(8, 8, VID_W - 16, VID_H - 16, 0xFFFF);

  dock.setTextColor(0xFFFF);
  dock.setTextSize(3);
  dock.setCursor(11, 20);
  dock.print("GGA DOCK MODE");
  dock.setTextSize(2);
  dock.setCursor(62, 52);
  dock.print("VIDEO 1 PIN");

  for (int i = 0; i < 6; i++) {
    uint8_t l = i * 51;
    dock.fillRect(20 + i * 36, 84, 36, 50, dock.color565(l, l, l));
  }
  dock.drawRect(20, 84, 216, 50, 0xFFFF);
}

void setup() {
  pinMode(PIN_SD_CS, OUTPUT);  digitalWrite(PIN_SD_CS, HIGH);
  pinMode(PIN_TFT_CS, OUTPUT); digitalWrite(PIN_TFT_CS, HIGH);

  if (!dock.begin()) {
    while (true) delay(1000);
  }
  drawTestCard();
}

void loop() {
  dock.waitFrame();
  dock.fillRect(bx, by, 20, 20, 0x0000);
  bx += bdx; by += bdy;
  if (bx < 16 || bx > 220) { bdx = -bdx; bx += bdx; }
  if (by < 150 || by > 208) { bdy = -bdy; by += bdy; }
  dock.fillRect(bx, by, 20, 20, 0xFFFF);
}
