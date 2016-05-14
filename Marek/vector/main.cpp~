#include "vector.h"

int main()
{
	try
	{
		Vector a(5);
		cin >> a;
		Vector b(6);
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
