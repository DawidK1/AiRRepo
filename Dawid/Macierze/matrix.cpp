#include "matrix.h"

Matrix :: Matrix()
	{
	vecs = new Wektor*[2];
	vecs[0] =new  Wektor();
	vecs[1] =new  Wektor();
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
		
		vecs = new Wektor*[col];
		if(vecs == NULL) throw bad_alloc();
		for(int i = 0 ; i < col ; i++)
			vecs[i] = new Wektor(row);
		
		}
	}
Matrix :: Matrix( const Matrix& src)
	{
	row = src.row;
	col = src.col;
	vecs = new Wektor*[col];
	for(int i = 0; i < col ; i++)
		*vecs[i] = *src.vecs[i];
		
	}
Matrix :: ~Matrix()
	{

	if(vecs != NULL)
		{
		for(int i = 0 ; i < col ; i++)
			{
			vecs[i]->~Wektor();
			delete vecs[i];
			}
		delete[] vecs;
		}
	}


Matrix& Matrix::operator= (const Matrix& src)
	{
	this->~Matrix();
	
	this->vecs = new Wektor*[src.col];
	if(this->vecs == NULL)
		throw bad_alloc();

	for(int i = 0 ; i < src.col ; i++)
		{
		this->vecs[i] = new Wektor(src.row);
		if(this->vecs[i] == NULL)
			throw bad_alloc();

		*(this->vecs[i]) = *(src.vecs[i]);
		
		}
		this->row = src.row;
		this->col = src.col;
	return *this;
	}

Matrix& Matrix::operator+ (const Matrix& a)
	{
	static Matrix result = Matrix();
	result.row = 0;
	result.col = 0;
	result.~Matrix();

	if(a.col == col && a.row == row)
		{
		result.row = row;
		result.col = col;
		result.vecs = new Wektor*[this->row];
		for(int i = 0; i < result.col ; i++)
			{
			result.vecs[i] = new Wektor(row);
			*result.vecs[i] = *(a.vecs[i]) + *(vecs[i]);
			}
		}
	return result;
	}
Matrix& Matrix::operator- (const Matrix& a)
	{
	static Matrix result = Matrix();

	result.row = 0;
	result.col = 0;
	result.~Matrix();

	if(a.col == col && a.row == row)
		{
		result.row = row;
		result.col = col;
		result.vecs = new Wektor*[this->row];
		for(int i = 0; i < result.col ; i++)
			{
			result.vecs[i] = new Wektor(row);
			*result.vecs[i] = *(a.vecs[i]) - *(vecs[i]);
			}
		}
	return result;
	}





ostream& operator<<(ostream& out, const Matrix& m)
	{
	if(m.vecs == NULL)
		{
		cout << "Incorrect matrix!";
		return out;
		}

	   else	{
		cout <<endl << "---------------------------"<< endl;
		for(int i = 0 ; i < m.col ; i++)
			{
			for(int j = 0 ; j < m.row ; j++)
				cout << (*(m.vecs[i]))[j] << "\t";
			cout << endl;
			}
		cout << "---------------------------"<< endl;
		return out;
		}
	}
Matrix& Matrix::operator* (const int a)
	{
	static Matrix result = Matrix();

	result = *this;

	for(int i = 0 ; i <this->col ; i++)
		*(result.vecs[i]) = *(result.vecs[i]) * a;
	return result;
	}





void Matrix::setVal(int c, int r, int v)
	{
	if( c < col && c >=0 && r <row && r >=0)
		vecs[c]->setVal(r, v);
	}








