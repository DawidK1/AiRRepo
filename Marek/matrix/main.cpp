#include "matrix.h"

int main()
{
	Matrix A;
	Matrix B(2,2);
	cin >> A;
	cin >> B;
	cout << "A: " << endl << A << endl;
	cout << "B: " << endl << B << endl;
	A=B;
	cout << "A=B: " << endl << A << endl;
//	cout << "A*3: " << endl << A*3 << endl;
//	cout << "3*A: " << endl << 3*A << endl;
	return 0;
}
