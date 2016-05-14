#include "vector.h"

Vector :: Vector(int new_size)
{
	if(new_size < 1)
	{
		size = 0; 
		fields = NULL;
	}
	else
	{
		fields = new int[new_size];
		if(fields == NULL)
		{
			size = 0;
			throw bad_alloc();
		}	
		size = new_size;
		for(int i=0; i<size; i++)
			fields[i]=0;
	}
}

Vector :: Vector(const Vector& source)
{
	if(source.size < 1)
	{
		size = 0;
		fields = NULL;
	}
	else
	{
		fields = new int[source.size];
		if(fields == NULL)
		{
			size = 0;
			throw bad_alloc();
		}
		size = source.size;
		for (int i=0; i<size; i++)
			fields[i] = source.fields[i];
	}
}

Vector :: ~Vector()
{
	delete[] fields;
}	























