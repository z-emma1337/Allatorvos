#include "debugmalloc.h"
#include "adatbazis.h"
#include "menu.h"
#include "gazdi_kereses.h"
#include "allat_kereses.h"
#include "kez_kereses.h"
#include "lista.h"
#include "adatkezeles.h"
#include <string.h>
#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>

// visszaad egy lefoglalt méretű karakter pointert csupa kisbetűkkel a nagybetűs hibák elkerülése érdekében
char* kisbetus(char szoveg[]) {
	char* re = malloc(strlen(szoveg) + 1);
	if (re == NULL) {
		return NULL;
	}
	for (int i = 0; szoveg[i] != '\0'; i++) {
		re[i] = tolower(szoveg[i]);
	}
	re[strlen(szoveg)] = '\0';

	return re;
}

//törli a terminál tartalmát külön definiálva windows és linuxra
void clear() {
#ifdef _WIN32
	system("cls");
#else
	system("clear");
#endif
}

//paramétere a fő változó, kiírja a keresés menüt, kezeli a kiválasztást
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
			allat_kereses(adatok);
			break;
		case '3':
			kez_kereses(adatok);
			break;
		case '0':
			break;
		default:
			printf("Hiba! A menupont szamat valaszd!");
		}
	}
}
//paramétere a fő változó, kiírja a menüt, kezeli a kiválasztást
gazdi* menu_init(gazdi* adatok) {
	int kiv = -1;
	while (kiv != '0') {
		clear();
		printf("/// ALLATORVOS MENU ///\n");
		printf("    [1] Kereses\n");
		printf("    [2] Lista\n");
		printf("    [3] Adatok kezelese\n");
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
			lista(adatok);
			break;
		case '3':
			adatok = adatkezeles(adatok);
			break;
		case '0':
			break;
		default:
			printf("Hiba! A menupont szamat valaszd!");
		}
	}
	return adatok;
}

