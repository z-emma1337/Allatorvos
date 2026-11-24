#include "debugmalloc.h"
#include "adatbazis.h"
#include "hozzaad.h"
#include "adatkezeles.h"
#include "menu.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>


void gazdi_hozzaad(gazdi* adatok) {
	int kiv = -1;
	while (kiv != '0') {
		nevTipus nev;
		clear();
		printf("/// UJ GAZDI HOZZAADASA [0] Kilepes ///\n");
		printf("Vezeteknev: ");
		scanf("%s", nev.vezetek);
		if (strcmp(nev.vezetek, "0") == 0) {
			break;
		}
		getchar();

		clear();
		printf("/// UJ GAZDI HOZZAADASA [0] Kilepes ///\n");
		printf("Vezeteknev: %s\n", nev.vezetek);
		printf("Keresztnev: ");
		scanf("%s", nev.kereszt);
		if (strcmp(nev.kereszt, "0") == 0) {
			break;
		}
		getchar();

		clear();
		printf("/// UJ GAZDI HOZZAADASA [0] Kilepes ///\n");
		printf("Nev: %s %s\n", nev.vezetek, nev.kereszt);
		printf("Telefonszam: ");
		char telefon[20];
		scanf("%s", telefon);
		if (strcmp(telefon, "0") == 0) {
			break;
		}
		getchar();


		clear();
		printf("/// UJ GAZDI HOZZAADASA [0] Kilepes ///\n");
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
		printf("/// UJ ALLAT HOZZAADASA [0] Kilepes///\n");
		char telefon[20];
		printf("Gazdi telefonszama: ");
		scanf("%s", telefon);
		if (strcmp(telefon, "0") == 0) {
			break;
		}
		getchar();
		gazdi* mostGazdi = NULL;
		gazdi* keres = adatok;
		while (keres != NULL && mostGazdi == NULL) {
			if (strcmp(keres->telefon, telefon) == 0) {
				mostGazdi = keres;
			}
			keres = keres->kov;
		}
		if (mostGazdi == NULL) {
			clear();
			printf("Nincs ilyen gazdi!\n");
			printf("[ENTER] Visszateres");
			getchar();


		}
		else {


			clear();
			printf("/// UJ ALLAT HOZZAADASA [0] Kilepes///\n");
			printf("Gazdi neve: %s %s\n", mostGazdi->nev.vezetek, mostGazdi->nev.kereszt);
			printf("Telefonszam: %s\n", mostGazdi->telefon);
			printf("------------------------\n");
			printf("Uj allat neve: ");
			char allatNev[20];
			scanf("%s", allatNev);
			if (strcmp(allatNev, "0") == 0) {
				break;
			}
			getchar();

			clear();
			printf("/// UJ ALLAT HOZZAADASA [0] Kilepes///\n");
			printf("Gazdi neve: %s %s\n", mostGazdi->nev.vezetek, mostGazdi->nev.kereszt);
			printf("Telefonszam: %s\n", mostGazdi->telefon);
			printf("------------------------\n");
			printf("Uj allat neve: %s\n", allatNev);
			printf("Uj allat faja: ");
			char faj[50];
			scanf("%s", faj);
			if (strcmp(faj, "0") == 0) {
				break;
			}
			getchar();

			clear();
			printf("/// UJ ALLAT HOZZAADASA [0] Kilepes///\n");
			printf("Gazdi neve: %s %s\n", mostGazdi->nev.vezetek, mostGazdi->nev.kereszt);
			printf("Telefonszam: %s\n", mostGazdi->telefon);
			printf("------------------------\n");
			printf("Uj allat neve: %s\n", allatNev);
			printf("Uj allat faja: %s\n", faj);
			printf("Uj allat oltasanak datuma [YYYY.MM.DD]: ");
			char datum[20];
			scanf("%s", datum);
			if (strcmp(datum, "0") == 0) {
				break;
			}

			clear();
			printf("/// UJ ALLAT HOZZAADASA [0] Kilepes///\n");
			printf("Gazdi neve: %s %s\n", mostGazdi->nev.vezetek, mostGazdi->nev.kereszt);
			printf("Telefonszam: %s\n", mostGazdi->telefon);
			printf("------------------------\n");
			printf("Uj allat neve: %s\n", allatNev);
			printf("Uj allat faja: %s\n", faj);
			printf("Uj allat oltasanak datuma: %s\n", datum);
			printf("[0] Kilepes [1] Mentes\n");
			printf("Valasztas:");
			do {
				kiv = getchar();

			} while (kiv == '\n');
			switch (kiv) {
			case '1':
				datumTipus oltas = str_to_datum(datum);
				allat* uj = ujAllat(allatNev, faj, oltas);

				allat* utolso = mostGazdi->allatok;

				if (utolso == NULL) {
					mostGazdi->allatok = uj;
				}
				else {
					while (utolso->kov != NULL) {
						utolso = utolso->kov;
					}
					LL_Allat(utolso, uj);
				}

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

void kezeles_hozzaad(gazdi* adatok) {
	int kiv = -1;
	while (kiv != '0') {
		clear();
		printf("/// UJ KEZELES HOZZAADASA [0] Kilepes ///\n");
		char telefon[20];
		printf("Gazdi telefonszama: ");
		scanf("%s", telefon);
		if (strcmp(telefon, "0") == 0) {
			break;
		}
		getchar();
		gazdi* mostGazdi = NULL;
		gazdi* keres_g = adatok;
		while (keres_g != NULL && mostGazdi == NULL) {
			if (strcmp(keres_g->telefon, telefon) == 0) {
				mostGazdi = keres_g;
			}
			keres_g = keres_g->kov;
		}
		if (mostGazdi == NULL) {
			clear();
			printf("Nincs ilyen gazdi!\n");
			printf("[ENTER] Visszateres");
			getchar();


		}
		else {


			clear();
			printf("/// UJ KEZELES HOZZAADASA [0] Kilepes ///\n");
			printf("Gazdi neve: %s %s\n", mostGazdi->nev.vezetek, mostGazdi->nev.kereszt);
			printf("Telefonszam: %s\n", mostGazdi->telefon);
			printf("------------------------\n");
			printf("Allat neve: ");
			char allatNev[20];
			scanf("%s", allatNev);
			if (strcmp(allatNev, "0") == 0) {
				break;
			}
			getchar();

			allat* mostAllat = NULL;
			allat* keres_a = mostGazdi->allatok;
			while (keres_a != NULL && mostAllat == NULL) {
				char* mostNev = kisbetus(keres_a->nev);
				char* k_allatNev = kisbetus(allatNev);
				if (strcmp(mostNev, k_allatNev) == 0) {
					mostAllat = keres_a;
				}
				keres_a = keres_a->kov;
				free(k_allatNev);
				free(mostNev);
			}

			if (mostAllat == NULL) {
				clear();
				printf("Nincs ilyen allat!\n");
				printf("[ENTER] Visszateres");
				getchar();
			}
			else {



				clear();
				printf("/// UJ KEZELES HOZZAADASA [0] Kilepes ///\n");
				printf("Gazdi neve: %s %s\n", mostGazdi->nev.vezetek, mostGazdi->nev.kereszt);
				printf("Telefonszam: %s\n", mostGazdi->telefon);
				printf("Allat neve: %s\n", mostAllat->nev);
				printf("Allat faja: %s\n",mostAllat->faj);
				printf("------------------------\n");
				printf("Kezeles leirasa: ");
				char kez[50];
				scanf("%[^\n]", kez);
				if (strcmp(kez, "0") == 0) {
					break;
				}
				getchar();

				clear();
				printf("/// UJ KEZELES HOZZAADASA [0] Kilepes ///\n");
				printf("Gazdi neve: %s %s\n", mostGazdi->nev.vezetek, mostGazdi->nev.kereszt);
				printf("Telefonszam: %s\n", mostGazdi->telefon);
				printf("Allat neve: %s\n", mostAllat->nev);
				printf("Allat faja: %s\n", mostAllat->faj);
				printf("------------------------\n");
				printf("Kezeles leirasa: %s\n",kez);
				printf("Datum [YYYY.MM.DD]: ");
				char datum[11];
				scanf("%s", datum);
				if (strcmp(datum, "0") == 0) {
					break;
				}
				getchar();

				clear();
				printf("/// UJ KEZELES HOZZAADASA [0] Kilepes ///\n");
				printf("Telefonszam: %s\n", mostGazdi->telefon);
				printf("Allat neve: %s\n", mostAllat->nev);
				printf("Allat faja: %s\n", mostAllat->faj);
				printf("------------------------\n");
				printf("Kezeles leirasa: %s\n", kez);
				printf("Datum: %s\n",datum);
				printf("[0] Kilepes [1] Mentes\n");
				printf("Valasztas:");
				do {
					kiv = getchar();

				} while (kiv == '\n');
				switch (kiv) {
				case '1':
					datumTipus kezDatum = str_to_datum(datum);
					kezeles* uj = ujKez(kezDatum,kez);

					kezeles* utolso = mostAllat->kezelesek;

					if (utolso == NULL) {
						mostAllat->kezelesek = uj;
					}
					else {
						while (utolso->kov != NULL) {
							utolso = utolso->kov;
						}
						LL_Kez(utolso, uj);
					}

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
}
