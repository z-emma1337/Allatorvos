#include "debugmalloc.h"
#include "adatbazis.h"
#include "adatkezeles.h"
#include "menu.h"
#include <stdio.h>
#include <ctype.h>
#include <string.h>

void gazdi_hozzaad(gazdi* adatok) {
	int kiv = -1;
	while (kiv != '0') {
		nevTipus nev;
		clear();
		printf("/// UJ GAZDI HOZZAADASA ///\n");
		printf("Vezeteknev: ");
		scanf("%s", nev.vezetek);
		getchar();

		clear();
		printf("/// UJ GAZDI HOZZAADASA ///\n");
		printf("Vezeteknev: %s\n", nev.vezetek);
		printf("Keresztnev: ");
		scanf("%s", nev.kereszt);
		getchar();

		clear();
		printf("/// UJ GAZDI HOZZAADASA ///\n");
		printf("Nev: %s %s\n", nev.vezetek, nev.kereszt);
		printf("Telefonszam: ");
		char telefon[11];
		scanf("%s", telefon);
		getchar();


		clear();
		printf("/// UJ GAZDI HOZZAADASA ///\n");
		printf("Nev: %s %s\n", nev.vezetek, nev.kereszt);
		printf("Telefonszam: %s\n", telefon);
		printf("[0] Kilepes [1] Mentes\n");
		printf("Valasztas:");
		do {
			kiv = getchar();

		} while (kiv == '\n');
		switch (kiv) {
		case '1':
			gazdi * uj = ujGazdi(nev, telefon);
			gazdi* utolso = adatok;
			while (utolso->kov != NULL) {
				utolso = utolso->kov;
			}
			LL_Gazdi(utolso, uj);
			Mentes(adatok);
			break;
		case '0':
			break;
		default:
			printf("Hiba! A menupont szamat valaszd!");
		}

	}
}
void ujAdat(gazdi* adatok) {
	int kiv = -1;
	while (kiv != '0') {
		clear();
		printf("/// UJ ADAT FELVETELE ///\n");
		printf("    [1] Uj gazdi\n");
		printf("    [2] Uj allat\n");
		printf("    [3] Uj kezeles\n");
		printf("    [0] Kilepes\n");
		printf("    Valasztas: ");
		do {
			kiv = getchar();

		} while (kiv == '\n');
		switch (kiv) {
		case '1':
			gazdi_hozzaad(adatok);
			break;
		case '2':

			break;
		case '3':

			break;
		case '0':
			break;
		default:
			printf("Hiba! A menupont szamat valaszd!");
		}
	}
}


void adatkezeles(gazdi* adatok) {
	int kiv = -1;
	while (kiv != '0') {
		clear();
		printf("/// ADATKEZELES MENU ///\n");
		printf("    [1] Uj adat felvetele\n");
		printf("    [2] Meglevo adat modositasa\n");
		printf("    [3] Adattorles\n");
		printf("    [0] Kilepes\n");
		printf("    Valasztas: ");
		do {
			kiv = getchar();

		} while (kiv == '\n');
		switch (kiv) {
		case '1':
			ujAdat(adatok);
			break;
		case '2':

			break;
		case '3':

			break;
		case '0':
			break;
		default:
			printf("Hiba! A menupont szamat valaszd!");
		}
	}
}