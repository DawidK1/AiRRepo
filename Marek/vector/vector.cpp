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

Vector Vector :: operator+ (const Vector& add)
{
	int max_size;
	if(size >= add.size)
		max_size = size;
	else
		max_size = add.size;
	
	Vector sum(max_size); //tworze nowy wektor, ktory bedzie suma pozostalych
	for(int i = 0; i < max_size; i++)
	{
		if(i < size)
			sum.fields[i] += fields[i];
		if(i < add.size)
			sum.fields[i] += add.fields[i];
	}
	return sum;
}

Vector Vector :: operator- (const Vector& sub)
{
	if(sub.size == 0 || sub.fields == NULL) //odejmujemy zero / pusty wektor
		return *this;
	if(size == 0 || fields == NULL) //odejmujemy od zera / od pustego wektora
	{
		Vector opposed(sub.size);
		for(int i = 0; i < size; i++)
		{
			opposed.fields[i] = -sub.fields[i];
		}
		return opposed;
	}
	
	int max_size;
	if(size >= sub.size)
		max_size = size;
	else
		max_size = sub.size;
		
	Vector diff(max_size);
	for(int i = 0; i < max_size; i++)
	{
		if(i < size)
			diff.fields[i] += fields[i];
		if(i < sub.size)
			diff.fields[i] -= sub.fields[i];
	}
	return diff;
}

Vector Vector :: operator* (const int& mult)
{
	if(size < 1 || fields == NULL)
		return *this;
	Vector result(size);
	for(int i = 0; i < size; i++)
	{
		result.fields[i] = fields[i] * mult;
	}
	return result;
}

Vector operator* (const int& mult, const Vector& source)
{
	if(source.size < 1 || source.fields == NULL)
		return source;
	Vector result(source.size);
	for(int i = 0; i < source.size; i++)
	{
		result.fields[i] = source.fields[i] * mult;
	}
	return result;
}

Vector Vector :: operator += (const Vector& add)
{
	if(size < 1 || fields == NULL)
		return add;
	else if(add.size == 0 || add.fields == NULL) return *this;
	else
	{
		int max_size;
		if(size >= add.size)
			max_size = size;
		else
			max_size = add.size;
		
		Vector temp(max_size);
		for(int i = 0; i < temp.size; i++)
		{
			if(i < size)
				temp.fields[i] += fields[i];
			if(i < add.size)
				temp.fields[i] += add.fields[i];
		}
		delete[] fields;
		size = max_size;
		fields = new int[size];
		if(fields == NULL)
		{
			size = 0;
			throw bad_alloc();
		}
		for(int i = 0;i < size; i++)
		{
			fields[i] = temp.fields[i];
		}
	}
	return *this;
}

Vector Vector :: operator-= (const Vector& sub)
{
	/*if(size <= 1 || fields == NULL)
	{
		for(int i = 0;i < sub.size; i++)
			sub.fields[i] = -sub.fields[i];
		return sub;
	}
	else if(sub.size == 0 || sub.fields == NULL) return *this;
	else
	{*/
		int max_size;
		if(size >= sub.size)
			max_size = size;
		else
			max_size = sub.size;
		
		Vector temp(max_size);
		for(int i = 0; i < temp.size; i++)
		{
			if(i < size)
				temp.fields[i] += fields[i];
			if(i < sub.size)
				temp.fields[i] -= sub.fields[i];
		}
		delete[] fields;
		size = max_size;
		fields = new int[size];
		if(fields == NULL)
		{
			size = 0;
			throw bad_alloc();
		}
		for(int i = 0;i < size; i++)
		{
			fields[i] = temp.fields[i];
		}
	
	return *this;
}

Vector Vector :: operator*= (const int& mult)
{
	if(size == 0 || fields == NULL)	
		return *this;
	else
	{
		for(int i = 0;i < size; i++)
			fields[i] = mult*fields[i];
	}
	return *this;
}

bool Vector :: operator!= (const Vector& v_2)
{
	if(size == v_2.size)
	{
		for(int i = 0;i < size; i++)
		{
			if(fields[i] == v_2.fields[i])
				return false;
		}
		return true;
	}
	if(size < 1 && v_2.size < 1)
		return false; //jezeli oba wektory maja rozmiar mniejszy od 1 to przyjmuje, ze sa rowne
	return true;
}

bool Vector :: operator== (const Vector& v_2)
{
	if(size < 1 && v_2.size < 1)
		return true;
	if(size != v_2.size)
		return false;
	else
	{
		for(int i = 0;i < size; i++)
		{
			if(fields[i] == v_2.fields[i])
				return true;
		}
	}
	return false;
}
















