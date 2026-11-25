#include "debugmalloc.h"
#include "adatbazis.h"
#include "torol.h"
#include "adatkezeles.h"
#include "menu.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

//gazdi_torol: megkapja a fej gazdit és visszatér a módosított fejgazdival, elvégzi a gazdi törlését
gazdi* gazdi_torol(gazdi* adatok) {
	//gazdik sorszámos felsorolása
	clear();
	int sorSzam = -1;
	gazdi* torlendo = NULL;
	while (sorSzam == -1) {
		printf("/// GAZDI TORLESE [0] Kilepes///\n");
		printf("Gazdik:\n");
		gazdi* felsorol = adatok;

		for (int i = 1; felsorol != NULL; i++) {
			printf("[%d] | %s %s | %s\n", i, felsorol->nev.vezetek, felsorol->nev.kereszt, felsorol->telefon);
			felsorol = felsorol->kov;
		}
		//sorszám bekérése
		printf("Torles: ");
		char be[10];
		scanf("%s", be);

		int valasztas = -1;
		sscanf(be, "%d", &valasztas);

		if (valasztas == 0) {
			return adatok;
		}
		gazdi* keres_g = adatok;
		for (int i = 1; keres_g != NULL && torlendo == NULL; i++) {
			if (valasztas == i) {
				sorSzam = i;
				torlendo = keres_g;
			}
			keres_g = keres_g->kov;
		}
		if (strcmp(be, "0") == 0) {
			return adatok;
		}
		if (sorSzam == -1) {
			printf("Hiba! A gazdi sorszamat valaszd! [ENTER] Visszateres");
			getchar();
			getchar();
		}
	}
	//listaelem törlése
	gazdi* elozo = NULL;
	gazdi* keres = adatok;

	while (keres != torlendo) {
		elozo = keres;
		keres = keres->kov;
	}
	if (elozo != NULL) {
		elozo->kov = torlendo->kov;

	}
	else {
		adatok = adatok->kov;
	}
	torlendo->kov = NULL;
	freeG(torlendo);
	Mentes(adatok);
	return adatok;


}

//allat_torol: megkapja a fej gazdit és visszatér a módosított fejgazdival, elvégzi az állat törlését
gazdi* allat_torol(gazdi* adatok) {

	int sorSzam = -1;
	allat* torlendo = NULL;
	gazdi* mostGazdi = NULL;

	while (sorSzam == -1) {
		//gazdi keresése telefonszám alapján
		clear();
		printf("/// ALLAT TORLESE [0] Kilepes ///\n");
		char telefon[12];
		printf("Gazdi telefonszama: ");
		scanf("%s", telefon);
		if (strcmp(telefon, "0") == 0) {
			return adatok;
		}
		getchar();

		mostGazdi = NULL;
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
		else if (mostGazdi->allatok == NULL) {
			clear();
			printf("Ennek a gazdinak nincs allata!\n");
			printf("[ENTER] Visszateres");
			getchar();
		}
		else {
			//állatok sorszámos felsorolása
			printf("Allatok:\n");
			allat* felsorol = mostGazdi->allatok;
			for (int i = 1; felsorol != NULL; i++) {
				printf("[%d] | %s | %s\n", i, felsorol->nev, felsorol->faj);
				felsorol = felsorol->kov;
			}
			//sorszám bekérése
			printf("Torles: ");
			char be[10];
			scanf("%s", be);
			int valasztas = -1;
			sscanf(be, "%d", &valasztas);

			if (valasztas == 0) {
				return adatok;
			}
			allat* keres_a = mostGazdi->allatok;
			for (int i = 1; keres_a != NULL && torlendo == NULL; i++) {
				if (valasztas == i) {
					sorSzam = i;
					torlendo = keres_a;
				}

				keres_a = keres_a->kov;
			}
			if (sorSzam == -1) {
				printf("Hiba! Az allat sorszamat valaszd! [ENTER] Visszateres");
				getchar();
				getchar();
			}
		}
	}
	//listaelem törlése

	allat* elozo = NULL;
	allat* keres = mostGazdi->allatok;

	while (keres != torlendo) {
		elozo = keres;
		keres = keres->kov;
	}
	if (elozo != NULL) {
		elozo->kov = torlendo->kov;
	}
	else {
		mostGazdi->allatok = torlendo->kov;
	}
	torlendo->kov = NULL;
	freeA(torlendo);
	Mentes(adatok);
	return adatok;
}

