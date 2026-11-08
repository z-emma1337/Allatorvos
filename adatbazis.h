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
	strut allat* kov;
}allat;

typedef struct gazdi {
	nevTipus nev;
	char telefon[12];
	Allat* allatok;
	struct gazdi* kov;
}gazdi;