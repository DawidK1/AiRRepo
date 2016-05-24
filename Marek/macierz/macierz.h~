#ifndef MACIERZ
#define MACIERZ

#include "wektor.h"

using namespace std;

class Macierz
{
private: 
	int wier;
	int kol;
	Wektor ** tab;
public:
	Macierz();
	Macierz(int wiersze, int kolumny);
	Macierz(const Macierz& source);
	~Macierz();
	Macierz operator+ (const Macierz& b);
	Macierz operator- (const Macierz& b);
	void operator= (const Macierz& b);
	int operator== (const Macierz& b); // zwraca 1 jak macierze sa sobie rowne, 0 jezeli sa rozne
	int operator!= (const Macierz& b); // zwraca 0 jak macierze sa sobie rowne, 1 jezeli sa rozne
	Wektor operator[] (int b);
	Macierz operator* (const Macierz& b);
	Macierz operator* (int b);
	void operator+= (const Macierz &b);
	void operator-= (const Macierz &b);
	void operator*= (int b);
	friend ostream& operator<< (ostream& wyjscie, Macierz& m);
	friend istream& operator>> (istream& wejscie, Macierz& m);
};


#endif
