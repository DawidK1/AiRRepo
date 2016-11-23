#include <iostream>
#include "pracownik.h"

int main() {

staly osstala("maciej","ciesla",345,999,10000);
zlecenie oszlecenie("anna","nowak",111,888,10,50);
handel oshandel("michal", "cegielski", 222, 777, 3000, 10);
pracownik * tab[3];
tab[0] = &osstala;
tab[1] = &oszlecenie;
tab[2] = &oshandel;
int i;
for(i=0;i<3;i++) {
	(*tab[i]).print();
	cout << endl << endl;
}
return 0;
}
