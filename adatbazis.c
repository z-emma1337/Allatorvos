#include "debugmalloc.h"
#include "adatbazis.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
/*
ujGazdi: paraméterei: névtípus, string telefonszám, visszaad egy gazdit.
Dinamikusan lefoglalja az új gazdi területét, majd a paraméterek segítségével létrehozza az új gazdit
A maradék paraméterek nullpointerek.
*/
gazdi* ujGazdi(nevTipus nev, char telefon[]) { //pointer "láncszem"
	gazdi* uj = (gazdi*)malloc(sizeof(gazdi));
	if (uj == NULL) {
		return NULL;
	}
	uj->nev = nev; //->  "." helyett, mert pointer
	strcpy(uj->telefon, telefon);
	uj->allatok = NULL;
	uj->kov = NULL;
	return uj;
}

/*
ujAllat: paraméterei: string név, faj és dátumtípus az oltásnak, visszaad egy állatot.
Dinamikusan lefoglalja az új állat területét, majd a paramétereknek megfelelően létrehozza az új állatot.
a maradék paraméterek nullpointerek
*/
allat* ujAllat(char nev[], char faj[], datumTipus oltas) {
	allat* uj = (allat*)malloc(sizeof(allat));
	if (uj == NULL) {
		return NULL;
	}
	strcpy(uj->nev, nev);
	strcpy(uj->faj, faj);
	uj->oltas = oltas;
	uj->kezelesek = NULL;
	uj->kov = NULL;
	return uj;
}
/*
ujKez: paraméterei: dátumtípus, string leírás, vissza ad egy kezelést.
Dinamikusan lefoglalja az új kezelés területét, a paraméterekkel létrehozza az új kezelést és a következőnek a pointerét nullon hagyja.
*/

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

//szövegből dátumtípust csinál
datumTipus str_to_datum(char str[]) {
	datumTipus datum;
	sscanf(str, "%d.%d.%d", &datum.ev, &datum.honap, &datum.nap);
	return datum;
}

//szövegből névtípust csinál
nevTipus str_to_nev(char str[]) {
	nevTipus nev;
	sscanf(str, "%s %s", nev.vezetek, nev.kereszt);
	return nev;
}

//összekötő függvények (láncolt lista)
void LL_Gazdi(gazdi* elozo, gazdi* most) {
	elozo->kov = most;
}

void LL_Allat(allat* elozo, allat* most) {
	elozo->kov = most;
}

void LL_Kez(kezeles* elozo, kezeles* most) {
	elozo->kov = most;
}

//felszabadító függvények, a freeG meghívja az összeset
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

/*
 fajlBe:parametere a fajlnev, visszaadja a head gazdi elemet.
 Beolvassa a pontosvesszovel tagolt szovegfajlt, es felepiti a 3 szintu lancolt listat.
 */
gazdi* fajlBe(char fajlnev[]) {
	//fajl megnyitasa olvasasra es nullcheck
	FILE* fajl = fopen(fajlnev, "r");
	if (fajl == NULL) {
		printf("Fajlbeolvasas sikertelen.");
		return NULL;
	}
	char adatsor[256];
	char adatok[5][50];


	// segedmutatok:
	// elso = teljes lista feje + mostani elemek
	gazdi* elso = NULL;
	gazdi* mostG = NULL;
	allat* mostA = NULL;
	kezeles* mostK = NULL;

	//soronkenti beolvasas (fgets) es darabolas az adatok[sor][oszlop] matrixba ';' menten
	while (fgets(adatsor, 256, fajl)) {
		int sor = 0;
		int oszlop = 0;
		for (int i = 0; adatsor[i] != '\0'; i++) {
			// Elvalaszto vagy sorveg eseten lezaras es uj sorba lepunk
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

		// sor tipusanak eldontese es osszekotes:
		//G
		if (adatok[0][0] == 'G') {
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
		//A
		else if (adatok[0][0] == 'A') {
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
		//K
		else if (adatok[0][0] == 'K') {
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
