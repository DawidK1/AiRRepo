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
	Wektor(const Wektor& source);
	~Wektor();


	friend ostream& operator<< (ostream& out, const Wektor& v);	
	friend istream& operator>> (istream& in, Wektor& v);	
	friend Wektor operator* (const int& m, const Wektor& s);
	friend bool operator== (const Wektor& v1, const Wektor& v2);
	friend bool operator!= (const Wektor& v1, const Wektor& v2);

	Wektor& operator= (const Wektor& s);
	Wektor operator+ (const Wektor& s) const;
	Wektor operator- (const Wektor& s) const;
	int operator* (const Wektor& s) const;
	Wektor operator* (const int& m) const;
	Wektor operator+= (const Wektor& s);
	Wektor operator-= (const Wektor& s);
	Wektor operator*= (const int& m);
	double get(int i);



	};
