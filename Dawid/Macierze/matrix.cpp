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
			*result.vecs[i] = *(vecs[i]) - *(a.vecs[i]);
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
Matrix& Matrix::operator* (const Matrix& a)
	{
	static Matrix result = Matrix();

	result.row = 0;
	result.col = 0;
	result.~Matrix();
	
	if(this->col == a.row)
		{
		result.vecs = new Wektor*[a.col];
		if(result.vecs == NULL)
			throw bad_alloc();
		
		for(int i = 0 ; i < a.col ; i++)
			{			
			result.vecs[i] = new Wektor(this->col);
			if (result.vecs[i] == NULL)
				throw bad_alloc();
			
			for(int j = 0 ; j < this->col ; j++)
				{
				for(int k = 0 ; k < this->col ; k++)
					{

					(*(result.vecs[i])).setVal(k, (*(this->vecs[k]))[j] * (*(a.vecs[k]))[i] + (*(result.vecs[i]))[k]);
					}
				}

			}
		result.row = this->row;
		result.col = a.col;
		}
	return result;

	}
Matrix& Matrix::operator+= (const Matrix& a)
	{
	*this = *this + a;
	return *this;
	}
Matrix& Matrix::operator-= (const Matrix& a)
	{
	*this = *this - a;
	return *this;
	}

Matrix& Matrix::operator*= (const Matrix& a)
	{
	*this = *this * a;
	return *this;
	}
Matrix& Matrix::operator*= (const int& a)
	{
	*this = *this * a;
	return *this;
	}

bool Matrix::operator== (const Matrix& a)
	{
	if(this->col != a.col || this->row != a.row)
		return false;
	else
		{
		for(int i = 0 ; i < this->col ; i++)
			{
			if(*(this->vecs[i]) != *(a.vecs[i]))
				return false;
			}
		return true;
		}
	}
bool Matrix::operator!= (const Matrix& a)
	{
	if(*this == a)
		return false;
	else
		return true;
	}

int Matrix::operator() (const int i, const int j)
	{
	if(i < this->col && j < this->row && i >= 0 && j >= 0 )
		return (*(this->vecs[i]))[j];
	else
		throw out_of_range("Out of range call");
	}
istream& operator>>(istream& in, Matrix& m)
	{
	if(m.col < 1 || m.row < 1)
		{
		cout << "Empty matrix, assigment impossible";
		return in;
		}
	else
		{
		int a;
		for (int i = 0 ; i < m.col; i++)
			{
			for(int j = 0; j < m.row ; j++)
				{
				cout <<endl << "Col: " <<i << "Row: " << j << " ";
				cin >> a;
				m.setVal(i, j, a);
				}
			}
		}
	}

void Matrix::setVal(int c, int r, int v)
	{
	if( c < col && c >=0 && r <row && r >=0)
		vecs[c]->setVal(r, v);
	}

Matrix& operator* (const int a, const Matrix& m)
	{
	static Matrix result;
	result = m;
	result*= a;
	return result;
	}  






