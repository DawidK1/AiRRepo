#include "matrix.h"

int main()
{
	Matrix A;
	Matrix B(2,2);
	cin >> A;
	cin >> B;
	cout << "A: " << endl << A << endl;
	cout << "B: " << endl << B << endl;
	cout << "A-B: " << endl << A-B << endl;
	return 0;
}
