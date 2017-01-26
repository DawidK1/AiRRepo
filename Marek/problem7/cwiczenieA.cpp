//Problem 7, cwiczenie A, Marek Piekarz AiR II rok

#include <iostream>
#include <vector>

using namespace std;

template <typename Iter>
void wypisuj_na_cout(Iter start, Iter end)
{
    for(Iter i = start; i != end; ++i)
    {
        cout << *i << endl;
    }
}

template <typename Iter>
void wypisuj_na_cout(Iter start, int a)
{
    for(Iter i = start; i != start+a; ++i)
    {
        cout << *i << endl;
    }
}


template <typename Container>
void wypisuj_na_cout(const Container& c)
{
    for(typename Container :: const_iterator i = c.begin(); i != c.end(); ++i)
    {
        cout << *i << endl;
    }
}

int main()
{
    cout << "Testuje na Vectorze" << endl << endl;
    vector<int> v;
    v.push_back(3);
    v.push_back(2);
    v.push_back(6);
    v.push_back(9);
    v.push_back(8);
    v.push_back(1);
    v.push_back(3);
    v.push_back(0);

    cout << "dwa iteratory" << endl;
    wypisuj_na_cout(v.begin(),v.end());

    cout << endl << "iterator i liczba" << endl;
    wypisuj_na_cout(v.begin(), 3);

    cout << endl << "kontener" << endl;
    wypisuj_na_cout(v);
    cout << endl << "------------------------------" << endl;

    float a[4];
    a[0] = 0;
    a[1] = 1;
    a[2] = 2;
    a[3] = 3;

    cout << endl << "Testuje na tablicy" << endl << endl;
    cout << "dwa iteratory" << endl;
    wypisuj_na_cout(a,a+4);
    cout << endl << "iterator i liczba" << endl;
    wypisuj_na_cout(a, 3);
    cout << endl;
    return 0;

}
