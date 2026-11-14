#include "debugmalloc.h"
#include "adatbazis.h"

int main() {
    gazdi* adatok = fajlBe("adatok.txt");
    menu_init(adatok);
    freeG(adatok);
    return 0;
}