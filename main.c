#include "debugmalloc.h"
#include "adatbazis.h"

int main() {
    gazdi* adatok = fajlBe("adatok.txt");

    if (adatok == NULL) {
        printf("Hiba: Fajlbeolvasas sikertelen.\n");
        freeG(adatok);
        return 0;
    }
    menu_init(adatok);

    freeG(adatok);
    return 0;
}