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
			printf("Allatok:%s",mostAllatok->nev);
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

void kereses_menu(gazdi* adatok) {
	int kiv = -1;
	while (kiv != '0') {
		clear();
		printf("/// Kereses MENU ///\n");
		printf("    [1] Gazdi\n");
		printf("    [2] Allat\n");
		printf("    [3] Kezeles\n");
		printf("    [0] Kilepes\n");
		printf("    Valasztas: ");
		do {
			kiv = getchar();

		} while (kiv == '\n');
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
		clear();
		printf("/// ALLATORVOS MENU ///\n");
		printf("    [1] Kereses\n");
		printf("    [2] Lista\n");
		printf("    [0] Kilepes\n");
		printf("    Valasztas: ");
		do {
			kiv = getchar();

		} while (kiv == '\n');
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

