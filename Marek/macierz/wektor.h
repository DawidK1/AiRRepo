#ifndef WEKTOR
#define WEKTOR

#include <iostream>
#include <iomanip>

using namespace std;

class Wektor
{
private:
	int dlugosc;
	int* tab;
public:
	Wektor();
	Wektor(int nowa_dlugosc);
	Wektor(const Wektor& source);
	~Wektor();
	
	Wektor operator+ (const Wektor& b);
	Wektor operator- (const Wektor& b);
	void operator= (const Wektor& b);
	int operator== (const Wektor& b); // funkcja zwraca logiczne 1 lub 0
	int operator!= (const Wektor& b); // funkcja zwraca logiczne 1 lub 0
	int operator* (const Wektor& b); // mnozenie skalarne dwoch wektorow
	Wektor operator* (const int a); // wektor razy skalar
	friend Wektor operator* (const int a, const Wektor& b); // skalar razy wektor
	int operator[] (int b);
	void operator+= (const Wektor &b);
	void operator-= (const Wektor &b);
	void operator*= (const int a);
	friend ostream& operator<< (ostream& wyjscie, Wektor& b);
	friend istream& operator>> (istream& wejscie, Wektor& b);
};

#endif
