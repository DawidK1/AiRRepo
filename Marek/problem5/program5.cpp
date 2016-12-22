#include <iostream>
#include <vector> //vector class-template
#include <set>

#include <algorithm>
#include <numeric>

using namespace std;

int main()
{
    vector<int> v;
    // add integers at the end of the vector
    v.push_back(2);
    v.push_back(3);
    v.push_back(4);
    v.push_back(7);
    v.push_back(5);

    cout << "ZADANIE A - VECTOR" << endl << endl;
    v.insert(++v.begin(), 7);
    v[0] = 9;
    v.push_back(v[0]);
    v.push_back(v[1]);
    cout <<"Pierwszy element o wartosci 3 to: " << *find(v.begin(), v.end(),3) << endl;
    v.erase(find(v.begin(), v.end(), 3));
    cout <<"Element o najmniejszej wartosci: " << *min_element(v.begin(), v.end()) << endl;
    sort(v.begin(), v.end());
    reverse(v.begin(), v.end());
    cout << "Ilosc dziewiatek: " << count(v.begin(), v.end(), 9) <<endl;
    cout << "Suma 4 pierwszych: " << accumulate(v.begin(), v.begin()+4, 0)<<endl;

    // display info about v
    cout << "The size of v is: " << v.size() << "\nThe capacity of v is: " << v.capacity();
    vector<int>::const_iterator it;
    cout << "\nThe content of v is: ";

    for (it = v.begin(); it != v.end(); it++)
    {
    cout << *it << " ";
    }
    cout << endl << endl;
    //====================================================

    cout << "ZADANIE B SET" << endl << endl;

    set<int, less <int> > s;

    s.insert(2);
    s.insert(3);
    s.insert(4);
    s.insert(7);
    s.insert(5);

    set<int, less <int> > ::iterator it_s;
    for (it_s = s.begin(); it_s != s.end(); it_s++)
    {
        cout << *it_s << " ";
    }
    cout << endl << endl;
    /*
    cout << "ZADANIE A - VECTOR" << endl << endl;
    v.insert(++v.begin(), 7);
    v[0] = 9;
    v.push_back(v[0]);
    v.push_back(v[1]);
    cout <<"Pierwszy element o wartosci 3 to: " << *find(v.begin(), v.end(),3) << endl;
    v.erase(find(v.begin(), v.end(), 3));
    cout <<"Element o najmniejszej wartosci: " << *min_element(v.begin(), v.end()) << endl;
    sort(v.begin(), v.end());
    reverse(v.begin(), v.end());
    cout << "Ilosc dziewiatek: " << count(v.begin(), v.end(), 9) <<endl;
    cout << "Suma 4 pierwszych: " << accumulate(v.begin(), v.begin()+4, 0)<<endl;

    // display info about v
    cout << "The size of v is: " << v.size() << "\nThe capacity of v is: " << v.capacity();
    vector<int>::const_iterator it;
    cout << "\nThe content of v is: ";

    for (it = v.begin(); it != v.end(); it++)
    {
    cout << *it << " ";
    }
    cout << endl << endl;
*/
    return 0;
}
