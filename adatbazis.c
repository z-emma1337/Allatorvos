#include "debugmalloc.h"
#include "adatbazis.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

gazdi* ujGazdi(nevTipus nev, int telefon[]){ //pointer "láncszem"
	gazdi* uj = (gazdi*)malloc(sizeof(gazdi)); 
	if (uj == NULL) {
		return NULL;
	}
	uj->nev = nev; //->  "." helyett, mert pointer
	for (int i = 0; i < 11;i++) {
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
	return uj;
}

datumTipus str_to_datum(char str[]) {
	datumTipus datum;
	sscanf(str,"%d.%d.%d", &datum.ev, &datum.honap, &datum.nap);
	return datum;
}

nevTipus str_to_nev(char str[]) {
	nevTipus nev;
	sscanf(str, "%s %s", nev.vezetek, nev.kereszt);
	return nev;
}

void fajlBe(char fajlnev[]) {
	fajl = fopen(fajlnev, "r");
	char sor[256];
	char adatok[5][50];
	if (fajl == NULL) {
		printf("Fajlbeolvasas sikertelen.");
		return;
	}
	while (fgets(sor, 256, fajl)) {
		for (int i = 0; sor[i] != '\0';i++) {

		}
	}

	fclose(fajl);
}