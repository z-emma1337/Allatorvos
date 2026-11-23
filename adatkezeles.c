#include "debugmalloc.h"
#include "adatbazis.h"
#include "adatkezeles.h"
#include "menu.h"
#include <stdio.h>
#include <ctype.h>
#include <string.h>

void Mentes(gazdi* adatok) {
	FILE* f = fopen("adatok.txt", "w");

	if (f == NULL) {
		printf("Nem sikerult megnyitni a fajlt!");
		return;
	}

	while (adatok != NULL) {
		fprintf(f, "G;%s %s;%s\n", adatok->nev.vezetek, adatok->nev.kereszt, adatok->telefon);

		allat* a = adatok->allatok;
		while (a != NULL) {
			fprintf(f, "A;%s;%s;%04d.%02d.%02d\n", a->nev, a->faj, a->oltas.ev, a->oltas.honap, a->oltas.nap);

			kezeles* k = a->kezelesek;
			while (k != NULL) {
				fprintf(f, "K;%04d.%02d.%02d;%s\n", k->datum.ev, k->datum.honap, k->datum.nap, k->leiras);
				k = k->kov;
			}

			a = a->kov;
		}

		adatok = adatok->kov;
	}

	fclose(f);
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
			allat_hozzaad(adatok);
			break;
		case '3':
			kezeles_hozzaad(adatok);
			break;
		case '0':
			break;
		default:
			printf("Hiba! A menupont szamat valaszd!");
		}
	}
}

void modAdat(gazdi* adatok) {
	int kiv = -1;
	while (kiv != '0') {
		clear();
		printf("/// ADAT MODOSITAS ///\n");
		printf("    [1] Gazdi modositasa\n");
		printf("    [2] Allat modositasa\n");
		printf("    [3] Kezeles modositasa\n");
		printf("    [0] Kilepes\n");
		printf("    Valasztas: ");
		do {
			kiv = getchar();

		} while (kiv == '\n');
		switch (kiv) {
		case '1':
			gazdi_mod(adatok);
			break;
		case '2':
			allat_mod(adatok);
			break;
		case '3':
			kezeles_mod(adatok);
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
			modAdat(adatok);
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