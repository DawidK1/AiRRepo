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

ostream& operator << (ostream& out, const Vector& v_out)
{
	if(v_out.size != 0 && v_out.fields != NULL)
	{
		out << "[";
		for(int i=0; i<v_out.size - 1; i++)
		{
			cout << setw(3) << v_out.fields[i] << ",";
		}
		out << setw(3) << v_out.fields[v_out.size - 1] << "]" << endl;
	}
	return out;
}

istream& operator >> (istream& in, const Vector& v_in)
{
	if(v_in.size >= 1 && v_in.fields != NULL)
	{
		for(int i=0; i<v_in.size; i++)
		{
			in >> v_in.fields[i];
		}
	}
	return in;
}

Vector& Vector :: operator= (const Vector& source)
{
	if(this == &source)
		return *this;
	if(source.size < 1 || source.fields == NULL)
	{
		delete[] fields;
		fields = NULL;
		size = 0;
	}
	else
	{
		if(size == source.size)
		{
			for(int i = 0; i < size; i++)
			{
				fields[i] = source.fields[i];
			}
		}
		else
		{
			delete[] fields;
			fields = new int[source.size];
			if(fields == NULL)
			{
				size =0;
				throw bad_alloc();
			}
			else
			{
				size = source.size;
				for(int i = 0; i < size; i++)
					fields[i] = source.fields[i];
			}
		}
	}
	return *this;
}






















