#include "firm.h"

Firm::Firm(string name, const Vector<Shop>& s1): _name(name), _shoplist(s1){}

void Firm::add(const Shop& s)
{
    _shoplist.push_back(s);
}

ostream& operator << (ostream& out, Firm& f)
{
    out << "Nazwa firmy: " << f._name <<endl;
    out << "Sklepy nalezace do tej firmy: " << endl;
    
    Iterator <Vectro<Shop>, <Shop> it = f._shoplist.begin();

    for( ; if != f._shoplist.end(); it++)
    {
        out << '\t' << (*it).getAdress() << endl;
    }
    return out;
}

void Firm::ShowAll()
{
    cout << "Nazwa firmy: " << _name << endl;
    cout << "Sklepy nalezace do tej firmy: " << endl;

    Iterator <Vectro<Shop>, <Shop> it = f._shoplist.begin();

    for( ; it != _shoplist.end(); it++)
    {
        cout << '\t' << (*it).getAdress() << endl;
        for( Iterator <Vector<Toy>, Toy> it2 = (*it)._storage_begin(); it2 != (*it)._storage_end(); it2++)
        {
            cout << "\t\t" << *it2;
        }
    }
}