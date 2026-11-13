#include "debugmalloc.h"
#include "adatbazis.h"
#include "menu.h"
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
   

    freeG(adatok);
    return 0;
}