#include <iostream>
#include "MyVector.h"
#include "Toy.h"
#include "Shop.h"
using namespace std;


int main(){
Toy t1(2,6.50);
Toy t2(3,5);
Toy t3(1,5.55);
Shop s1("Smyk", "ul. f40");
s1.add(t1);
s1.add(t2);
s1.add(t3);

cout << s1;
return 0;
}