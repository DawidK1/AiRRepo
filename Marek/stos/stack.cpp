#include "stack.h"

Stack :: Stack(int dlugosc)
{
	tab = new int[dlugosc];
	if (tab == NULL)
		rozmiar = 0;
	else
		rozmiar = dlugosc;
	licznik = 0;
}

Stack :: Stack(const Stack& source)
{
	tab = new int[source.rozmiar];
	if (tab == NULL) 
		rozmiar = 0;
	else
	{
		rozmiar = source.rozmiar;
		licznik = source.licznik;
		for (int i = 0; i < licznik; i++)
			tab[i] = source.tab[i];
		cout << "skopiowalem" << endl;
	}
}

Stack :: ~Stack()
{
	delete[] tab;
	licznik = 0;
	rozmiar = 0;
}

void Stack :: zwieksz()
{
	int* ptab = new int[rozmiar +5];
	if(ptab == NULL)
		rozmiar = rozmiar;
	else
	{
		for(int i = 0; i < licznik; i++)
			ptab[i] = tab[i];
		delete[] tab;
		tab = ptab;
		rozmiar = rozmiar + 5;
	}
}

void Stack :: zmniejsz()
{
	int* ptab = new int[rozmiar -5];
	if(ptab == NULL)
		rozmiar = rozmiar;
	else
	{
		for(int i = 0; i < licznik && i < (rozmiar-5); i++)
			ptab[i] = tab[i];
		delete[] tab;
		tab = ptab;
		rozmiar -= 5;
	}
}

int Stack :: size()
{
	return licznik;
}

int Stack :: isempty()
{
	if(licznik == 0)
		return 1;
	else 
		return 0;
}

int Stack :: top()
{
	if(isempty() == 1)
	{
		cout << "Stos jest pusty!" << endl;
	}
	return tab[0];
}

void Stack :: push(int wartosc)
{
	if(licznik == rozmiar)	
		(*this).zwieksz();
	for(int i = licznik; i > 0; i--)
		tab[i] = tab[i-1];
	tab[0] = wartosc;
	licznik++;
}

void Stack :: pop()
{
	for(int i = 0; i < (licznik - 1); i++)
		tab[i] = tab [i+1];
	licznik --;
	if((rozmiar - licznik) > 5)
		(*this).zmniejsz();
}

void Stack :: wypisz()
{
	for(int i = 0; i < licznik; i++)
		cout << tab[i] << " ";
	cout << endl;
}















