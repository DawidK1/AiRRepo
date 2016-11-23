#ifndef TOY_H
#define TOY_H

using namespace std;
#include <iostream>

class Toy{
private:
    int _id;
    float _price;
    int _counter;
    //static Vector _toylist;
    static string _DB_file;
    void load_from_file();


public:
    Toy(int id = 0, float price = 0);
    Toy(Toy& src);



    int get_id() const;
    float get_price() const;
    //string name() const;






~Toy();



};
























#endif // TOY_H
