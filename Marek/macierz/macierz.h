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
	Macierz operator+ (const Macierz &b);
	
	friend ostream& operator<< (ostream& wyjscie, Macierz& m);
	friend istream& operator>> (istream& wejscie, Macierz& m);
};


#endif
