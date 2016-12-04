#ifndef ITERATOR
#define ITERATOR
#include "toy.h"
#include "shop.h"
using namespace std;

template <class Type>
class iter
{
	Type* ptr;
	int p;
public:
	iter(vector<Type>& container);
	void operator++();
	void operator--();
	void operator+(int a);
	void operator-(int a);
	Type operator*();
	void operator=(const iter<Type>& a);
	void operator=(int a);
	int operator>(int a);
	int operator<(int a);
	int operator>=(int a);
	int operator<=(int a);
};


template<class Type>
iter<Type>::iter(vector<Type>& container)
{
	p =0;
	ptr = container.head;

}


template<class Type>
void iter<Type>::operator++()
{
	++p;
	return;
}



template<class Type>
void iter<Type>::operator--()
{
	if(p>0)
	{
		p--;
	}
	else
	{
	cout<<"Bład"<<endl;
	}
	return;
}


template<class Type>
void iter<Type>::operator+(int a)
{
	p = p + a;
	return;
}



template<class Type>
void iter<Type>::operator-(int a)
{
	if(p>a)
	{
		p=p-a;
	}
	else
	{
	cout<<"Bład"<<endl;
	}
	return;
}

template<class Type>
Type iter<Type>::operator*()
{
	
	return ptr[p];
	
}




template<class Type>
void iter<Type>::operator=(const iter<Type>& a)
{
	ptr = a.ptr;
	p = a.p;
	return;
}



template<class Type>
void iter<Type>::operator=(int a)
{
	p = a;
	return;
}


template<class Type>
int iter<Type>::operator>(int a)
{
	if(p>a)
	{
		return 1;
	}
	else
	{
		return 0;
	}
}


template<class Type>
int iter<Type>::operator<(int a)
{
	if(p<a)
	{
		return 1;
	}
	else
	{
		return 0;
	}
}

template<class Type>
int iter<Type>::operator>=(int a)
{
	if(p>=a)
	{
		return 1;
	}
	else
	{
		return 0;
	}
}

template<class Type>
int iter<Type>::operator<=(int a)
{
	if(p<=a)
	{
		return 1;
	}
	else
	{
		return 0;
	}
}


#endif
