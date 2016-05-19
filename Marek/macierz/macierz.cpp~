#include "macierz.h"

Macierz :: Macierz() 
{
	wier = 2;
	kol = 2;
	tab = new Wektor* [wier];
	int i;
	Wektor* tablica;
	tablica = new Wektor[wier];
	for(i = 0;i < wier; i++) {
		tab[i]=&(tablica[i]);
	}
}

Macierz :: Macierz (int kolumny,int wiersze) 
{
	wier = wiersze;
	kol = kolumny;
	tab = new Wektor* [wier];
	int i;
	for(i = 0;i < wier; i++) {
		tab[i]=new Wektor(kol);
	}
}

Macierz :: Macierz(const Macierz &source)
{
	wier = source.wier;
	tab = new Wektor* [wier];
	for(int i = 0;i < wier; i++)
		tab[i] = new Wektor(kol);
	for(int i = 0;i < wier; i++)
		*(tab[i]) = *(source.tab[i]);
}

Macierz :: ~Macierz()
{
	delete[] tab;		
}

Macierz Macierz :: operator+ (const Macierz& b) 
{
	Macierz c(wier,kol);
	if(wier == b.wier && kol==b.kol) 
	{
		int i;
		for(i = 0;i < wier; i++) {
		  *(c.tab[i]) = *(tab[i]) + *(b.tab[i]);
		}
  	}
	return c;
}




ostream& operator<< (ostream& wyjscie, Macierz& m)
{
	for(int i = 0;i < m.wier; i++)
		wyjscie << *(m.tab[i]) << endl;
	return wyjscie;
}

istream& operator>> (istream& wejscie, Macierz& m)
{
	for(int i = 0;i < m.wier; i++)
		wejscie >> *(m.tab[i]);
	return wejscie;
}























