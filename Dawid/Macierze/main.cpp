#include <iostream>
#include "wektor.h"

using namespace std;

int main()
	{
	int tab[] = {1,3,6}; 
 	int tab2[] = {-2, -6 , -2};
	Wektor m = Wektor(3, tab);
	Wektor n = Wektor(3, tab2);
	

	cout << "A " << m;
	cout << "B " << n;
	cout << "A + B" << m + n ;
	cout << "A - B"<< m - n ;
	cout << "A * B = " << m*n;
	cout << endl;
	cout << "A * 7" << m * 7;
	cout << "17 * A" << 112*m ;
	cout << "A += B" << (m += n);
	cout << "A -= B" <<  (m-=n) ;
	cout << "A == A " << (m == m) ;
	cout <<endl; 
	cout << "A != A " << (m != m);
	cout << endl;
	cout << "A[0] = " << m[0] ;
	}
  
