#include "macierz.h"

int main()
{
	cout << "hello" << endl;
	Macierz a;
	Macierz b;
	Macierz wynik;
	Wektor c;
	cin >> a;
	cin >> b;
	cout << a;
	cout << b;
	b  *= 2;
	cout << b << endl;
	
	
	/*int result;
	Wektor a(3);
	Wektor b(3);
	cin >> a;
	cin >> b;
	cout << a;
	cout << b;
	result =a==b;
	cout << result << endl;
	result = a*b;
	cout << result << endl;
	a -= b;
	cout << a << endl;
	b *= 3;
	cout << b << endl;
	result = a[2];
	cout << result << endl;*/
	return 0;
}