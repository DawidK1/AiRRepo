#ifndef _MATRIX_H_
#define _MATRIX_H_
#include <iostream>
#include "wektor.h"

class Matrix{
	
	
	private:
	Wektor* vecs;
	int row;
	int col;

	public:	
	Matrix();
	Matrix(int r, int c);
	Matrix(const Matrix& src);
	void setVal(int r, int c, int v);

	~Matrix();
	friend ostream& operator<<(ostream& out, const Matrix& m);
	Matrix operator+ (const Matrix& a) const;





	};













#endif