//kezeles_torol: megkapja a fej gazdit és visszatér a módosított fejgazdival, elvégzi a kezelés törlését

gazdi* kezeles_torol(gazdi* adatok) {
	gazdi* mostGazdi = NULL;
	allat* mostAllat = NULL;

	while (mostAllat == NULL) {
		//gazdi keresés telefonszám szerint
		clear();
		printf("/// KEZELES TORLESE [0] Kilepes ///\n");
		char telefon[12];
		printf("Gazdi telefonszama: ");
		scanf("%s", telefon);
		if (strcmp(telefon, "0") == 0) {
			return adatok;
		}
		getchar();

		mostGazdi = NULL;
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
		else if (mostGazdi->allatok == NULL) {
			clear();
			printf("Ennek a gazdinak nincs allata!\n");
			printf("[ENTER] Visszateres");
			getchar();
		}
		else {
			//állat keresés név szerint
			clear();
			printf("/// KEZELES TORLESE [0] Kilepes ///\n");
			printf("Gazdi neve: %s %s\n", mostGazdi->nev.vezetek, mostGazdi->nev.kereszt);
			printf("Telefonszam: %s\n", mostGazdi->telefon);
			printf("------------------------\n");
			char allatNev[20];
			printf("Allat neve: ");
			scanf("%s", allatNev);
			if (strcmp(allatNev, "0") == 0) {
				return adatok;
			}
			getchar();

			allat* keres_a = mostGazdi->allatok;
			while (keres_a != NULL && mostAllat == NULL) {
				char* mostNev = kisbetus(keres_a->nev);
				char* k_allatNev = kisbetus(allatNev);
				if (strcmp(mostNev,k_allatNev) == 0) {
					mostAllat = keres_a;
				}
				keres_a = keres_a->kov;
				free(mostNev);
				free(k_allatNev);
			}

			if (mostAllat == NULL) {
				clear();
				printf("Nincs ilyen allat!\n");
				printf("[ENTER] Visszateres");
				getchar();
			}
			else if (mostAllat->kezelesek == NULL) {
				clear();
				printf("Ez az allat meg nem volt kezelve!\n");
				printf("[ENTER] Visszateres");
				getchar();
				mostAllat = NULL;
			}
		}
	}

	int sorSzam = -1;
	kezeles* torlendo = NULL;
	while (sorSzam == -1) {
		//kezelések sorszámos felsorolása
		clear();
		printf("Kezelesek: [0] Kilepes\n");
		kezeles* felsorol = mostAllat->kezelesek;
		for (int i = 1; felsorol != NULL; i++) {
			datumTipus kezDatum = felsorol->datum;
			printf("[%d] | %04d.%02d.%02d | %s\n", i, kezDatum.ev, kezDatum.honap, kezDatum.nap, felsorol->leiras);
			felsorol = felsorol->kov;
		}
		//sorszám bekérése
		printf("Torles: ");
		char be[10];
		scanf("%s", be);
		int valasztas = -1;
		sscanf(be, "%d", &valasztas);

		if (valasztas == 0) {
			return adatok;
		}
		kezeles* keres_k = mostAllat->kezelesek;
		for (int i = 1; keres_k != NULL && torlendo == NULL; i++) {
			if (valasztas == i) {
				sorSzam = i;
				torlendo = keres_k;
			}
			keres_k = keres_k->kov;
		}
		if (sorSzam == -1) {
			printf("Hiba! A kezeles sorszamat valaszd! [ENTER] Visszateres");
			getchar();
			getchar();
		}
	}
	//listaelem törlése
	kezeles* elozo = NULL;
	kezeles* keres = mostAllat->kezelesek;

	while (keres != torlendo) {
		elozo = keres;
		keres = keres->kov;
	}
	if (elozo != NULL) {
		elozo->kov = torlendo->kov;
	}
	else {
		mostAllat->kezelesek = torlendo->kov;
	}

	torlendo->kov = NULL;
	freeK(torlendo);
	Mentes(adatok);
	return adatok;
}
