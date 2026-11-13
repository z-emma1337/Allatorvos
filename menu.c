#include "debugmalloc.h"
#include "conio.h"
#include "menu.h"

menu* menu_init() {
	menu* M = malloc(5 * sizeof(menu);
	menu[0] = menu{ 0,-1,"Kereses"; };
	menu[1] = menu{ 1,-1,"Lista" };
	menu[2] = menu{ 0,0,"Gazdi" };
	menu[2] = menu{ 1,0,"Allat" };
	menu[2] = menu{ 2,0,"Kezeles" };

	return M;
}

void MenuKiir(int szint, int kiv, menu* M) {
	char* cur = " >";
	system("cls");
	printf("/// MENU ///\n");
	for (int i = 0; M[i] != NULL && M[i].elozoIndex == szint - 1; i++) {
		if (kiv == M[i].index) {
			printf("   %s%s", cur, M[i].Menupont);
		}
		else {
			printf("   %s", M[i].Menupont);
		}
	}
}

