#include <iostream>
#include <vector>

using namespace std;

template <typename Iter>
void wypisuj_na_cout(Iter a,Iter b)
{
  for(Iter i=a; i!=b; ++i)
    {
      cout<<*i<<endl;
    }
}

template <typename Iter>
void wypisuj_na_cout(Iter a,int b)
{
  for(Iter i=a; i!=a+b; ++i)
    {
      cout<<*i<<endl;
    }
}

template <class Container>
void wypisuj_na_cout(const Container& c)
{
  
  for(typename Container::const_iterator i=c.begin(); i!=c.end(); ++i)
    {
      cout<<*i<<endl;
    }
}



int main()
{
  vector<int> v;
  v.push_back(5);
  v.push_back(3);
  v.push_back(4);
  v.push_back(9);
  v.push_back(0);
  cout<<"Dla dwoch iteratorow"<<endl;
  wypisuj_na_cout(v.begin(),v.end());

  cout<<endl;
  cout<<"Dla iteratora i liczby"<<endl;
  wypisuj_na_cout(v.begin(),3);
  cout<<endl<<"Dla kontenera"<<endl;
  wypisuj_na_cout(v);
  cout<<endl;
  
  float a[5];
  a[0]=1;
  a[1]=2;
  a[2]=3;
  a[3]=4;
  a[4]=5;
  
  cout<<"Dla dwoch iteratorow"<<endl;
  wypisuj_na_cout(a,a+5);
  cout<<endl;
  cout<<"Dla iteratora i liczby"<<endl;
  wypisuj_na_cout(a,3);
  cout<<endl;
}
