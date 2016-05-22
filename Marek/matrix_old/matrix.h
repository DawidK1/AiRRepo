#ifndef MATRIX
#define MATRIX

#include "vector.h"

class Matrix
{
private:
	int rows;
	int vector_size; //vector_size odpowiada liczbie kolumn macierzy
	Vector** vectors;

public:
	Matrix(int input_vector_size = 2, int input_rows = 2);
	Matrix(const Matrix& source);
	~Matrix();
	
	friend ostream& operator<< (ostream& out, const Matrix& matrix_out);
	friend istream& operator>> (istream& in, const Matrix& matrix_in);
	
	Matrix& operator= (const Matrix& source);
	Matrix operator+ (const Matrix& add);
	Matrix operator- (const Matrix& sub);
	Matrix operator* (const int& mult);
	friend Matrix operator* (const int& mult, const Matrix& source);
};

#endif