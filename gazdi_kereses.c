#include "debugmalloc.h"
#include "adatbazis.h"
#include "gazdi_kereses.h"
#include "menu.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>


/*
* keresett_g:gazdira keres, megkapja a felhasználó keresését és a fejgazdit, nincs visszatérési értéke.
* végig megy az adatbázis gazdijain amíg egyezést nem talál a keresés és gazdi név között
* kiírja keresésnek megfelelt gazdik összes adatát
*/
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
			if (mostAllatok != NULL) {
				printf("Allatok:%s", mostAllatok->nev);
				mostAllatok = mostAllatok->kov;

			}
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
/*
* gazdi_kereses: megkapja a fejgazdit, nincs visszatérési érték
* elkéri a felhasználótól, hogy melyik gazdira akar keresni majd meghívja a keresett_g-t
*/
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