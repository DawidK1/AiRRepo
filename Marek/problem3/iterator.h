#ifndef ITERATOR_H_
#define ITERATOR_H_

#include <iostream>

using namespace std;

template<typename T, typename obj_t>
class Iterator 
{
private:
    T& _container;
    int _pos;

public:
    bool inrange()
    {
        if( (_pos >= 0) & (_pos <= _container._actural_size))
            return true;
        else
            return false;
    }

    Iterator(T& container): _container(container), _pos(0){}
    Iterator(T& container, int position): _container(container), _pos(position)
    {
        if(!inrange())
            cerr << "Out of range!";
    }

    obj_T* operator* ()
    {
        if( (_pos >= 0) & (_pos < _container.actual_size))
            return _container._tab[_pos];
        else
        {
            cerr << "Out of position!";
            return _container._tab[0];
        }
    }

    bool operator == (const Iterator& i2)
    {
        if( &_container != &i2._container) | (_pos != i2._pos)
            return false;
        else
            return true;
    }

    bool operator != (const Iterator& i2)
    {
        return !(*this == i2);
    }
}