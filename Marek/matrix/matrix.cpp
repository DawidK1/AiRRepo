#include "matrix.h"

Matrix :: Matrix(int input_vector_size, int input_rows)
{
	if(input_vector_size < 1 || input_rows < 1)
	{
		vectors = NULL;
		rows = 0;
		vector_size = 0;
		return;
	}
	
	vectors = new Vector[input_vector_size];
	if(vectors == NULL)
	{
		rows = 0;
		vector_size = 0;
		throw bad_alloc();
	}
	
	rows = input_rows;
	vector_size = input_vector_size;
	for (int i = 0;i < rows; i++)
	{
		vectors[i] = Vector(vector_size);
	}
}
