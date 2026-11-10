#include "debugmalloc.h"
#include "adatbazis.h"
#include "stdio.h"
#include "conio.h"
#include "stdlib.h"

int main() {
    gazdi* adatok = fajlBe("adatok.txt");

    if (adatok == NULL) {
        printf("Hiba: Fajlbeolvasas sikertelen.\n");
        freeG(adatok);
        return 0;
    }

    int b = 0;
    int menu = 0;

    while (b != 27) {
        system("cls");

        printf("/// MENU ///\n");

        if (menu == 0)
            printf("  > Kereses\n");
        else
            printf("    Kereses\n");

        if (menu == 1)
            printf("  > Lista\n");
        else
            printf("    Lista\n");

        b = _getch();

        if (b == 224) {
            b = _getch();

            if (b == 72 && menu > 0) {
                menu--;
            }
            else if (b == 80 && menu < 1) {
                menu++;
            }
        }
    }

    freeG(adatok);
    return 0;
}