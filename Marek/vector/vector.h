#ifndef VECTOR
#define VECTOR

#include <iostream>
#include <iomanip>

using namespace std;

class Vector
{
private:
	int size;
	int *fields;

public:
	Vector(int new_size = 2);
	Vector(const Vector& source);
	~Vector();
	
	friend ostream& operator << (ostream& out, const Vector& v_out);
	friend istream& operator >> (istream& in, const Vector& v_in);
	
	Vector& operator= (const Vector& source);
	Vector operator+ (const Vector& add);
	Vector operator- (const Vector& sub);
	Vector operator* (const int& mult); //wektor razy skalar
	friend Vector operator* (const int& mult, const Vector& source); //skalar razy wektor
	int operator* (const Vector& source); //wektor razy wektor
	Vector operator+= (const Vector& add);
	Vector operator-= (const Vector& sub);
	Vector operator*= (const int& mult);
	
	bool operator!= (const Vector& v_2);
	bool operator== (const Vector& v_2);
};

#endif

