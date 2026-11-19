#include <stdio.h>

int main(){
	
	int v1, v2, v3, v4, v5,vf ;
	
	printf("inserisci il primo voto: ");
	scanf ("%d", &v1);
	printf("inserisci il secondo voto: ");
	scanf ("%d", &v2);
	printf("inserisci il terzo voto: ");
	scanf ("%d", &v3);
	printf("inserisci il quarto voto: ");
	scanf ("%d", &v4);
	printf("inserisci il quinto voto: ");
	scanf ("%d", &v5);
	
	vf=(v1+v2+v3+v4+v5)/5;
	
	printf("il voto finale \x8a %d", vf);
	
	if (vf >= 6) {
    printf(" ,PROMOSSO");
    return 0; 
	}

	
	if (vf==6){
	printf(" ,PROMOSSO");
	return 0;
	}
	
	if (vf<=6){
	printf(" ,BOCCIATO");	
	return 0;
	}
}
