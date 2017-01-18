#include <iostream>

#include <vector>


using namespace std;


template <typename Iter>

void wypisz_na_cout(Iter begin, Iter end){
    cout << endl;

    for(Iter It= begin; It!= end; It++){
        cout << *It << " ";
    }
}

template <typename Iter>

void wypisz_na_cout(Iter begin, int how_many){
    int i = 0;
    cout << endl;

    for(Iter It= begin;i < how_many;i++, It++){
        cout << *It << " ";
    }
}

template < typename container>

void wypisz_na_cout(const container & gc){

    cout << endl;

    for(auto It= gc.begin();It!=gc.end(); It++){
        cout << *It << " ";
    }
}
///////////////////////////////////////////


template <typename dt>
struct is_less{

    dt compare_data;



    bool operator() (const dt& a,const dt& b ){
        return a < b;
    }
};

  template <typename dt>
 struct multiple{
   dt operator() (const dt& a,const dt& b ){
              return a * b;
         }
     };

 ////////////////////////////////////////






 ///
 int main() {


    float tab[4] = {1,2,3,4};
    vector<int> v = vector<int>(20,10);
is_less<int> comp =is_less<int>();

    wypisz_na_cout(v.begin(),v.end());

    wypisz_na_cout(tab, tab+4);
    wypisz_na_cout(v.begin(),6);
    wypisz_na_cout(v);
	return 0;
}
