#include <iostream>

using namespace std;

class Wektor
	{
	private:
	double* tab;
	int dim;	
		

	public:

	Wektor(int d, double* t);
	double get(int i);
	void show();
	


	};