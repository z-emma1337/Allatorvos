#include "debugmalloc.h"
#include "adatbazis.h"
#include <stdio.h>
#include <ctype.h>
#include <string.h>

char* kisbetus(char szoveg[]) {
	char* re = malloc(strlen(szoveg) + 1);
	for (int i = 0; szoveg[i] != '\0';i++) {
		re[i] = tolower(szoveg[i]);
	}
	re[strlen(szoveg)] = '\0';

	return re;
}

void clear() {
	printf("\033[H\033[J");
}

void keresett_g(char* ker, gazdi* adatok) {
	clear();
	printf("/// TALALATOK %s ///\n", ker);
	ker = kisbetus(ker);
	while (adatok != NULL) {
		char* kereszt = kisbetus(adatok->nev.kereszt);
		char* vezetek = kisbetus(adatok->nev.vezetek);
		if (strstr(kereszt, ker) != NULL || strstr(vezetek, ker) != NULL) {
			printf("Nev: %s %s\n", adatok->nev.vezetek, adatok->nev.kereszt);
			printf("Telefonszam: %s\n", adatok->telefon);
			printf("Allatok:\n");

			allat* mostAllatok = adatok->allatok;
			while (mostAllatok != NULL) {
				printf("\t%s\n", mostAllatok->nev);
				mostAllatok = mostAllatok->kov;
			}

		}
		adatok = adatok->kov;
		free(kereszt);
		free(vezetek);
	}
	free(ker);

	printf("\nNyomj Entert a visszalepeshez...");
	getchar();
}

void gazdi_kereses(gazdi* adatok) {
	clear();
	char ker[50];
	while (1) {
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

void kereses_menu(gazdi* adatok) {
	int kiv = -1;
	while (kiv != '0') {
		printf("/// Kereses MENU ///\n");
		printf("    [1] Gazdi\n");
		printf("    [2] Allat\n");
		printf("    [3] Kezeles\n");
		printf("    [0] Kilepes\n");
		printf("    Valasztas: ");
		kiv = getchar();
		switch (kiv) {
		case '1':
			gazdi_kereses(adatok);
			break;
		case '2':
			//
			break;
		case '3':
			//
			break;
		case '0':
				break;

			default:
				printf("Hiba! A menupont szamat valaszd!");
		}
	}
}

void menu_init(gazdi* adatok) {
	int kiv = -1;
	while (kiv != '0') {
		printf("/// ALLATORVOS MENU ///\n");
		printf("    [1] Kereses\n");
		printf("    [2] Lista\n");
		printf("    [0] Kilepes\n");
		printf("    Valasztas: ");
		kiv = getchar();
		switch (kiv) {
		case '1':
			kereses_menu(adatok);
			break;
		case '2':
			break;
		case '0':
			break;
		default:
			printf("Hiba! A menupont szamat valaszd!");
		}
	}






}

