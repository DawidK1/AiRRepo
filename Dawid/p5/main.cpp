#include <iostream>

#include <vector>
#include <set>
#include <map>

#include <algorithm>
#include <numeric>

using namespace std;

int main() {

	cout << "\tczesc pierwsza" << endl;
	vector<int> v;
	vector<int>::const_iterator it;
	// add integers at the end of the vector
	v.push_back(2);
	v.push_back(3);
	v.push_back(4);
	v.push_back(7);
	v.push_back(5);
	cout << "The size of v is: " << v.size() << "\nThe capacity of v is: " << v.capacity();
	cout << "\nThe content of v is: ";
	for (it = v.begin(); it != v.end(); it++) {
		cout << *it << " ";
	}
	cout << endl << endl;
	/////////////////////////1
	v.insert(v.begin()+1, 7);
	////////////////////2
	v[0]=9;
	///////////////////////3
	v.push_back(v[0]);
	v.push_back(v[1]);
	//////////////////////4
	cout << "indeks elementu o wartosci 3: " << *find(v.begin(), v.end(), 3) << endl;
	///////////////////5
	v.erase(find(v.begin(), v.end(), 3));
	//////////////////6
	cout << "Najmniejszy element w wektorze to: " << *min_element(v.begin(), v.end()) << endl;
	//////////////////7
	sort(v.begin(), v.end());
	//////////////////8
	reverse(v.begin(), v.end());
	///////////////9
	cout << "liczba dziewiatek: " << count(v.begin(), v.end(), 9) << endl;

	///////////////10
	cout << "Suma pierwszych czterech elementow : " << accumulate(v.begin(), (v.begin() + 4) , 0) << endl;
	 
	// display info about v
	cout << "\nrozmiar v to: " << v.size() << "\nzarezerwowana pamiec: " << v.capacity();
	cout << "\nzawartosc wektora v: ";
	for (it = v.begin(); it != v.end(); it++) {
		cout << *it << " ";
	}
	cout << endl << endl;

//============================================================

	cout << "\tczesc druga" << endl;
	set < int, less < int > > s;
	set < int, less < int > > ::const_iterator it_s;
	// add integers to set
	s.insert(2);
	s.insert(3);
	s.insert(4);
	s.insert(7);
	s.insert(5);
	cout << "The size of s is: " << s.size();
	cout << "\nThe content of s is: ";
	for (it_s = s.begin(); it_s != s.end(); it_s++) {
		cout << *it_s << " ";
	}
	cout << endl << endl;
	//////////////1
	s.insert(7);
	/////////////2
	s.erase(s.begin());
	s.insert(9);
	///////////////4
	cout << "Element o wartosci 3: " << *find(s.begin(), s.end(), 3) << endl;
	//////////////5
	s.erase(find(s.begin(), s.end(), 3));
	/////////6
	cout << "Najmniejszy element w zbiorze to: " << *min_element(s.begin(), s.end()) << endl;
	//////////////9
	cout << "Ilosc dziewiatek: " << count(s.begin(), s.end(), 9) << endl
	     << "Suma dziewiatek wynosi " << count(s.begin(), s.end(), 9) * 9 << endl;
	////////////////10
    it_s = s.begin();
    it_s++;
    it_s++;
    it_s++;// s.begin() + 4 nie dziala dla set, nie udalo mi sie znalezc przyczyny
    it_s++;
	cout << "Suma pierwszych czterech elementow setu: " << accumulate(s.begin(), it_s, 0) << endl;
	/////////////////// display info about s
	cout << "\nThe size of s is: " << s.size();
	cout << "\nThe content of s is: ";
	for (it_s = s.begin(); it_s != s.end(); it_s++) {
		cout << *it_s << " ";
	}
	cout << endl << endl;

//============================================================
	
	cout << "\tczesc trzecia" << endl;
	typedef multimap <int, string, less <int>> mp_type;
	mp_type mp;
	mp_type::iterator it_mp;
	/////////////////// add pairs to multimap
	mp.insert(pair<int, string>(2, "dwa"));
	mp.insert(pair<int, string>(3, "trzy"));
	mp.insert(pair<int, string>(4, "cztery"));
	mp.insert(pair<int, string>(7, "siedem"));
	mp.insert(pair<int, string>(5, "piec"));
	cout << "Rozmiar mapy to: " << mp.size();
	cout << "\nzawartosc: \n";
	for (it_mp = mp.begin(); it_mp != mp.end(); it_mp++) {
		cout << (*it_mp).first << " " << (*it_mp).second << endl;
	}
	cout << endl << endl;
	//////////////////1
	mp.insert(pair<int, string>(7, "siedem"));
	///////////////////////2
	mp.erase(mp.begin());
	mp.insert(pair<int, string>(9, "dziewiec"));
	///////////////3
	pair <int, string> temp = *mp.begin();
	it_mp = (++mp.begin());
	mp.insert(temp);
	mp.insert(*it_mp);
	////////////////////4
	pair <mp_type::iterator, mp_type::iterator> range;
	range = mp.equal_range(3);
	cout << "Element o wartosci 3 to: \n";
	for (it_mp = range.first; it_mp != range.second; it_mp++)
		cout << (*it_mp).first << " " << (*it_mp).second << endl;
	///////////////////5
	mp.erase(3);
	/////////////////6
	cout << "Najmniejszy element w multimap to: " << (*min_element(mp.begin(), mp.end())).first << " " << (*min_element(mp.begin(), mp.end())).second << endl;
	////////////////9
	cout << "Ilosc dziewiatek: " << mp.count(9) << endl;

	//////////////////10
	int suma, k;
	for (it_mp = mp.begin(), k = 0, suma = 0; k < 4; it_mp++, k++) {
		suma+=(*it_mp).first;
	}
	cout << "Suma pierwszych czterech elementow: " << suma << endl;
	////////////////// display info about mp
	cout << "\nRozmiar mapy to: " << mp.size();
	cout << "\nZawartosc mapy to: \n";
	for (it_mp = mp.begin(); it_mp != mp.end(); it_mp++) {
		cout << (*it_mp).first << " " << (*it_mp).second << endl;
	}
	cout << endl << endl;

//============================================================

	return 0;
}