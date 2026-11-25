#include "debugmalloc.h"
#include "adatbazis.h"
#include "menu.h"
#include "adatkezeles.h"
#include "hozzaad.h"
#include "modosit.h"
#include "torol.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>


/*
* Mentés: megkapja a fej gazdit és frissíti az adatok.txt-t visszatérési érték nélkül
* Megnyitja olvasásra a fájlt, nullcheck majd végig megy a láncolt listán miközben beleírja a benne lévő adatsorokat a fájlba
*/
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

/*
* ujAdat: megkapja a fej gazdit és visszatérési érték nélkül felépíti az új adat felvevő menüt
* 3 menüpontot biztosít új G A K felvételének, switchel választ, meghívja a megfelelő függvényeket
*/

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
/*
* modAdat: megkapja a fej gazdit és visszatérési érték nélkül felépíti az adatmodosito menüt
* 3 menüpontot biztosít a G A K modosításának, switchel választ, meghívja a megfelelő függvényeket
*/
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
/*
* torolAdat: megkapja a fej gazdit és visszaadja a módosított fej gazdit, felépíti az adattörlő menüt
* 3 menüpontot biztosít a G A K törlésének, switchel választ, meghívja a megfelelő függvényeket
*/
gazdi* torolAdat(gazdi* adatok) {
	int kiv = -1;
	while (kiv != '0') {
		clear();
		printf("/// ADAT TORLES ///\n");
		printf("    [1] Gazdi torlese\n");
		printf("    [2] Allat torlese\n");
		printf("    [3] Kezeles torlese\n");
		printf("    [0] Kilepes\n");
		printf("    Valasztas: ");
		do {
			kiv = getchar();

		} while (kiv == '\n');
		switch (kiv) {
		case '1':
			adatok = gazdi_torol(adatok);
			break;
		case '2':
			adatok = allat_torol(adatok);
			break;
		case '3':
			adatok = kezeles_torol(adatok);
			break;
		case '0':
			break;
		default:
			printf("Hiba! A menupont szamat valaszd!");
		}
	}
	return adatok;
}

/*
* adatkezeles: megkapja a fej gazdit és vissza adja a módosított fej gazdit
* kirajzol egy menüt, hogy milyen módon akarjuk az adatbázist módosítani
* a fenti függvények meghívásával felépíti a switches menürendszert
*/


gazdi* adatkezeles(gazdi* adatok) {
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
			adatok = torolAdat(adatok);
			break;
		case '0':
			break;
		default:
			printf("Hiba! A menupont szamat valaszd!");
		}
	}
	return adatok;
}