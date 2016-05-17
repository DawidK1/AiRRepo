#include "matrix.h"

Matrix :: Matrix(int input_vector_size, int input_rows)
{
	vectors = new Vector*[input_vector_size];
	if(vectors == NULL)
	{
		rows = 0;
		vector_size = 0;
		throw bad_alloc();
	} 
	
	for( int i = 0;i < input_vector_size; i++)
	{
		vectors[i] = new Vector(input_vector_size);
		if(vectors[i] == NULL)
		{
			rows = 0;
			vector_size = 0;
			throw bad_alloc();
		}
	}
	vector_size = input_vector_size;
	rows = input_rows;
}

Matrix :: Matrix(const Matrix& source)
{
	if(source.vectors == NULL || source.rows < 1)
	{
		rows = 0;
		vectors = NULL;
		return;
	}
	else
	{
		vectors = new Vector*[source.vector_size];
		if(vectors == NULL)
		{
			rows = 0;
			vector_size = 0;
			throw bad_alloc();
		}
		rows = source.rows;
		vector_size = source.vector_size;
		for(int i = 0;i < rows; i++)
		{
			*vectors[i] = *source.vectors[i];
		}
	}
}

Matrix :: ~Matrix()
{
	delete[] vectors;
	cout << "Jestem destruktorem" << endl;
}

ostream& operator<< (ostream& out, const Matrix& matrix_out)
{
	if(matrix_out.rows < 1 || matrix_out.vectors == NULL)
	{
		cout << "Macierz jest pusta" << endl;
		return out;
	}
	else
	{
		for(int i = 0;i < matrix_out.rows; i++)
		{
			cout << *(matrix_out.vectors)[i] << endl;
		}
		return out;
	}
}

istream& operator>> (istream& in, const Matrix& matrix_in)
{
	if(matrix_in.rows < 1 || matrix_in.vectors == NULL)
	{
		cout << "Macierz jest pusta, nie mam gdzie wpisac danych" << endl;
		return in;
	}
	else
	{
		for(int i = 0; i < matrix_in.rows; i++)
		{
			cin >> *(matrix_in.vectors)[i];
		}
		return in;
	}
}

Matrix& Matrix :: operator= (const Matrix& source)
{
	if(rows == source.rows && vector_size == source.vector_size)
	{
		vectors = new Vector*[source.rows];
		if(vectors == NULL)
		{
			rows = 0;
			vector_size = 0;
			throw bad_alloc();
		}
		for(int i = 0;i < source.rows; i++)
			*(vectors)[i] = *(source.vectors)[i];
		return *this;
	}
	else
		return *this;
	
}
/*
Matrix Matrix :: operator+ (const Matrix& add) 
{
	if(rows == add.rows && vector_size == add.vector_size)
	{
		Matrix sum(vector_size, rows);
		for(int i = 0;i < sum.rows; i++)
		{
			sum.vectors[i] = vectors[i] + add.vectors[i];
		}
		return sum;
	}
	else
		return *this;
}

Matrix Matrix :: operator- (const Matrix& sub) 
{
	if(rows == sub.rows && vector_size == sub.vector_size)
	{
		Matrix diff(vector_size, rows);
		for(int i = 0; i<rows; i++)
		{
			diff.vectors[i] = vectors[i] - sub.vectors[i];
		}
		return diff;
	}
	else
		return *this;
		
	
}

Matrix Matrix :: operator* (const int& mult)
{
	Matrix result(vector_size, rows);
	for(int i = 0;i < rows; i++)
	{
		result.vectors[i] = mult * vectors[i];
	}	
	return result;
}

Matrix operator* (const int& mult, const Matrix& source)
{
	Matrix result(source.vector_size, source.rows);
	for(int i = 0;i < result.rows; i++)
	{
		result.vectors[i] = mult * source.vectors[i];
	}	
	return result;
}


*/























