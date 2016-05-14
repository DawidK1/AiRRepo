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
};

#endif

