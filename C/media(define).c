#include <stdio.h>

#define NUMVOTI 3

float media(int voto1, int voto2, int voto3) {
    int somma;
    somma = voto1 + voto2 + voto3;
    return (float) somma / 3;
}

int main() {
    int i;
    int voti[NUMVOTI];

    for (i = 0; i < NUMVOTI; i++) {
        printf("Inserisci voto %d: ", i + 1);
        scanf("%d", &voti[i]);
    }

    printf("Voti inseriti: ");
    for (i = 0; i < NUMVOTI; i++) {
        printf("%d\t", voti[i]);
    }
    printf("\n");

    printf("La media \x8A: %.2f\n", media(voti[0], voti[1], voti[2]));

    return 0;
}
