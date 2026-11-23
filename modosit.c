#include "debugmalloc.h"
#include "adatbazis.h"
#include "modosit.h"
#include "adatkezeles.h"
#include "menu.h"
#include <stdio.h>
#include <ctype.h>
#include <string.h>

void gazdi_mod(gazdi* adatok) {
	int kiv = -1;
	while (kiv != '0') {
		clear();
		printf("/// GAZDI MODOSITASA [0] Kilepes///\n");
		char telefon[12];
		printf("Gazdi telefonszama: ");
		scanf("%s", telefon);
		if (strcmp(telefon, "0") == 0) {
			break;
		}
		getchar();
		gazdi* mostGazdi = NULL;
		gazdi* keres = adatok;
		while (keres != NULL && mostGazdi == NULL) {
			if (strcmp(keres->telefon, telefon) == 0) {
				mostGazdi = keres;
			}
			keres = keres->kov;
		}
		if (mostGazdi == NULL) {
			clear();
			printf("Nincs ilyen gazdi!\n");
			printf("[ENTER] Visszateres");
			getchar();


		}
		else {


			clear();
			printf("/// GAZDI MODOSITASA [0] Kilepes///\n");
			printf("Gazdi neve: %s %s\n", mostGazdi->nev.vezetek, mostGazdi->nev.kereszt);
			printf("Telefonszam: %s\n", mostGazdi->telefon);
			printf("------------------------\n");
			printf("Vezeteknev modositasa: ");
			nevTipus nev;
			scanf("%s", nev.vezetek);
			if (strcmp(nev.vezetek, "0") == 0) {
				break;
			}
			if (strcmp(nev.vezetek, "-") == 0) {
				strcpy(nev.vezetek, mostGazdi->nev.vezetek);
			}
			getchar();

			clear();
			printf("/// GAZDI MODOSITASA [0] Kilepes///\n");
			printf("Gazdi neve: %s %s\n", mostGazdi->nev.vezetek, mostGazdi->nev.kereszt);
			printf("Telefonszam: %s\n", mostGazdi->telefon);
			printf("------------------------\n");
			printf("Vezeteknev modositasa: %s\n", nev.vezetek);
			printf("Keresztnev modositasa: ");
			scanf("%s", nev.kereszt);
			if (strcmp(nev.kereszt, "0") == 0) {
				break;
			}
			if (strcmp(nev.kereszt, "-") == 0) {
				strcpy(nev.kereszt, mostGazdi->nev.kereszt);
			}
			getchar();

			clear();
			printf("/// GAZDI MODOSITASA [0] Kilepes///\n");
			printf("Gazdi neve: %s %s\n", mostGazdi->nev.vezetek, mostGazdi->nev.kereszt);
			printf("Telefonszam: %s\n", mostGazdi->telefon);
			printf("------------------------\n");
			printf("Vezeteknev modositasa: %s\n", nev.vezetek);
			printf("Keresztnev modositasa: %s\n",nev.kereszt);
			printf("Telefonszam modositasa: ");
			char ujtelefon[12];
			scanf("%s", ujtelefon);
			if (strcmp(ujtelefon, "0") == 0) {
				break;
			}
			if (strcmp(ujtelefon, "-") == 0) {
				strcpy(ujtelefon, mostGazdi->telefon);
			}
			getchar();

			clear();
			printf("/// GAZDI MODOSITASA [0] Kilepes///\n");
			printf("Gazdi neve: %s %s\n", mostGazdi->nev.vezetek, mostGazdi->nev.kereszt);
			printf("Telefonszam: %s\n", mostGazdi->telefon);
			printf("------------------------\n");
			printf("Vezeteknev modositasa: %s\n", nev.vezetek);
			printf("Keresztnev modositasa: %s\n", nev.kereszt);
			printf("Telefonszam modositasa: %s\n",ujtelefon);

			printf("[0] Kilepes [1] Mentes\n");
			printf("Valasztas:");
			do {
				kiv = getchar();

			} while (kiv == '\n');
			switch (kiv) {
			case '1':
				mostGazdi->nev = nev;
				strcpy(mostGazdi->telefon, ujtelefon);

				Mentes(adatok);
				break;

			case '0':
				break;
			default:
				printf("Hiba! A menupont szamat valaszd!");
			}

		}
	}
}
void allat_mod(gazdi* adatok) {

}
void kezeles_mod(gazdi* adatok){
}