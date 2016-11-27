#ifndef _FIRM_H_
#define _FIRM_H_

#include <iostream>
#include "Shop.h"
#include "MyVector.h"

class Firm{

private:
    string _name;
    Vector<Shop> _shoplist;

public:
    Firm(string name = "Brak nazwy firmy" , const Vector<Shop>& sl = Vector<Shop>(10));
    void add(const Shop& s);
    void ShowAll();
    friend ostream& operator << (ostream& out, Firm& f);
};
























#endif