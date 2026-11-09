#include "debugmalloc.h"
#include "adatbazis.h"
int main() {
	gazdi* adatok = fajlBe("adatok.txt");

	if (adatok == NULL){
		printf("Hiba: Fajlbeolvasas sikertelen.");
	}
	else {
		printf("Siker!");
	}

	freeG(adatok);
	return 0;

}