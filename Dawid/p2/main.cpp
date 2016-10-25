#include <iostream>
#include "workers.h"


int main(){

    FulltimeWorker w1 = FulltimeWorker();
    HourPaidWorker w2 = HourPaidWorker();
    Dealer w3 = Dealer();

    FulltimeWorker w11("Jan", "Kowalski", 7611, 14531, 5200, 3);
    HourPaidWorker w22("Piotr", "Kowalski", 8805, 24531, 22, 105);
    Dealer w33("Zbigniew", "Kowalski", 6688, 34531, 100000 , 0.12);

    Worker* tab[6];

    tab[0] = &w1;
    tab[1] = &w2;
    tab[2] = &w3;
    tab[3] = &w11;
    tab[4] = &w22;
    tab[5] = &w33;

    for(int i = 0 ; i <  6 ; i++){
        tab[i] -> print();
    }

return 0;
}
