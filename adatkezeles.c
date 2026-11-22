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
		fprintf(fajl, "G;%s %s;%s\n", adatok->nev.vezetek, adatok->nev.kereszt, adatok->telefon);

		allat* a = adatok->allatok;
		while (a != NULL) {
			fprintf(f, "A;%s;%s;%04d.%02d.%02d\n", ev, a->faj, a->oltas.ev, a->oltas.honap, a->oltas.nap);

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

void allat_hozzaad(gazdi* adatok) {
	int kiv = -1;
	while (kiv != '0') {
		clear();
		printf("/// UJ ALLAT HOZZAADASA ///\n");
		char telefon[11];
		printf("Gazdi telefonszama: ");
		scanf("%s", telefon);
		getchar();
		gazdi mostGazdi = NULL;
		while (adatok != NULL && mostGazdi == NULL) {
			if (strcmp(adatok->telefon, telefon) == 0) {
				mostGazdi.nev = adatok->nev;
				mostGazdi.telefon = adatok->telefon;
			}
			adatok = adatok->kov;
		}
		if (mostGazdi == NULL) {
			clear();
			printf("Nincs ilyen gazdi!\n");	
			printf("[ENTER] Visszateres");
			getchar();
			getchar();

		}
		else {


			clear();
			printf("/// UJ ALLAT HOZZAADASA ///\n");
			printf("Gazdi neve: %s %s\n", mostGazdi.nev.vezetek, mostGazdi.nev.kereszt);
			printf("Telefonszam: %s\n",mostGazdi.telefon);
			printf("------------------------\n");
			printf("Uj allat neve: ");
			char allat[50];
			scanf("%s", allat);
			getchar();

			clear();
			printf("/// UJ ALLAT HOZZAADASA ///\n");
			printf("Gazdi neve: %s %s\n", mostGazdi.nev.vezetek, mostGazdi.nev.kereszt);
			printf("Telefonszam: %s"\n, mostGazdi.telefon);
			printf("------------------------\n");
			printf("Uj allat neve: %s\n",allat);
			printf("Uj allat faja: ");
			char faj[50];
			scanf("%s", faj);
			getchar();

			clear();
			printf("/// UJ ALLAT HOZZAADASA ///\n");
			printf("Gazdi neve: %s %s\n", mostGazdi.nev.vezetek, mostGazdi.nev.kereszt);
			printf("Telefonszam: %s"\n, mostGazdi.telefon);
			printf("------------------------\n");
			printf("Uj allat neve: %s\n", allat);
			printf("Uj allat faja: %s\n",faj);


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