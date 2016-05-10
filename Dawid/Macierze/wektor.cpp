#include "wektor.h"


Wektor::Wektor(int d, double* t)
	{
	if(d > 0 && t != NULL)
		{
		dim = d;
		tab = new double[dim];

		if(tab == NULL)
			{
			dim = 0;			
			return;	
			}

		//kopiowanie do nowej tablicy
		for(int i = 0 ; i < dim ; i++)
			{
			tab[i] = t[i];
			}
		}
	else
		{
		dim = 0;
		tab = NULL;
		} 
	}
double Wektor::get(int i)
	{
	if( i >=0 && i < dim)
		return tab[i];

	else return 0;
	}
void Wektor::show()
	{
	cout <<endl << "[ "<< tab[0];
	for(int i = 1 ; i < dim ; i++)
		{
		cout << ", " << tab[i];
		}
	cout << " ]"<< endl;
	}
















