#include "wektor.h"

Wektor :: Wektor()
{
	dlugosc = 2;
	tab = new int[dlugosc];
	for(int i = 0;i < dlugosc; i++)
		tab[i] = 0;
}

Wektor :: Wektor(int nowa_dlugosc)
{
	dlugosc = nowa_dlugosc;
	tab = new int[dlugosc];
	for(int i = 0;i < dlugosc; i++)
		tab[i] = 0;
}

Wektor :: Wektor(const Wektor& source)
{
	dlugosc = source.dlugosc;
	tab = new int[dlugosc];
	for(int i = 0;i < dlugosc; i++)
		tab[i] = source.tab[i];
}

Wektor :: ~Wektor()
{
	delete[] tab;
	
}

Wektor Wektor :: operator+ (const Wektor& b)
{
	Wektor result(dlugosc);
	if(dlugosc == b.dlugosc)
	{
		for(int i = 0;i < dlugosc; i++)
			result.tab[i] = tab[i] + b.tab[i];
	}
	return result;
}

Wektor Wektor :: operator- (const Wektor& b)
{
	Wektor result(dlugosc);
	if(dlugosc == b.dlugosc)
	{
		for(int i = 0;i < dlugosc; i++)
			result.tab[i] = tab[i] - b.tab[i];
	}
	return result;
}

void Wektor :: operator= (const Wektor& b)
{
	if(dlugosc == b.dlugosc)
	{
		for(int i = 0;i < dlugosc; i++)
			tab[i] = b.tab[i];
		return;
	}
	else
	{
		cout << "Wektory sa roznych rozmiarow, nie przypisalem ich" << endl;
		return;
	}
}

int Wektor :: operator== (const Wektor& b)
{
	if(dlugosc == b.dlugosc)
	{
		for(int i = 0;i < dlugosc; i++)
		{
			if(tab[i] != b.tab[i])
				return 0;
		}
		return 1;
	}
	else
		return 0;
}

int Wektor :: operator!= (const Wektor& b)
{
	if(dlugosc == b.dlugosc)
	{
		for(int i = 0;i < dlugosc; i++)
		{
			if(tab[i] != b.tab[i])
				return 1;
		}
		return 0;
	}
	else
		return 1;
}

int Wektor :: operator* (const Wektor& b)
{
	int result = 0;
	if(dlugosc == b.dlugosc)
	{
		for(int i = 0;i < dlugosc; i++)
			result += tab[i] * b.tab[i];
		return result;	
	}
	else
	{
		cout << "Wektory sa roznych rozmiarow" << endl;
		return 0;
	}
}

Wektor Wektor :: operator* (const int a)
{
	Wektor result(dlugosc);
	for(int i = 0;i < dlugosc; i++)
		result.tab[i] = a * tab[i];
	return result;
}

Wektor operator* (const int a, const Wektor& b)
{
	Wektor result(b.dlugosc);
	for(int i = 0;i < b.dlugosc; i++)
		result.tab[i] = a * b.tab[i];
	return result;
}

int Wektor :: operator[] (int b)
{
	if(dlugosc >= b)
		return tab[b-1];
	else
	{
		cout << "Podales zly rozmiar" << endl;
		return 0;
	}
}

void Wektor :: operator+= (const Wektor& b)
{
	if(dlugosc == b.dlugosc)
	{
		for(int i = 0;i < dlugosc; i++)
			tab[i] = tab[i] + b.tab[i];
		return;
	}
	else
	{
		cout << "Wystapil blad" << endl;
		return;
	}
	
}

void Wektor :: operator-= (const Wektor& b)
{
	if(dlugosc == b.dlugosc)
	{
		for(int i = 0;i < dlugosc; i++)
			tab[i] = tab[i] - b.tab[i];
		return;
	}
	else
	{
		cout << "Wystapil blad" << endl;
		return;
	}
	
}

void Wektor :: operator*= (const int a)
{
	for(int i = 0;i < dlugosc; i++)
		tab[i] = a * tab[i];
}

ostream& operator<< (ostream& wyjscie, Wektor& b)
{
	wyjscie << "[";
	for(int i = 0;i < b.dlugosc - 1; i++)
		wyjscie << setw(3) << b.tab[i] << ",";
	wyjscie << setw(3) << b.tab[b.dlugosc - 1] << "]" << endl;
	return wyjscie;
}

istream& operator>> (istream& wejscie, Wektor& b)
{
	for(int i = 0;i < b.dlugosc; i++)
		wejscie >> b.tab[i];
	return wejscie;
}
























