#include "debugmalloc.h"
#include "adatbazis.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

gazdi* ujGazdi(nevTipus nev, char telefon[]) { //pointer "láncszem"
	gazdi* uj = (gazdi*)malloc(sizeof(gazdi));
	if (uj == NULL) {
		return NULL;
	}
	uj->nev = nev; //->  "." helyett, mert pointer
	for (int i = 0; i < 11; i++) {
		uj->telefon[i] = telefon[i];
	}
	uj->allatok = NULL;
	uj->kov = NULL;
	return uj;
}


allat* ujAllat(char nev[], char faj[], datumTipus oltas) {
	allat* uj = (allat*)malloc(sizeof(allat));
	strcpy(uj->nev, nev);
	strcpy(uj->faj, faj);
	uj->oltas = oltas;
	uj->kezelesek = NULL;
	uj->kov = NULL;
	return uj;
}

kezeles* ujKez(datumTipus datum, char leiras[]) {
	kezeles* uj = (kezeles*)malloc(sizeof(kezeles));
	if (uj == NULL) {
		return NULL;
	}
	uj->datum = datum;
	strcpy(uj->leiras, leiras);
	uj->kov = NULL;
	return uj;
}



datumTipus str_to_datum(char str[]) {
	datumTipus datum;
	sscanf(str, "%d.%d.%d", &datum.ev, &datum.honap, &datum.nap);
	return datum;
}

nevTipus str_to_nev(char str[]) {
	nevTipus nev;
	sscanf(str, "%s %s", nev.vezetek, nev.kereszt);
	return nev;
}

void LL_Gazdi(gazdi* elozo, gazdi* most) {
	elozo->kov = most;
}

void LL_Allat(allat* elozo, allat* most) {
	elozo->kov = most;
}

void LL_Kez(kezeles* elozo, kezeles* most) {
	elozo->kov = most;
}

void freeK(kezeles* mostK) {
	while (mostK != NULL) {
		kezeles* kov = mostK->kov;
		free(mostK);
		mostK = kov;
	}
}

void freeA(allat* mostA) {
	while (mostA != NULL) {
		allat* kov = mostA->kov;
		freeK(mostA->kezelesek);
		free(mostA);
		mostA = kov;
	}
}

void freeG(gazdi* mostG) {
	while (mostG != NULL) {
		gazdi* kov = mostG->kov;
		freeA(mostG->allatok);
		free(mostG);
		mostG = kov;
	}
}

gazdi* fajlBe(char fajlnev[]) {
	FILE* fajl = fopen(fajlnev, "r");
	char adatsor[256];
	char adatok[5][50];
	if (fajl == NULL) {
		printf("Fajlbeolvasas sikertelen.");
		return NULL;
	}

	gazdi* elso = NULL;
	gazdi* mostG = NULL;
	allat* mostA = NULL;
	kezeles* mostK = NULL;
	while (fgets(adatsor, 256, fajl)) {
		int sor = 0;
		int oszlop = 0;
		for (int i = 0; adatsor[i] != '\0'; i++) {
			if (adatsor[i] != ';' && adatsor[i] != '\n') {
				adatok[sor][oszlop] = adatsor[i];
				oszlop++;
			}
			else {
				adatok[sor][oszlop] = '\0';
				sor++;
				oszlop = 0;
			}
		}
		adatok[sor][oszlop] = '\0';

		if (adatok[0][0] == 'G') {//gazdi
			gazdi* uj = ujGazdi(str_to_nev(adatok[1]), adatok[2]);
			if (elso == NULL) {
				elso = uj;
			}
			else {
				LL_Gazdi(mostG, uj);
			}
			mostG = uj;
			mostA = NULL;
		}
		else if (adatok[0][0] == 'A') {//állat
			allat* uj = ujAllat(adatok[1], adatok[2], str_to_datum(adatok[3]));
			if (mostG->allatok == NULL) {
				mostG->allatok = uj;
			}
			else {
				LL_Allat(mostA, uj);
			}
			mostA = uj;
			mostK = NULL;
		}
		else if (adatok[0][0] == 'K') {//kezelés
			kezeles* uj = ujKez(str_to_datum(adatok[1]), adatok[2]);
			if (mostA->kezelesek == NULL) {
				mostA->kezelesek = uj;
			}
			else {
				LL_Kez(mostK, uj);
			}
			mostK = uj;
		}
	}

	fclose(fajl);
	return elso;
}