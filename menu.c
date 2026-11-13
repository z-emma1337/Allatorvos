#include "debugmalloc.h"
#include "conio.h"
#include "menu.h"

menu* menu_init() {
	menu* M = malloc(6 * sizeof(menu));
	M[0] = (menu){ 0,-1,"Kereses" };
	M[1] = (menu){ 1,-1,"Lista" };
	M[2] = (menu){ 0,0,"Gazdi" };
	M[3] = (menu){ 1,0,"Allat" };
	M[4] = (menu){ 2,0,"Kezeles" };
	M[5] = (menu){ -1, -1, NULL };

	return M;
}

void MenuKiir(int szint, int kiv, menu* M) {
	char* cur = " >";
	system("cls");
	printf("/// MENU ///\n");
	for (int i = 0; M[i].Menupont != NULL && M[i].elozoIndex == szint - 1; i++) {
		if (kiv == M[i].index) {
			printf("   %s%s", cur, M[i].Menupont);
		}
		else {
			printf("   %s", M[i].Menupont);
		}
	}
}

void Inditas() {
	menu* M = menu_init();
	int b = 0;
	int szint = 0;
	int kiv = 0;
	MenuKiir(szint, kiv, M);

	while (b != 27) {
		b = _getch();
		if (b == 224) {
			b = _getch();
			if (b == 72) { //fel
				if (kiv > 0) kiv--;
			}
			else if (b == 80) {//le
				if (kiv < 1) kiv++;
			}

		}
		else if (b == 13) {//enter !!le kell kezelni mert ez már lehet függvényt hív!!
			if (szint < 0) {
				szint++;
				kiv = 0;
			}
		}
		else if (b == 8) { //backspace
			if (szint > 0) {
				szint--;
				kiv = 0;
			}
		}
		MenuKiir(szint, kiv, M);
	}
	printf("   >Kilépés");
	b = _getch();
	if (b == 13) { //double check kilepes
		free(M);
	}
	else if (b == 8) {
		Inditas();
	}
}

