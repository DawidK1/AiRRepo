#include <iostream>
#include "wektor.h"
#include "matrix.h"

int main()
	{
	Matrix m1 = Matrix(3,3);
	Matrix m2 = Matrix(3,3);
	
	for(int i = 0 ;i < 3 ; i++)
		{
		for(int j = 0 ; j < 3 ; j++)
			{
			m1.setVal(i, j, i + j + 3);
			m2.setVal(i, j, i - j -5);
			}
		}
	m1 + m2;
	cout << "aa";
	cout <<  m1 + m2;
	}