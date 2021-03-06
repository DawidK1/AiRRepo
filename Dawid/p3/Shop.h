#ifndef SHOP_H_
#define SHOP_H_

#include <iostream>
#include "MyVector.h"
#include "Toy.h"

class Shop{
    
private:
    Vector<Toy> _storage;
    string _adress;
    string _name;
public:

    Shop(string name = "Brak nazwy", string adress = "Nie podano adresu"
    ,const Vector<Toy>& t = Vector<Toy>(5));


    void add(int id, float price = 0);
    void add (const Toy& t);

    string getAdress() const{
        return _adress;}
    string getName() const{
        return _name;}

    friend ostream& operator<<(ostream& out , Shop& s);
    friend class Firm;
    ~Shop(){
        ;
    }
};







#endif