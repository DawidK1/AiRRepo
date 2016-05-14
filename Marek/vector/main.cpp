#include "vector.h"

int main()
{
	Vector a(2);
	cin >> a;
	Vector b(3);
	cin >> b;
	cout << "A: " << a << endl;
	cout << "B: " << b << endl;
	cout << "A+B= " << a+b << endl;
	cout << "A-B= " << a-b << endl;
	cout << "B-A= " << b-a << endl;
	cout << "A*3= " << a*3 << endl;
	cout << "3*B= " << 3*b << endl;
	a+=b;
	cout << "A+=B: " << a << endl;
	a-=b;
	cout << "A-=B: " << a << endl;
	return 0;
}
