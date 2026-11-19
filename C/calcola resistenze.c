#include<stdio.h>
void main (){
	int v1,v2,v3,tol;
	float mol,ris;
	
	printf ("===============\n");
	printf ("|primo valore|\n");
	printf ("|0-nero      |\n");
	printf ("|1-marrone   |\n");
	printf ("|2-rosso     |\n");
	printf ("|3-arancione |\n");
	printf ("|4-giallo    |\n");
	printf ("|5-verde     |\n");
	printf ("|6-blu       |\n");
	printf ("|7-viola     |\n");
	printf ("|8-grigio    |\n");
	printf ("|9-bianco    |\n");
	
	printf ("\n");
	printf("inserisci valore 1: ");
	scanf("%d",&v1);

	system("cls");
	
	printf ("===============================\n");
	printf ("|primo valore |secondo valore|\n");
	printf ("|0-nero       |0-nero        |\n");
	printf ("|1-marrone    |1-marrone     |\n");
	printf ("|2-rosso      |2-rosso       |\n");
	printf ("|3-arancione  |3-arancione   |\n");
	printf ("|4-giallo     |4-giallo      |\n");
	printf ("|5-verde      |5-verde       |\n");
	printf ("|6-blu        |6-blu         |\n");
	printf ("|7-viola      |7-viola       |\n");
	printf ("|8-grigio     |8-grigio      |\n");
	printf ("|9-bianco     |9-bianco      |\n");
	
	printf ("|#############|\n|");
	
	switch (v1) {
	case 0: printf("nero     ");     break;
	case 1: printf("marrone  ");  break;
	case 2: printf("rosso    ");    break;
	case 3: printf("arancione"); break;
	case 4: printf("giallo   ");   break;
	case 5: printf("verde    ");    break;
	case 6: printf("blu      ");      break;
	case 7: printf("viola    ");    break;
	case 8: printf("grigio   ");   break;
	case 9: printf("bianco   ");   break;
}

	printf("    |inserisci valore 2: ");
	scanf("%d",&v2);


	system("cls");
	
	printf ("============================================\n");
	printf ("|primo valore |secondo valore |terzo valore|\n");
	printf ("|0-nero       |0-nero         |0-nero      |\n");
	printf ("|1-marrone    |1-marrone      |1-marrone   |\n");
	printf ("|2-rosso      |2-rosso        |2-rosso     |\n");
	printf ("|3-arancione  |3-arancione    |3-arancione |\n");
	printf ("|4-giallo     |4-giallo       |4-giallo    |\n");
	printf ("|5-verde      |5-verde        |5-verde     |\n");
	printf ("|6-blu        |6-blu          |6-blu       |\n");
	printf ("|7-viola      |7-viola        |7-viola     |\n");
	printf ("|8-grigio     |8-grigio       |8-grigio    |\n");
	printf ("|9-bianco     |9-bianco       |9-bianco    |\n");
	
	printf ("|#############|###############|\n");
	
switch (v1) {
	case 0: printf("|nero     "); break;
	case 1: printf("|marrone  "); break;
	case 2: printf("|rosso    "); break;
	case 3: printf("|arancione"); break;
	case 4: printf("|giallo   "); break;
	case 5: printf("|verde    "); break;
	case 6: printf("|blu      "); break;
	case 7: printf("|viola    "); break;
	case 8: printf("|grigio   "); break;
	case 9: printf("|bianco   "); break;
}
	printf("    ");
	
switch (v2) {
	case 0: printf("|nero     "); break;
	case 1: printf("|marrone  "); break;
	case 2: printf("|rosso    "); break;
	case 3: printf("|arancione"); break;
	case 4: printf("|giallo   "); break;
	case 5: printf("|verde    "); break;
	case 6: printf("|blu      "); break;
	case 7: printf("|viola    "); break;
	case 8: printf("|grigio   "); break;
	case 9: printf("|bianco   "); break;
}
	
	printf("      | inserisci valore 3: ");
	scanf("%d",&v3);
	
	system("cls");
	
	printf ("============================================================\n");
	printf ("|primo valore |secondo valore |terzo valore|moltiplicatore |\n");
	printf ("|0-nero       |0-nero         |0-nero      |1-nero         |\n");
	printf ("|1-marrone    |1-marrone      |1-marrone   |10-marrone     |\n");
	printf ("|2-rosso      |2-rosso        |2-rosso     |100-rosso      |\n");
	printf ("|3-arancione  |3-arancione    |3-arancione |1000-arancione |\n");
	printf ("|4-giallo     |4-giallo       |4-giallo    |10000-giallo   |\n");
	printf ("|5-verde      |5-verde        |5-verde     |100000-verde   |\n");
	printf ("|6-blu        |6-blu          |6-blu       |1000000-blu    |\n");
	printf ("|7-viola      |7-viola        |7-viola     |               |\n");
	printf ("|8-grigio     |8-grigio       |8-grigio    |0.1-oro        |\n");
	printf ("|9-bianco     |9-bianco       |9-bianco    |0.01-argento   |\n");
	
	printf ("|#############|###############|############|\n");
	
switch (v1) {
	case 0: printf("|nero     "); break;
	case 1: printf("|marrone  "); break;
	case 2: printf("|rosso    "); break;
	case 3: printf("|arancione"); break;
	case 4: printf("|giallo   "); break;
	case 5: printf("|verde    "); break;
	case 6: printf("|blu      "); break;
	case 7: printf("|viola    "); break;
	case 8: printf("|grigio   "); break;
	case 9: printf("|bianco   "); break;
}
	printf("    ");
	
switch (v2) {
	case 0: printf("|nero     "); break;
	case 1: printf("|marrone  "); break;
	case 2: printf("|rosso    "); break;
	case 3: printf("|arancione"); break;
	case 4: printf("|giallo   "); break;
	case 5: printf("|verde    "); break;
	case 6: printf("|blu      "); break;
	case 7: printf("|viola    "); break;
	case 8: printf("|grigio   "); break;
	case 9: printf("|bianco   "); break;
}
	
	printf("      ");
 
switch (v3) {
	case 0: printf("|nero     "); break;
	case 1: printf("|marrone  "); break;
	case 2: printf("|rosso    "); break;
	case 3: printf("|arancione"); break;
	case 4: printf("|giallo   "); break;
	case 5: printf("|verde    "); break;
	case 6: printf("|blu      "); break;
	case 7: printf("|viola    "); break;
	case 8: printf("|grigio   "); break;
	case 9: printf("|bianco   "); break;
}

		printf("   |inserisci valore moltiplicatore: ");
	scanf("%f", &mol);
	
	system("cls");
	
	printf ("========================================================================\n");
	printf ("|primo valore |secondo valore |terzo valore|moltiplicatore |tolleranza |\n");
	printf ("|0-nero       |0-nero         |0-nero      |1-nero         |           |\n");
	printf ("|1-marrone    |1-marrone      |1-marrone   |10-marrone     |1-marrone  |\n");
	printf ("|2-rosso      |2-rosso        |2-rosso     |100-rosso      |2-rossso   |\n");
	printf ("|3-arancione  |3-arancione    |3-arancione |1000-arancione |           |\n");
	printf ("|4-giallo     |4-giallo       |4-giallo    |10000-giallo   |           |\n");
	printf ("|5-verde      |5-verde        |5-verde     |100000-verde   |           |\n");
	printf ("|6-blu        |6-blu          |6-blu       |1000000-blu    |           |\n");
	printf ("|7-viola      |7-viola        |7-viola     |               |           |\n");
	printf ("|8-grigio     |8-grigio       |8-grigio    |0.1-oro        |5-oro      |\n");
	printf ("|9-bianco     |9-bianco       |9-bianco    |0.01-argento   |10-argento |\n");
	
	printf ("|#############|###############|############|###############|###########|\n");
	
switch (v1) {
	case 0: printf("|nero     "); break;
	case 1: printf("|marrone  "); break;
	case 2: printf("|rosso    "); break;
	case 3: printf("|arancione"); break;
	case 4: printf("|giallo   "); break;
	case 5: printf("|verde    "); break;
	case 6: printf("|blu      "); break;
	case 7: printf("|viola    "); break;
	case 8: printf("|grigio   "); break;
	case 9: printf("|bianco   "); break;
}
	printf("    ");
	
switch (v2) {
	case 0: printf("|nero     "); break;
	case 1: printf("|marrone  "); break;
	case 2: printf("|rosso    "); break;
	case 3: printf("|arancione"); break;
	case 4: printf("|giallo   "); break;
	case 5: printf("|verde    "); break;
	case 6: printf("|blu      "); break;
	case 7: printf("|viola    "); break;
	case 8: printf("|grigio   "); break;
	case 9: printf("|bianco   "); break;
}
	
	printf("      ");
 
switch (v3) {
	case 0: printf("|nero     "); break;
	case 1: printf("|marrone  "); break;
	case 2: printf("|rosso    "); break;
	case 3: printf("|arancione"); break;
	case 4: printf("|giallo   "); break;
	case 5: printf("|verde    "); break;
	case 6: printf("|blu      "); break;
	case 7: printf("|viola    "); break;
	case 8: printf("|grigio   "); break;
	case 9: printf("|bianco   "); break;
}

	printf("   ");

	if      (mol == 1)        printf("|nero     ");
	else if (mol == 10)       printf("|marrone  ");
	else if (mol == 100)      printf("|rosso    ");
	else if (mol == 1000)     printf("|arancione");
	else if (mol == 10000)    printf("|giallo   ");
	else if (mol == 100000)   printf("|verde    ");
	else if (mol == 1000000)  printf("|blu      ");
	else if (mol == 0.1f)     printf("|oro      ");
	else if (mol == 0.01f)    printf("|argento  ");
	else                      printf("|null     ");

	printf("      | inserisci tolleranza: ");
	scanf("%d",&tol);
	
	system("cls");
	
	printf ("========================================================================\n");
	printf ("|primo valore |secondo valore |terzo valore|moltiplicatore |tolleranza |\n");
	printf ("|0-nero       |0-nero         |0-nero      |1-nero         |           |\n");
	printf ("|1-marrone    |1-marrone      |1-marrone   |10-marrone     |1-marrone  |\n");
	printf ("|2-rosso      |2-rosso        |2-rosso     |100-rosso      |2-rossso   |\n");
	printf ("|3-arancione  |3-arancione    |3-arancione |1000-arancione |           |\n");
	printf ("|4-giallo     |4-giallo       |4-giallo    |10000-giallo   |           |\n");
	printf ("|5-verde      |5-verde        |5-verde     |100000-verde   |           |\n");
	printf ("|6-blu        |6-blu          |6-blu       |1000000-blu    |           |\n");
	printf ("|7-viola      |7-viola        |7-viola     |               |           |\n");
	printf ("|8-grigio     |8-grigio       |8-grigio    |0.1-oro        |5-oro      |\n");
	printf ("|9-bianco     |9-bianco       |9-bianco    |0.01-argento   |10-argento |\n");
	
	printf ("|#############|###############|############|###############|###########|\n");
	
switch (v1) {
	case 0: printf("|nero     "); break;
	case 1: printf("|marrone  "); break;
	case 2: printf("|rosso    "); break;
	case 3: printf("|arancione"); break;
	case 4: printf("|giallo   "); break;
	case 5: printf("|verde    "); break;
	case 6: printf("|blu      "); break;
	case 7: printf("|viola    "); break;
	case 8: printf("|grigio   "); break;
	case 9: printf("|bianco   "); break;
}
	printf("    ");
	
switch (v2) {
	case 0: printf("|nero     "); break;
	case 1: printf("|marrone  "); break;
	case 2: printf("|rosso    "); break;
	case 3: printf("|arancione"); break;
	case 4: printf("|giallo   "); break;
	case 5: printf("|verde    "); break;
	case 6: printf("|blu      "); break;
	case 7: printf("|viola    "); break;
	case 8: printf("|grigio   "); break;
	case 9: printf("|bianco   "); break;
}
	
	printf("      ");
 
switch (v3) {
	case 0: printf("|nero     "); break;
	case 1: printf("|marrone  "); break;
	case 2: printf("|rosso    "); break;
	case 3: printf("|arancione"); break;
	case 4: printf("|giallo   "); break;
	case 5: printf("|verde    "); break;
	case 6: printf("|blu      "); break;
	case 7: printf("|viola    "); break;
	case 8: printf("|grigio   "); break;
	case 9: printf("|bianco   "); break;
}

	printf("   ");

	if      (mol == 1)        printf("|nero     ");
	else if (mol == 10)       printf("|marrone  ");
	else if (mol == 100)      printf("|rosso    ");
	else if (mol == 1000)     printf("|arancione");
	else if (mol == 10000)    printf("|giallo   ");
	else if (mol == 100000)   printf("|verde    ");
	else if (mol == 1000000)  printf("|blu      ");
	else if (mol == 0.1f)     printf("|oro      ");
	else if (mol == 0.01f)    printf("|argento  ");
	else                      printf("|null     ");

	printf("      ");
	
switch (tol) {
	case 0:  printf("|null       |"); break;
	case 1:  printf("|marrone    |"); break;
	case 2:  printf("|rosso      |"); break;
	case 3:  printf("|null       |"); break;
	case 4:  printf("|null       |"); break;
	case 5:  printf("|oro        |"); break;
	case 6:  printf("|null       |"); break;
	case 7:  printf("|null       |"); break;
	case 8:  printf("|null       |"); break;
	case 9:  printf("|null       |"); break;
	case 10: printf("|argento    |"); break;
}
	printf ("\n========================================================================\n");
	
	ris = ((v1 * 100) + (v2 * 10) + v3) * mol;
	
	printf("il resistore \x8a da %.2f ohm con tolleranza %d%% \n", ris, tol);
	
	system("PAUSE >nul");
	return 0;
}