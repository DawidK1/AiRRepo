#include "wektor.h"


Wektor::Wektor(int d, int* t)
	{
	if(d > 0 && t != NULL)
		{
		dim = d;
		tab = new int[dim];

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
Wektor::Wektor(int d )
	{
	if(d < 1)
		{
		tab = NULL;
		dim = 0;
		}
	else
		{
		dim = d;
		tab = new int[dim];
		if(tab == NULL)
			throw bad_alloc();

		for(int i = 0; i < dim ; i++)
			tab[i] = 0;		
		

		}
	}
Wektor :: Wektor(const Wektor& source)
	{
	dim = source.dim;
		
	tab = new int[dim];
	if (tab == NULL)
		throw bad_alloc();

	for(int i = 0; i < dim ; i++)
		tab[i] = source.tab[i];
	}
Wektor :: ~Wektor()
	{

	delete[] tab;
	tab = NULL;
	}

void Wektor::setVal(int pos, int val)
	{
	if(pos < dim && pos >= 0 )
		tab[pos] = val;		

	}
	
const int Wektor::get(int i)
	{
	if( i >= 0 && i < dim)
		return tab[i];

	else return 0;
	}


ostream& operator<< (ostream& out, const Wektor& v)
	{
	cout << " [ "<< v.tab[0];
	for(int i = 1 ; i < v.dim ; i++)
		{
		cout << ", " << v.tab[i];
		}
	cout << " ]"<< endl;
	return out;
	}
istream& operator>> (istream& in, Wektor& v)
	{
	for(int i = 0 ; i < v.dim ; i++)
		cin >> v.tab[i];
	}



Wektor& Wektor::operator= (const Wektor& s){

	delete[] tab;
	
	tab = new int[s.dim];
	if(tab == NULL)
		{
		dim = 0;
		}
	else
		{
		dim = s.dim;
		for(int i = 0; i < dim ; i++)
			{
			tab[i] = s.tab[i];
			
			}
		}
	return *this;

	}

Wektor Wektor::operator+ (const Wektor& s)const
	{
	static Wektor suma;
	if(dim != s.dim)
		{
		suma.~Wektor();
		Wektor suma = Wektor(0);
		return suma;
		}
	else
		{
		suma.~Wektor();
		suma = Wektor(dim);
		for(int i = 0 ; i < dim ; i++ ) 
			{
			
			suma.tab[i] = tab[i] + s.tab[i];
		
			}
		return suma;	
		}
	}

Wektor Wektor::operator- (const Wektor& s)const
	{
	static Wektor r;
	if(dim != s.dim)
		{
		r.~Wektor();
		Wektor r = Wektor(0);
		return r;
		}
	else
		{
		r.~Wektor();
		r = Wektor(dim);
		for(int i = 0 ; i < dim ; i++ ) 
			{
			
			r.tab[i] = tab[i] - s.tab[i];
			
			}
		return r;	
		}
	}

int Wektor::operator* (const Wektor& s)const
	{
	int result;
	if(dim != s.dim)
		{

		return 0;
		}
	else
		{
		result = 0;
		for(int i = 0 ; i < dim ; i++ ) 
			{
			result = result + (tab[i] * s.tab[i]);
			
			}
		return result;	
		}
	}

Wektor Wektor::operator* (const int& m) const
	{
	static Wektor r;

	r.~Wektor();
	r = Wektor(*this);
	for (int i = 0 ; i < dim ; i++)
		r.tab[i] *= m;
	return r;
	
	}
 Wektor operator* (const int& m, const Wektor& s)
	{
		static Wektor r;

	r.~Wektor();
	r = Wektor(s);
	for (int i = 0 ; i < s.dim ; i++)
		r.tab[i] *= m;
	return r;
	}

bool operator== (const Wektor& v1, const Wektor& v2)
	{
	if(v1.dim != v2.dim)
		return false;
	else
		{
		for(int i = 0 ; i < v1.dim ; i++)
			if(v1.tab[i] != v2.tab[i]) return false;
		return true;
		}
	}


bool operator!= (const Wektor& v1, const Wektor& v2)
	{
	if(v1.dim != v2.dim)
		return true;
		{
		for(int i = 0 ; i < v1.dim ; i++)
			if(v1.tab[i] != v2.tab[i]) return true;
		return false;
		}
	}
	
Wektor Wektor::operator+= (const Wektor& s)
	{
	if(dim == s.dim)
		{
		for(int i = 0 ; i < dim ; i++)
			tab[i] += s.tab[i];
		}
	return *this;
	}

Wektor Wektor::operator-= (const Wektor& s)
	{
	if(dim == s.dim)
		{
		for(int i = 0 ; i < dim ; i++)
			tab[i] -= s.tab[i];
		}
	return *this;
	}

Wektor Wektor::operator*= (const int& m)
	{
	for(int i = 0 ; i < dim ; i++)
		tab[i] *= m;
	return *this;
	}
int Wektor::operator[] (const int& pos)
	{
	if(pos >=0 && pos < dim)
		return tab[pos];
	else
		throw out_of_range("Incorrect position");
	}












