#ifndef TOY_H
#define TOY_H

using namespace std;

#include <iostream>
#include <fstream>
#include "MyVector.h"



class Toy{
private:
    int _id;
    float _price;
    static int _counter;
    static Vector<string> _toylist;
    static const char*_DB_file;
    void load_from_file();


public:
    Toy(int id = 0, float price = 0);
    Toy(const Toy& src);



    int get_id() const;
    float get_price() const;
    string name() const;
    friend ostream& operator<<(ostream& out, const Toy& t);





~Toy();



};
























#endif // TOY_H
