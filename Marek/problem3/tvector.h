#ifndef TVECTOR_H
#define TVECTOR_H

#include <iostream>

template <typename T>
class Vector{
private:
    T* tab;
    int size;
    int max_size;

public:
    Vector(int msize=5);
    Vector(const Vector<T>& source);

    void resize(int add = 5);
    void insert(const T& inElement, int pos);
    void clear();
    void erase(int pos);
    void push_back(const T& inElement);
    void pop_back();

    T& operator[] (int pos) const;
    Vector<T>& operator= (const Vector<T>& source);

    ~Vector()
    {
        delete[] tab;
    }
};

template <typename T>
Vector<T>::Vector(int msize) : size(0), max_size(msize)
{
    tab = new T[max_size];
}

template <typename T>
Vector<T>::Vector(const Vector<T>& source)
{
    max_size = source.max_size;
    tab = new T[max_size];
    for(int i = 0; i < max_size; i++)
    {
        tab[i] = source.tab[i];
    }
}

template <typename T>
void Vector<T>::resize(int add)
{
    max_size += add;
    T* temp;
    temp = tab;
    tab = new T[max_size];

    for(int i = 0; i < max_size - add; i++)
        tab[i] = temp[i];

    delete [] temp;
}

template <typename T>
void Vector<T>::insert(const T& inElement, int pos)
{
    size++;
    if(pos > size)
        pos = size;
    if(size >= max_size)
        resize();
    
    T* temp = new T[max_size];
    for(int i = 0; i < pos; i++)
        temp[i] = tab[i];
    
    temp[pos] = inElement;

    for(int i = pos + 1; i < size; i++)
        temp[i] = tab[i-1];
}

template <typename T>
void Vector<T>::clear()
{
    delete [] tab;
    tab = NULL;
    max_size = 0;
    size = 0;
}

template <typename T>
void Vector<T>::erase(int pos)
{
    if(pos < 0 || pos >= size)
        return;
    
    for(int i = pos; i < size; i++)
        tab[i] = tab[i+1];
    
    size --;
}

template <typename T>
void Vector<T>::push_back(const T& inElement)
{
    insert(inElement, size);
}

template <typename T>
void Vector<T>::pop_back()
{
    erase(size - 1);
}

template <typename T>
T& Vector<T>::operator[] (int pos) const
{
    if( pos > size || pos < 0)
    {
        std::cout << "blad odczytu, poza rozmiarem";
        return tab[0];
    }
    else
        return tab[pos];
}

template <typename T>
Vector<T>& Vector<T>::operator= (const Vector<T>& source)
{
    if(tab != NULL)
        delete [] tab;
    
    size = source.size;
    max_size = source.max_size;

    tab = new T[max_size];
    for(int i = 0; i < size; i++)
    {
        tab[i] = source.tab[i];
    }
    return *this;
}

#endif 