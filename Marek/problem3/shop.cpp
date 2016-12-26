#include "shop.h"

Shop::Shop(string name, string adress, const Vector<Toy>& t): _storage(t)
{
    _name = name;
    _adress = adress;
}

void Shop::add(int id, float price)
{
    Toy t(id, price);
    _storage.push_back(t);
}

void Shop::add(const Toy& src)
{
    if(src.get_id() != -1)
        _storage.push_back(src);
}

ostream& operator << (ostream& out, Shop& s)
{
    Iterator <Vector<Toy>,Toy> it = s._storage.begin();

    out << "Nazwa sklepu: " << s._name << endl;

    out << "asortyment: " << endl;
    while(it != s._storage.end())
    {
        out << "\t" << *it ;
        it++;
    }

    return out;
}