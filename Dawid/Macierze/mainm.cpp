#include <iostream>
#include "wektor.h"
#include "matrix.h"

int main() 
	{

  

	Matrix m1 = Matrix(3,3);
	Matrix m2 = Matrix(3,3);
	Matrix m3;
	for(int i = 0 ;i < 3 ; i++)
		{
		for(int j = 0 ; j < 3 ; j++)
			{ 
			m1.setVal(i, j, i + j + 3);
			m2.setVal(i, j, i - j -5);
			}
		}

	cout <<  m1 + m2;
	cout << m1 - m2;
	cout << m1;
	m3 = m1;	
	cout << m3 * 5;
	cout << m1 * m2;
	m3 += m1;
	cout << m3;
	m3-= m1;
	cout << m3;
	cout << (m1==m1);
	cout << (m1!=m2);
	cout << m1(0,0);
	}
