#include "debugmalloc.h"
#include "adatbazis.h"
#include "menu.h"
#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <time.h>

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
	time_t ido = time(NULL);
	struct tm* datum = localtime(&ido);
	datumTipus maiDatum = (datumTipus){ datum->tm_year + 1900,datum->tm_mon + 1,datum->tm_mday };
	printf("/// a lista.txt elkeszult /// [ENTER] Visszateres\n");
	printf("Allatok melyek tobb mint egy eve nem kaptak veszettseg elleni oltast:\n");
	gazdi* mostGazdi = adatok;
	while (mostGazdi != NULL) {
		allat* mostAllat = mostGazdi->allatok;
		while (mostAllat != NULL) {
			kezeles* mostKez = mostAllat->kezelesek;
			while (mostKez != NULL) {
				char* mostLeiras = kisbetus(mostKez->leiras);
				datumTipus mostDatum = mostKez->datum;
				if (strcmp(mostLeiras, "veszettseg elleni oltas")==0 && egyEve(mostDatum,maiDatum)) {
					printf("------------------------\n");
					printf("Gazdi: %s %s\n", mostGazdi->nev.vezetek, mostGazdi->nev.kereszt);
					printf("Datum: %04d.%02d.%02d\n", mostDatum.ev, mostDatum.honap, mostDatum.nap);
					printf("Allat:%s", mostAllat->nev);

					printf("\n");
				}
				mostKez = mostKez->kov;
				free(mostLeiras);

			}
			mostAllat = mostAllat->kov;

		}
		mostGazdi = mostGazdi->kov;
	}
	printf("[ENTER] Visszateres");
	getchar();
	getchar();
}