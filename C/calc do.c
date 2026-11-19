#include <stdio.h>

int main() {
    float a, b;
    int scelta;

    // Acquisizione dei due valori iniziali
    printf("Inserisci il primo valore (a): ");
    scanf("%f", &a);
    printf("Inserisci il secondo valore (b): ");
    scanf("%f", &b);

    do {
        // Visualizzazione del menu
        printf("\n====================\n");
        printf("       MENU         \n");
        printf("====================\n");
        printf("1) somma\n");
        printf("2) sottrai\n");
        printf("3) moltiplica\n");
        printf("4) dividi\n");
        printf("5) esci\n");
        printf("Inserisci la tua scelta (1-5): ");
        scanf("%d", &scelta);

        // Gestione della scelta tramite switch
        switch (scelta) {
            case 1:
                printf("Risultato: %.2f + %.2f = %.2f\n", a, b, a + b);
                break;
            case 2:
                printf("Risultato: %.2f - %.2f = %.2f\n", a, b, a - b);
                break;
            case 3:
                printf("Risultato: %.2f * %.2f = %.2f\n", a, b, a * b);
                break;
            case 4:
                if (b != 0) {
                    printf("Risultato: %.2f / %.2f = %.2f\n", a, b, a / b);
                } else {
                    printf("Errore: Impossibile dividere per zero!\n");
                }
                break;
            case 5:
                printf("Uscita dal programma. Arrivederci!\n");
                break;
            default:
                printf("Scelta non valida. Scegli un numero compreso tra 1 e 5.\n");
        }

    } while (scelta != 5);

    return 0;
}