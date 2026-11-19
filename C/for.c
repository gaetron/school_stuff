#include <stdio.h>

int main (){
	int i, num, voto, somma=0;
	float media;
	
	printf("quanti valori useremo?: ");
	scanf("%d", &num);
	
	for (i=0;i<num;i++){
		printf("inserisci il voto: ");
		scanf("%d", &voto);
		somma=somma+voto;
	}
	media=(float)somma/num;
	
	printf("la media \x8a %f",media);
	
	if(media>=6)
	8
	printf(", promosso");
	else
	printf(", bocciato");
}
