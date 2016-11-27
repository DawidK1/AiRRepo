#ifndef _FIRM_H_
#define _FIRM_H_

#include <iostream>
#include "Shop.cpp"


class Firm(){

private:
    string _name;
    Vector<Shop> _shoplist;

public:
    Firm(name = "Brak nazwy firmy", shoplist = Vector<Shop>())
    void add(const Shop& s);
    
};
























#endif