#pragma once
typedef struct datumTipus {
	int ev;
	int honap;
	int nap;
}datumTipus;

typedef struct nevTipus {
	char vezetek[20];
	char kereszt[20];
}nevTipus;

typedef struct kezeles {
	datumTipus datum;
	char leiras[50];
	struct kezeles* kov;
}kezeles;

typedef struct allat {
	char nev[20];
	char faj[20];
	datumTipus oltas;
	kezeles* kezelesek;
	struct allat* kov;
}allat;

typedef struct gazdi {
	nevTipus nev;
	char telefon[12];
	allat* allatok;
	struct gazdi* kov;
}gazdi;

datumTipus str_to_datum(char str[]);
nevTipus str_to_nev(char str[]);

gazdi* ujGazdi(nevTipus nev, char telefon[]);
allat* ujAllat(char nev[], char faj[], datumTipus oltas);
kezeles* ujKez(datumTipus datum, char leiras[]);

void LL_Gazdi(gazdi* elozo, gazdi* most);
void LL_Allat(allat* elozo, allat* most);
void LL_Kez(kezeles* elozo, kezeles* most);

gazdi* fajlBe(char fajlnev[]);

void freeK(kezeles* mostK);
void freeA(allat* mostA);
void freeG(gazdi* mostG);