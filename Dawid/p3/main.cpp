#include <iostream>

#include "MyVector.h"
#include "Toy.h"
#include "Shop.h"
#include "Firm.h"
using namespace std;


int main(){
    Toy t1(2,6.50);
    Toy t2(3,5);
    Toy t3(1,5.55);
    Shop s1("Smyk", "ul. f40");
    Shop s2("TOYZ", "ul. Reymonta 1");

    Firm f1("Smyk");


    s1.add(t1);
    s1.add(t2);
    s1.add(t3);
    s2.add(t1);
    s2.add(t2);
    s2.add(t3);
    s2.add(t1);
    s2.add(t2);
    f1.add(s1);
    f1.add(s2);
    //cout << f1;
    f1.ShowAll();
    return 0;
}