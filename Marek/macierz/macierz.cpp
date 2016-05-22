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
	Macierz c(wier, kol);
	if(wier == b.wier && kol==b.kol) 
	{
		int i;
		for(i = 0;i < wier; i++) {
		  *(c.tab[i]) = *(tab[i]) + *(b.tab[i]);
		}
  	}
	return c;
}

Macierz Macierz :: operator- (const Macierz& b)
{
	Macierz c(wier, kol);
	if(wier == b.wier && kol == b.kol)
	{
		for(int i = 0;i < wier; i++)
		{
			*(c.tab[i]) = *(tab[i]) - *(b.tab[i]);
		}
	}
	return c;
}

void Macierz :: operator= (const Macierz&b)
{
	if(wier == b.wier && kol == b.kol)
	{
		for(int i = 0;i< wier; i++)
			*(tab[i]) = *(b.tab[i]);
		return;
	}
	else
	{
		cout << "Macierze sa roznej wielkosci" << endl;
		return;
	}
}

int Macierz :: operator== (const Macierz& b)
{
	if(wier == b.wier && kol == b.kol)
	{
		for(int i = 0;i< wier; i++)
		{
			if(*(tab[i]) != *(b.tab[i]))
				return 0;
		}
		return 1;
	}
	else
	{
		return 0;
	}
}

int Macierz :: operator!= (const Macierz& b)
{
	if(wier == b.wier && kol == b.kol)
	{
		for(int i = 0;i< wier; i++)
		{
			if(*(tab[i]) != *(b.tab[i]))
				return 1;
		}
		return 0;
	}
	else
	{
		return 1;
	}
}

Wektor Macierz :: operator[] (int b)
{
	if(wier >= b)
		return *(tab[b-1]);
	else
	{
		cout << "Wystapil blad" << endl;
		return *(tab[0]);
	}
}
/*
Macierz Macierz :: operator* (const Macierz &b)
{
	Macierz result(wier, b.kol);
	if(kol == b.wier)
	{
		for(int i = 0; i < wier; i++)
		{
			for(int j = 0; j < b.kol; j++)
			{
				for(int m = 0;m < kol; m++)
					*(result.tab[i][j]) = *(result.tab[i][j]) + ((*(tab[i][m])) * (*(b.tab[m][j])));
			}	
		}
		return result;
	}
	else
	{
		cout << "Podany wymiar macierzy jest zly" << endl;
		return result;
	}
}
*/

Macierz Macierz :: operator* (int b)
{
	Macierz result(wier, kol);
	for(int i = 0;i <  wier; i++)
		*(result.tab[i]) = *(tab[i]) * b;
	return result;
}

void Macierz :: operator+= (const Macierz& b)
{
	if(wier == b.wier && kol == b.kol)
	{
		for(int i = 0;i < wier; i++)
			*(tab[i]) = *(tab[i]) + *(b.tab[i]);
		return;
	}

	else
	{
		cout << "Wystapil blad" << endl;
		return;
	}
}

void Macierz :: operator-= (const Macierz& b)
{
	if(wier == b.wier && kol == b.kol)
	{
		for(int i = 0;i < wier; i++)
			*(tab[i]) = *(tab[i]) - *(b.tab[i]);
		return;
	}

	else
	{
		cout << "Wystapil blad" << endl;
		return;
	}
}

void Macierz :: operator*= (int b)
{
	for(int i = 0;i < wier; i++)
		*(tab[i]) = *(tab[i]) * b;
	return;
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






















