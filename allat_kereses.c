#include "debugmalloc.h"
#include "adatbazis.h"
#include "allat_kereses.h"
#include "menu.h"
#include <stdio.h>
#include <ctype.h>
#include <string.h>

void keresett_a(char* ker, gazdi* adatok) {
	clear();
	printf("/// TALALATOK %s /// [ENTER] Visszateres\n", ker);
	ker = kisbetus(ker);
	gazdi* mostGazdi = adatok;
	while ( mostGazdi!= NULL) {
		allat* mostAllat = mostGazdi->allatok;
		while (mostAllat != NULL) {
			char* mostNev = kisbetus(mostAllat->nev);
			if (strstr(mostNev, ker) != NULL) {
				printf("------------------------\n");
				printf("Nev: %s\n", mostAllat->nev);
				printf("Gazdi: %s %s\n", mostGazdi->nev.vezetek, mostGazdi->nev.kereszt);
				datumTipus mostOltas = mostAllat->oltas;
				printf("Oltas: %04d.%02d.%02d\n", mostOltas.ev, mostOltas.honap, mostOltas.nap);
				kezeles* mostKezelesek = mostAllat->kezelesek;
				printf("Kezelesek:%s", mostKezelesek->leiras);
				mostKezelesek = mostKezelesek->kov;
				while (mostKezelesek != NULL) {
					printf("\n\t  %s", mostKezelesek->leiras);
					mostKezelesek = mostKezelesek->kov;
				}
				printf("\n");
			}

			mostAllat = mostAllat->kov;
			free(mostNev);

		}
		mostGazdi = mostGazdi->kov;
	}
	free(ker);
	printf("------------------------\n");
	printf("[ENTER] Visszateres");
	getchar();
	getchar();
}

void allat_kereses(gazdi* adatok) {
	char ker[50];
	while (1) {
		clear();
		printf("/// Allat Kereses MENU ///\n");
		printf("    [0] Kilepes\n");
		printf("    Kereses: ");
		scanf("%s", ker);
		if (strcmp(ker, "0") == 0) {
			break;
		}
		keresett_a(ker, adatok);

	}
}