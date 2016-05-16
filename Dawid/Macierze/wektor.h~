#include <iostream>

using namespace std;

class Wektor
	{
	private:
	int* tab;
	int dim;	
		

	public:

	Wektor(int d, int* t);
	Wektor(int d = 2);
	~Wektor();


	friend ostream& operator<< (ostream& out, const Wektor& v);	
	friend istream& operator>> (istream& in, Wektor& v);	
	
	Wektor& operator= (const Wektor& s);
	Wektor operator+ (const Wektor& s) const;
	Wektor operator- (const Wektor& s) const;
	int operator* (const Wektor& s) const;
	double get(int i);



	};
