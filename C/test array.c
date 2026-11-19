#include <stdio.h>

int i, j, n1[2], n2[2];
float IPO, somma, x;

int main()
{
    for (i = 0; i < 2; i++) {
        printf("inserisci primo numero: ");
        scanf("%d", &n1[i]);
    }

    for (j = 0; j < 2; j++) {
        printf("inserisci secondo numero: ");
        scanf("%d", &n2[j]);
    }

    somma = (n2[0] - n1[0]) * (n2[0] - n1[0]) + (n2[1] - n1[1]) * (n2[1] - n1[1]);

    x = somma;
    IPO = 0;
    if (somma > 0) {
        IPO = somma;
        for (i = 0; i < 50; i++) {
            IPO = (IPO + somma / IPO) / 2;
        }
    }

    printf("%f\n", IPO);

    return 0;
}