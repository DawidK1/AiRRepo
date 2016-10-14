#include "macierz.h"

int main()
{
	Macierz A(3, 3);
	Macierz B(3, 3);
	Macierz C(3, 3);
	cin >> A;
	cin >> B;
	C = A + B;
	cout << endl;
	cout << A << "+" << endl << endl << B << endl << "=" << endl << C << endl;
	C = A - B;
	cout << A << "-" << endl << endl << B << endl << "=" << endl << C << endl;
	C = B * 3;
	cout << B << "*" << endl << endl << 3 << endl << endl << "=" << endl << C << endl;
	C = A * B;
	cout << A << "*" << endl << endl << B << endl << "=" << endl << C << endl;
	A += B;
	cout << "A+=B" << endl << A << endl;
	A -= B;
	cout << "A-=B" << endl << A << endl;
	A *= 2;
	cout << "A*=2" << endl << A << endl;
	if (A == B) cout << "A==B" << endl;
	if (A != B) cout << "A!=B" << endl;
	
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
