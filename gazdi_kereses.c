#include "debugmalloc.h"
#include "adatbazis.h"
#include "gazdi_kereses.h"
#include "menu.h"
#include <stdio.h>
#include <ctype.h>
#include <string.h>
//Kiírja a találatokat, megkapja a beírt szöveget és a fő változót
// külön változóba menti a kisbetűs kereszt- és vezetéknevet, összehasonlít, kiír
//lépteti a láncszemeket, majd a végén felszabadít 
void keresett_g(char* ker, gazdi* adatok) {
	clear();
	printf("/// TALALATOK %s /// [ENTER] Visszateres\n", ker);
	ker = kisbetus(ker);
	while (adatok != NULL) {
		char* kereszt = kisbetus(adatok->nev.kereszt);
		char* vezetek = kisbetus(adatok->nev.vezetek);
		if (strstr(kereszt, ker) != NULL || strstr(vezetek, ker) != NULL) {
			printf("------------------------\n");
			printf("Nev: %s %s\n", adatok->nev.vezetek, adatok->nev.kereszt);
			printf("Telefonszam: %s\n", adatok->telefon);
			allat* mostAllatok = adatok->allatok;
			printf("Allatok:%s", mostAllatok->nev);
			mostAllatok = mostAllatok->kov;
			while (mostAllatok != NULL) {
				printf("\n\t%s", mostAllatok->nev);
				mostAllatok = mostAllatok->kov;
			}
			printf("\n");

		}
		adatok = adatok->kov;
		free(kereszt);
		free(vezetek);
	}
	free(ker);
	printf("------------------------\n");
	printf("[ENTER] Visszateres");
	getchar();
	getchar();
}
// paramétere az fő változó, ha nem 0-át ír be, meghívja a keresett függvényt
void gazdi_kereses(gazdi* adatok) {
	char ker[50];
	while (1) {
		clear();
		printf("/// Gazdi Kereses MENU ///\n");
		printf("    [0] Kilepes\n");
		printf("    Kereses: ");
		scanf("%s", ker);
		if (strcmp(ker, "0") == 0) {
			break;
		}
		keresett_g(ker, adatok);



	}
}