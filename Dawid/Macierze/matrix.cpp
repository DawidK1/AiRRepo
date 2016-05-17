#include "matrix.h"

Matrix :: Matrix()
	{
	vecs = new Wektor[2];
	vecs[0] = Wektor(2);
	vecs[1] = Wektor(2);
	row = 2;
	col = 2;
	}
Matrix :: Matrix(int r, int c)
	{
	if(r < 1 || c < 1)
		{
		row = 0;
		col = 0;
		vecs = NULL;
		}
	else
		{
		row = r;
		col = c;
		
		vecs = new Wektor[col];
		if(vecs == NULL) throw bad_alloc();
		for(int i = 0 ; i < col ; i++)
			vecs[i] = Wektor(row);
		
		}
	}
Matrix :: Matrix( const Matrix& src)
	{
	row = src.row;
	col = src.col;
	vecs = new Wektor[col];
	for(int i = 0; i < col ; i++)
		vecs[i] = src.vecs[i];
		
	}
Matrix :: ~Matrix()
	{
	for(int i = 0 ; i < col ; i++)
		vecs[i].~Wektor();
	delete [] vecs;
	}




Matrix Matrix :: operator+ (const Matrix& a) const
	{
	static Matrix temp;
	//temp.~Matrix();

	if(col == a.col && row == a.row)
		{

		temp = Matrix(row, col);
		for(int i = 0 ; i < col ; i++)
			temp.vecs[i] = a.vecs[i] + vecs[i];

		}
	else
		temp = Matrix( 0, 0);
	cout << temp;
	return temp;

	}
ostream& operator<<(ostream& out, const Matrix& m)
	{
	if(m.col == 0)
		{
		cout << "Incorrect matrix!";
		return out;
		}
	cout << "---------------------------"<< endl;
	for(int i = 0 ; i < m.col ; i++)
		{
		for(int j = 0 ; j < m.row ; j++)
			cout << m.vecs[i][j] << "\t";
		cout << endl;
		}
	cout << "---------------------------"<< endl;
	return out;
	}
void Matrix::setVal(int c, int r, int v)
	{
	if( c < col && c >=0 && r <row && r >=0)
		vecs[c].setVal(r, v);
	}








