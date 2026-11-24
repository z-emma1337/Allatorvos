#include "debugmalloc.h"
#include "adatbazis.h"
#include "menu.h"
#include <stdio.h>
#include <time.h>
#include <stdlib.h>


int egyEve(datumTipus a, datumTipus b) {
	if (a.ev > b.ev - 1) return 0;
	if (a.ev == b.ev - 1) {
		if (a.honap > b.honap) return 0;
		if (a.honap == b.honap && a.nap >= b.nap) return 0;
	}
	return 1;
}

void lista(gazdi* adatok) {
	clear();
	FILE* f = fopen("lista.txt", "w");

	time_t ido = time(NULL);
	struct tm* datum = localtime(&ido);
	datumTipus maiDatum = (datumTipus){ datum->tm_year + 1900, datum->tm_mon + 1, datum->tm_mday };

	printf("/// a lista.txt elkeszult /// [ENTER] Visszateres\n");
	printf("Allatok melyek tobb mint egy eve nem kaptak veszettseg elleni oltast:\n");

	gazdi* mostGazdi = adatok;
	while (mostGazdi != NULL) {
		allat* mostAllat = mostGazdi->allatok;
		while (mostAllat != NULL) {
			datumTipus mostOltas = mostAllat->oltas;
			if (egyEve(mostOltas, maiDatum)) {
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

	printf("[ENTER] Visszateres");
	fclose(f);
	getchar();
	getchar();
}