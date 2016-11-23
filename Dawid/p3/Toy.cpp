#include "Toy.h"


int Toy::get_id()const{
    return _id;
}


float Toy::get_price() const{
    return _price;
}

Toy::Toy( int id , float price){

    _DB_file = "data.txt";
    if( id >= -1 )
        _id = id;
    else
        _id = -1;

    if(price > 0)
        _price = price;
    else
         _price = -1;

    if(_counter == 0)
        ;//load_from_file();


    _counter++;
}


Toy::Toy( Toy& src){

    _id = src._id;
    _price = src._price;
    _counter++;
}


Toy::~Toy(){

    _counter--;
}


void Toy::load_from_file(){
    string temp;

    ifstream in;
    in.open(_DB_file);

if(in){
    in>>temp;
    cout << temp;
    }




}
