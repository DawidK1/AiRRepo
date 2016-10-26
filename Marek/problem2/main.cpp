#include "worker.h"

int main()
{
    FullTime F = FullTime();
    PartTime P = PartTime();
    Traders T = Traders();

    FullTime F2("Alicja", "Nowak", 12453, 758, 7600, 2);
    PartTime P2("Jozef", "Kowal", 32156, 987, 17, 140);
    Traders T2("Adam", "Topolski", 753951, 764, 0.07, 15000);

    Worker* tab[6];

    tab[0] = &F;
    tab[1] = &P;
    tab[2] = &T;
    tab[3] = &F2;
    tab[4] = &P2;
    tab[5] = &T2;

    for(int i = 0; i < 6; i++)
        tab[i] -> print();

    return 0;
}
