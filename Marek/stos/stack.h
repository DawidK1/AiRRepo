#ifndef STACK
#define STACK

#include <iostream>
#include <string>
using namespace std;

class Stack
{
private:
	int* tab;
	int licznik; //informuje o liczbie elementów na stosie
	int rozmiar; //aktualny rozmiar stosu
public:
	Stack(int dlugosc = 5);
	Stack(const Stack& source);
	~Stack();
	
	void zwieksz(); //zwieksza rozmiar stosu o 5
	void zmniejsz(); // zmniejsza rozmiar stosu o 5
	int size(); //zwraca wysokosc stosu
	int isempty(); //zwraca 1 gdy stos jest pusty, 0 gdy stos nie jest pusty
	int top(); //zwraca element na szczycie
	void push(int wartosc); //dodaje nowy element na szczyt stosu
	void pop(); //usuwa element na szczycie stosu
	void wypisz(); //pokazuje caly stos
};

#endif
