#include <iostream>
#include "wektor.h"

using namespace std;

int main()
	{
	int tab[] = {2,4,8}; 
 
	Wektor m = Wektor(3, tab);
	Wektor n = Wektor(m);
	
	cout << m + n;
	cout << m - n;
	cout << m*n;
	cout << m * 7;
	cout << 112*m ;
	}
  
