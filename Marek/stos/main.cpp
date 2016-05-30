#include "stack.h"

int main()
{
	cout << "hello" << endl;
	Stack stos (5);
	int a=0;
	a = stos.isempty();
	cout << "czy jest pusty? " << a << endl;
	stos.push(2);
	a = stos.top();
	cout << a << endl;
	stos.push(3);
	a = stos.top();
	cout << a << endl;
	stos.push(8);
	stos.push(-6);
	stos.push(6);
	stos.push(5);
	stos.push(30);
	stos.push(8);
	stos.push(-6);
	stos.push(6);
	stos.push(5);
	stos.push(30);
	stos.wypisz();
	a = stos.isempty();
	cout << "czy jest pusty? " << a << endl;
	a = stos.size();
	cout << "size " << a << endl;
	a = stos.top();
	cout << a << endl;
	stos.pop();
	a = stos.top();
	cout << a << endl;
	return 0;
}
