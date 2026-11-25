#include "debugmalloc.h"
#include "adatbazis.h"
#include "menu.h"
#include <stdio.h>
#include <time.h>
#include <stdlib.h>

/*
* egyEve: megkapja az oltás dátumát és eldönti, hogy több mint egy éve volt-e, egész számmal tér vissza 0/1
*/
int egyEve(datumTipus oltas) {
	time_t ido = time(NULL);
	struct tm* datum = localtime(&ido);
	datumTipus maiDatum = (datumTipus){ datum->tm_year + 1900, datum->tm_mon + 1, datum->tm_mday };

	//ha az oltás éve frissebb a tavalyinál még nem telt el 1 év
	if (oltas.ev > maiDatum.ev - 1) return 0;

	// ha tavaly volt az oltás, a hónap és a nap dönt
	if (oltas.ev == maiDatum.ev - 1) {
		if (oltas.honap > maiDatum.honap) return 0;
		if (oltas.honap == maiDatum.honap && oltas.nap >= maiDatum.nap) return 0;
	}

	return 1;
}

/*
- lista: megkapja a fejgazdit és visszatérési érték nélkül elkészít egy listát(cmd+txt) azokról az állatokról melyek több mint egy éve nem voltak veszettség ellen oltva
*/
void lista(gazdi* adatok) {
	clear();

	// Fájl megnyitása írásra és nullcheck
	FILE* f = fopen("lista.txt", "w");
	if (f == NULL) {
		printf("Nem sikerult megnyitni a lista.txt fajlt!\n");
		getchar();
		getchar();
		return;
	}

	printf("/// a lista.txt elkeszult /// [ENTER] Visszateres\n");
	printf("Allatok melyek tobb mint egy eve nem kaptak veszettseg elleni oltast:\n");

	// keresés
	gazdi* mostGazdi = adatok;
	while (mostGazdi != NULL) {
		allat* mostAllat = mostGazdi->allatok;
		while (mostAllat != NULL) {
			datumTipus mostOltas = mostAllat->oltas;
			// Ha több mint egy éve volt kiírás
			if (egyEve(mostOltas)) {
				printf("------------------------\n");
				printf("Gazdi: %s %s\n", mostGazdi->nev.vezetek, mostGazdi->nev.kereszt);
				printf("Datum: %04d.%02d.%02d\n", mostOltas.ev, mostOltas.honap, mostOltas.nap);
				printf("Allat: %s\n", mostAllat->nev);

				fprintf(f, "------------------------\n");
				fprintf(f, "Gazdi: %s %s\n", mostGazdi->nev.vezetek, mostGazdi->nev.kereszt);
				fprintf(f, "Datum: %04d.%02d.%02d\n", mostOltas.ev, mostOltas.honap, mostOltas.nap);
				fprintf(f, "Allat: %s\n", mostAllat->nev);
			}
			mostAllat = mostAllat->kov;
		}
		mostGazdi = mostGazdi->kov;
	}

	//lezárás
	printf("[ENTER] Visszateres");
	fclose(f);
	getchar();
	getchar();
}