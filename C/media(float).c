#include<stdio.h>

void main(){

int voto[10], i, somma=0;
float media;

for (i=0;i<10;i++){
printf ("inserisci voto: ");
scanf ("%d",& voto[i]);
somma=voto[i]+somma;
}

media=(float)somma/10;

printf ("la media è %f", media);
}