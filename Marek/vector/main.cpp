#include "vector.h"

int main()
{
	try
	{
		Vector a(2);
		Vector b(2);
		Vector c(2);

		cin >> a;
		cin >> b;
		c=a;
		cout << "A: " << a << endl;
		cout << "B: " << b << endl;
		cout << "C=A: " << c << endl;
		cout << "A+B= " << a+b << endl;
		cout << "A-B= " << a-b << endl;
		cout << "B-A= " << b-a << endl;
		cout << "A*3= " << a*3 << endl;
		cout << "3*B= " << 3*b << endl;
		a+=b;
		cout << "A+=B: " << a << endl;
		c-=b;
		cout << "C-=B: " << c << endl;
		a*=4;
		cout << "A*=4: " << a << endl;
		if(a == b) cout << "A==B" << endl;
		if(a != b) cout << "A!=B" << endl;
	}
	
	catch (bad_alloc& bad)
	{
		cout << bad.what() <<endl;
	}
	return 0;
}
