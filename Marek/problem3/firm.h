#ifndef FIRM_H_
#define FIRM_H_

#include <iostream>
#include "shop.h"
#include "tvector.h"

class Firm 
{
private:
    string _name;
    Vector<Shop> _shoplist;

public:
    Firm(string name = "Nie podano nazwy firmy", const Vector<Shop>& s1=Vector<Shop>(10));
    void add(const Shop& s);
    void ShowAll();
    friend ostream& operator << (ostream& out, Firm& f);
};

#endif 