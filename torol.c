#include "debugmalloc.h"
#include "adatbazis.h"
#include "torol.h"
#include "adatkezeles.h"
#include "menu.h"
#include <stdio.h>
#include <ctype.h>
#include <string.h>

void gazdi_torol(gazdi* adatok) {
	int sorSzam = -1;
	gazdi* torlendo = NULL;
	while (sorSzam == -1) {
		printf("/// GAZDI TORLESE [0] Kilepes [-] Nem valtozik///\n");
		printf("Gazdik:\n");
		gazdi* felsorol = adatok;

		for (int i = 1; felsorol != NULL; i++) {
			printf("[%d] | %s %s | %s\n", i, felsorol->nev.vezetek, felsorol->nev.kereszt, felsorol->telefon);
			felsorol = felsorol->kov;
		}
		printf("Torles: ");
		char be[10];
		scanf("%s", be);
		gazdi* keres_g = adatok;
		for (int i = 1; keres_g != NULL && torlendo == NULL; i++) {
			char szam[10];
			sprintf(szam, "%d", i);

			if (strcmp(szam, be) == 0) {
				sorSzam = i;
				torlendo = keres_g;
			}

			keres_g = keres_g->kov;
		}
		if (strcmp(be, "0") == 0) {
			return;
		}
		if (sorSzam == -1) {
			printf("Hiba! A gazdi sorszamat valaszd! [ENTER] Visszateres");
			getchar();
			getchar();
		}
	}
	
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
		adatok = torlendo->kov;
	}
	torlendo->kov = NULL;
	freeG(torlendo);


}
void allat_torol(gazdi* adatok) {

}
void kezeles_torol(gazdi* adatok) {

}
