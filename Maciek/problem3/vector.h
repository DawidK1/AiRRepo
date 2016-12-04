#ifndef VECTOR
#define VECTOR
#include "toy.h"
using namespace std;

template <class Type>
class iter;

template <class Type>
class vector
{
	friend class iter <Type>;
	Type * head;
	int length;                 //dlugosc
	int capacity;               //wypelnienie
public:
	vector();
	vector(int leng);
	vector(const vector<Type> &copy);
	~vector();
	void add(Type el);
	void remove(int place);
	void change_length();
	void clear();
	int size();
	int position();
	vector operator + (const vector &b);
	void operator = (const vector &b);
	int operator == (const vector &b);
	int operator != (const vector &b);
	Type operator [] (int place);

};

template <class Type>                               //dziala
vector<Type>::vector()
{
	head = NULL;
	length = 0;
	capacity = 0;
}



template <class Type>                             //dziala
vector<Type>::vector(int leng)
{
	length = leng;
	capacity = 0;
	head = new Type[length];
}



template <class Type>                             //dziala 
vector<Type>::vector(const vector<Type> &copy)
{
	length = copy.length;
	head = new Type[copy.length];
	capacity = copy.capacity;   
	int i;
	for(i = 0; i < capacity; i++) 
	{
		head[i] = copy.head[i];
	}
}



template <class Type>                       //dziala
vector<Type>::~vector ()
{
	delete[] head;
	capacity = 0;
	length = 0;
	head = NULL;
}



template <class Type>                        //dziala
void vector<Type>::add(Type el)
{
	change_length();
	int i;
	head[capacity] = el; 
	capacity++;
	return;
}



template <class Type>                            //dziala
void vector<Type>::remove(int place)
{
	int i;
	for(i = place; i<=length; i++)
	{
		head[i] = head[i+1];
	}
	capacity--;
	return;
}



template <class Type>                             //dziala
void vector<Type>::change_length()
{
	int i;
	if(capacity + 5 < length)
	{
		Type * indic;
		indic = new Type[length-5];
		for(i=0;i<capacity;i++)
		{
			indic[i] = head[i];
		}
		delete[] head;
		head = indic;
		length = length-5;
		return;
	}
	else
	{
		Type * indic;
		indic = new Type[length+5];
		for(i=0;i<capacity;i++)
		{
			indic[i] = head[i];
		}
		delete[] head;
		head = indic;
		length = length+5;
		return;
	}
}



template <class Type>                           //dziala
void vector<Type>::clear()
{
	delete[] head;
	head = NULL;
	length = 0;
	capacity = 0;
	return;
}



template <class Type>                      //dziala
int vector<Type>::size()
{
	return length;
}


template <class Type>                       //dziala
int vector<Type>::position()
{
  return capacity;
}



template <class Type>                                       //dziala
vector<Type> vector<Type>::operator + (const vector &b)
{
	vector c(length + b.length);
	int i;
	for(i = 0; i<capacity; i++)
	{
		c.add(head[i]);
	}
	for(i = 0; i < b.capacity; i++)
	{
		c.add(b.head[i]);
	}
	c.length = length+b.length;
	c.capacity = capacity + b.capacity;
	return c;
}



template <class Type>                                     //dziala
void vector<Type>::operator = (const vector& b)
{
	while(b.capacity > length)
	{
		change_length();
	}
	int i;
	for(i = 0; i<b.capacity; i++)
	{
		head[i] = b.head[i];
	}
	capacity = b.capacity;
	return;
}




template <class Type>                                  //dziala
int vector<Type>::operator == (const vector& b)
{
	int i;
	if(length != b.length)
	{
		return 0;
	}
	for(i = 0; i < capacity; i++)
	{
		if(head[i] != b.head[i])
		{
			return 0;
		}
	}
	return 1;
}



template <class Type>                                 //dziala
int vector<Type>::operator != (const vector& b)
{
	int i;
	if(length != b.length)
	{
		return 1;
	}
	for(i = 0; i < capacity; i++)
	{
		if(head[i] != b.head[i])
		{
			return 1;
		}
	}
	return 0;
}



template <class Type>                                //dziala
Type vector<Type>::operator [](int place)
{
	return head[place];
}

#endif
