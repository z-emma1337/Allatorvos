#include "debugmalloc.h"
#include "adatbazis.h"
#include "kez_kereses.h"
#include "menu.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>


void keresett_k(char* ker, gazdi* adatok) {
	clear();
	printf("/// TALALATOK %s /// [ENTER] Visszateres\n", ker);
	ker = kisbetus(ker);
	gazdi* mostGazdi = adatok;
	while (mostGazdi != NULL) {
		allat* mostAllat = mostGazdi->allatok;
		while (mostAllat != NULL) {


				kezeles* mostKez = mostAllat->kezelesek;
				while (mostKez != NULL) {
				char* mostLeiras = kisbetus(mostKez->leiras);
				if (strstr(mostLeiras, ker) != NULL) {
					printf("------------------------\n");
					printf("Leiras: %s\n", mostKez->leiras);
					datumTipus mostDatum = mostKez->datum;
					printf("Datum: %04d.%02d.%02d\n", mostDatum.ev, mostDatum.honap, mostDatum.nap);
					printf("Allat:%s", mostAllat->nev);

					printf("\n");
				}
				mostKez = mostKez->kov;
				free(mostLeiras);

			}
			mostAllat = mostAllat->kov;

		}
		mostGazdi = mostGazdi->kov;
	}
	free(ker);
	printf("------------------------\n");
	printf("[ENTER] Visszateres");
	getchar();
	getchar();
}

void kez_kereses(gazdi* adatok) {
	char ker[50];
	while (1) {
		clear();
		printf("/// Kezeles Kereses MENU ///\n");
		printf("    [0] Kilepes\n");
		printf("    Kereses: ");
		scanf("%s", ker);
		if (strcmp(ker, "0") == 0) {
			break;
		}
		keresett_k(ker, adatok);

	}
}