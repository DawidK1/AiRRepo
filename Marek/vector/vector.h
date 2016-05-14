#ifndef VECTOR
#define VECTOR

#include <iostream>

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
};

#endif

