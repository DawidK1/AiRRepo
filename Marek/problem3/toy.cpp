#include "toy.h"

Vector<string> Toy::_toylist = Vector<string>();
const char* Toy::_DB_file = "data.txt";
int Toy::_counter = 0;

int Toy::get_id()const{
    return _id;
}

float Toy::get_price() const{
    return _price;
}

Toy::Toy(int id, float price){
    if(_counter == 0){
        load_from_file();
    }

    if((id >= -1) && (id < _toylist.current_size()))
        _id = id;
    else
        _id = -1;

    if(price > 0)
        _price = price;
    else
        _price = 0;

    _counter ++;
}

Toy::Toy(const Toy &source)
{
    _id = source._id;
    _price = source._price;
    _counter++;
}

Toy::~Toy()
{
    _counter--;
}

string Toy::name() const{
    if(_id != -1)
        return _toylist[_id];
    else
        return "Brak wprowadzonej nazwy";
}

void Toy::load_from_file(){
    string temp;

    ifstream in;
    in.open(_DB_file);

    while(in.good()){
        in >> temp;
        _toylist.push_back(temp);
    }
    in.close();
}

ostream& operator << (ostream& out, const Toy& t){
    out << "Nazwa zabawki: " << t.name() << " cena: " << t._price << endl;
    return out;
}

