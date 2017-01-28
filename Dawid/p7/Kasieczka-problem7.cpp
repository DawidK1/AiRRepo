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

is_less(dt cmp){
    compare_data = cmp;
}
    bool operator() (const dt& a){
        return a < compare_data;
    }
};

  template <typename dt>
 struct multiple{ 
     dt data_to_multiple;
     multiple(dt data){
         data_to_multiple = data;
     }

   void operator() (dt& a){
              a=  a * data_to_multiple;
         }
     };

 ////////////////////////////////////////


template <typename Iter, typename Cond, typename Oper>
void wykonaj_na_spelniajacych(Iter poczatek, Iter za_koncem,
Cond warunek, Oper czynnosc)
{
    for(Iter it = poczatek ; it != za_koncem ; it++){
        if (warunek(*it))
            czynnosc(*it);
    }
}



 ///
 int main() {

    float tab[4] = {1,2,3,4};

    vector<int> v = vector<int>(20,7);

    wypisz_na_cout(v.begin(),v.end());

    wypisz_na_cout(tab, tab+4);

    wypisz_na_cout(v.begin(),6);

    wypisz_na_cout(v);

    wykonaj_na_spelniajacych(v.begin(),v.begin() + 12 ,is_less<int>(24) , multiple<int>(3));

    wypisz_na_cout(v);
	return 0;
}
