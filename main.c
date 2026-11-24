#include "debugmalloc.h"
#include "adatbazis.h"
#include "menu.h"

int main() {
    gazdi* adatok = fajlBe("adatok.txt");
   adatok = menu_init(adatok);
    freeG(adatok);
    return 0;
}