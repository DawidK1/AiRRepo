#include <iostream>
#include "wektor.h"

using namespace std;

int main()
	{
	int tab[] = {2,4,8}; 
 
	Wektor m = Wektor(3, tab);
	Wektor n = Wektor(3, tab);
	
	cout << m + n;
	cout << m - n;
	cout << m*n;
	}
  
