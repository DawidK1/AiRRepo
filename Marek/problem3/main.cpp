#include <iostream>

#include "tvector.h"
#include "toy.h"
#include "shop.h"
#include "firm.h"

using namespace std;

int main()
{
    /*
    Vector<int> A;
    int B=10;
    A.push_back(B);
    int a=A.current_size();
    cout << a <<endl;
    if(A.isempty())
        cout << "A jest puste" << endl;
    if(A.isfull())
        cout << "A jest pelne" << endl;
    return 0;
    */

    Toy t1(0, 7.50);
    Toy t2(3,5);
    Toy t3(1,3.33);
    Shop s1("Samochodzik", "ul. Dluga 10");
    Shop s2("Zabawkowy", "ul. Krotka 150");
    Firm f1("Art. Zabawkowe");

    s1.add(t1);
    s1.add(t2);
    s1.add(t3);
    s2.add(t1);
    s2.add(t1);
    s2.add(t1);
    s2.add(t2);
    s2.add(t2);
    f1.add(s1);
    f1.add(s2);
    f1.ShowAll();

    return 0;
}
