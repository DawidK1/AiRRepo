#include <iostream>

#include "tvector.h"
#include "toy.h"
#include "shop.h"
#include "firm.h"

using namespace std;

int main()
{
    Toy t1(0, 7.50);
    Toy t2(3,5);
    Toy t3(1,3.33);
    Toy t4(4,6.15);
    Shop s1("Samochodzik", "ul. Dluga 10");
    Shop s2("Zabawkowy", "ul. Krotka 150");
    Firm f1("Art. Zabawkowe");

    Shop s3("Maluszek", "ul. Zawila 42");
    Shop s4("Kolorowy", "ul. Prosta 15");
    Shop s5("Sklep z zabawkami", "ul. Rynek 8");
    Firm f2("M&P Company");

    s1.add(t1);
    s1.add(t2);
    s1.add(t3);
    s2.add(t1);
    s2.add(t1);
    s2.add(t4);
    s2.add(t2);
    s2.add(t2);
    f1.add(s1);
    f1.add(s2);
    f1.ShowAll();

    s3.add(t1);
    s3.add(t2);
    s4.add(t3);
    s4.add(t3);
    s5.add(t1);
    s5.add(t3);
    s5.add(t4);
    f2.add(s3);
    f2.add(s4);
    f2.add(s5);
    f2.ShowAll();
    cout << s3;
    return 0;
}
