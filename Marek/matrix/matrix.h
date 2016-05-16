#ifndef MATRIX
#define MATRIX

#include "vector.h"

class Matrix
{
private:
	int rows;
	int vector_size; //vector_size odpowiada liczbie kolumn macierzy
	Vector* vectors;

public:
	Matrix(int input_vector_size = 2, int input_rows = 2);
};

#endif
