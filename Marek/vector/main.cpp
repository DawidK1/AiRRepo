#include "vector.h"

int main()
{
	Vector a(2);
	cin >> a;
	Vector b(2);
	cin >> b;
	cout << "A: " << a << endl;
	cout << "B: " << b << endl;
	a=b;
	cout << "A: " << a << endl;

	return 0;
}
