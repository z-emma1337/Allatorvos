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
	FILE* f;
	f = fopen("lista.txt", "w");
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
			datumTipus legfrissebb;
			while (mostKez != NULL) {
				char* mostLeiras = kisbetus(mostKez->leiras);
				if (strstr(mostLeiras, "veszettseg ellen") != NULL) {
					legfrissebb = mostKez->datum;
				}
				mostKez = mostKez->kov;
				free(mostLeiras);

			}
			if (egyEve(legfrissebb,maiDatum)) {
				printf("------------------------\n");
				printf("Gazdi: %s %s\n", mostGazdi->nev.vezetek, mostGazdi->nev.kereszt);
				printf("Datum: %04d.%02d.%02d\n", legfrissebb.ev, legfrissebb.honap, legfrissebb.nap);
				printf("Allat: %s", mostAllat->nev);
				printf("\n");

				fprintf(f,"------------------------\n");
				fprintf(f,"Gazdi: %s %s\n", mostGazdi->nev.vezetek, mostGazdi->nev.kereszt);
				fprintf(f,"Datum: %04d.%02d.%02d\n", legfrissebb.ev, legfrissebb.honap, legfrissebb.nap);
				fprintf(f,"Allat: %s", mostAllat->nev);
				fprintf(f,"\n");
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