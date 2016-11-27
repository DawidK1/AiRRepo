#include "Firm.h"


    Firm::Firm(string name ,const Vector<Shop>& sl ) :_name(name), _shoplist(sl){
;}

void Firm::add(const Shop& s){
    _shoplist.push_back(s);
}


ostream& operator << (ostream& out, Firm& f){

    out << "Nazwa firmy: " <<f._name << endl;
    out << "Posiadane sklepy: " << endl;
    Iterator<Vector<Shop>, Shop> it = f._shoplist.begin();

    for( ; it != f._shoplist.end() ; it++){
        out<<'\t' <<(*it).getAdress()<<endl;
    }
    return out;
}
void Firm::ShowAll(){
        cout << "Nazwa firmy: " <<_name << endl;
    cout << "Posiadane sklepy: " << endl;
    Iterator<Vector<Shop>, Shop> it = _shoplist.begin();

    for( ; it != _shoplist.end() ; it++){
        cout<<'\t' <<(*it).getAdress()<<endl;
        for(  Iterator <Vector<Toy>,Toy> it2 = (*it)._storage.begin();
        it2 !=  (*it)._storage.end() ;  it2++  ){
                    cout<<"\t\t" <<*it2;
            }
    }
   
}