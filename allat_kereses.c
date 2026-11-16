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

	while (adatok != NULL) {
		while (adatok->allatok != NULL) {
			if (strstr(adatok->allatok->nev, ker) != NULL) {
				printf("------------------------\n");
				printf("Nev: %s\n", adatok->allatok->nev);
				printf("Gazdi: %s %s\n", adatok->nev.vezetek, adatok->nev.kereszt);
				datumTipus mostOltas = adatok->allatok->oltas;
				printf("Oltas: 04%d.02%d.01%d\n", mostOltas.ev, mostOltas.honap, mostOltas.nap);
				kezeles* mostKezelesek = adatok->allatok->kezelesek;
				printf("Kezelesek:%s", mostKezelesek->leiras);
				mostKezelesek = mostKezelesek->kov;
				while (mostKezelesek != NULL) {
					printf("\n\t%s", mostKezelesek->leiras);
					mostKezelesek = mostKezelesek->kov;
				}
				printf("\n");
			}

			adatok->allatok = adatok->allatok->kov;
		}
		adatok = adatok->kov;
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