#ifndef _MATRIX_H_
#define _MATRIX_H_
#include <iostream>
#include "wektor.h"

class Matrix{
	
	
	private:
	Wektor** vecs;
	int row;
	int col;
  
	public:	  
	Matrix();
	Matrix(int r, int c);
	Matrix(const Matrix& src);
	void setVal(int r, int c, int v);

	~Matrix();
	friend ostream& operator<<(ostream& out, const Matrix& m);
	friend istream& operator>>(istream& in, Matrix& m);
		
	 
	Matrix& operator= (const Matrix& src);
	Matrix& operator+ (const Matrix& a);
	Matrix& operator- (const Matrix& a);
	Matrix& operator* (const int a) ;
	Matrix& operator* (const Matrix& a);
	Matrix& operator+= (const Matrix& a);
	Matrix& operator-= (const Matrix& a);
	Matrix& operator*= (const Matrix& a);
	Matrix& operator*= (const int& a);
	
	bool operator== (const Matrix& a);
	bool operator!= (const Matrix& a);
	int operator() (const int i, const int j);

	friend Matrix& operator* (const int a,const Matrix& m);
	};













#endif
