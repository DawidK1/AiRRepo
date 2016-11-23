 #ifndef MYVECTOR_H
 #define MYVECTOR_H
 #include <iostream>
 
template <typename T>
class Vector{
private:
    T* _tab;
    int _actual_size;
    int _max_size;

public:
    Vector(int max_size= 10);
    Vector(const Vector<T>& src);

    void resize(int add=10);
    void push_back(const T& new_el);
    void pop_back();
    void insert(const T& new_el, int position);
    void erase(int position);
    void clear();

    bool isempty() const;
    bool isfull() const;
    int max_size() const;
    int current_size() const;
    
    T& operator[](int pos) const;
    Vector<T>& operator= (const Vector<T>& source);


    ~Vector(){
            delete[] _tab;
    }
};
///////////////////////////////////////////////////////////

template <typename T> Vector<T>::Vector(int max_size){
    if(max_size < 0){
        max_size = 10;
    }

    _tab = new T[max_size];
    _max_size = max_size;
}

template <typename T> Vector<T>::Vector(const Vector<T>& src){
    
    _max_size = src._max_size;
    _tab = new T[_max_size];
    for(int i = 0; i < _max_size; i++)
        _tab[i] = src._tab[i];
}
template <typename T> 
void Vector<T>::resize(int add){
    _max_size += add;
    T* tmp;
    tmp = _tab;
    _tab = new T[_max_size];

    for(int i = 0 ; i < _max_size - add; i++)
        _tab[i] = tmp[i];
    
    delete [] tmp;
}
template <typename T> 
void Vector<T>::clear(){
    delete[] _tab;
    _tab = NULL;
    _max_size = 0;
    _actual_size = 0;
}
template <typename T> 
void Vector<T>::insert(const T& new_el, int position){
    _actual_size++;
    if(position > _actual_size)
        position = _actual_size;
        
    if(_actual_size >= _max_size)
        resize();


    T temp1 = new_el;
    T temp2;
    for(int i = position;  i < _actual_size; i++){
        temp2 = _tab[i];
         _tab[i] = temp1;
         temp1 = temp2;
    }

}
template <typename T> 
void Vector<T>::push_back(const T& new_el){
    insert(new_el , _actual_size);
}
template <typename T> 
void Vector<T>::erase(int position){
    if(position < 0 || position >= _actual_size)
        return;

    for(int i = position;  i < _actual_size; i++)
        _tab[i] = _tab[ i + 1 ];

    _actual_size--;
}
template <typename T> 
void Vector<T>::pop_back(){
    erase(_actual_size -1);
}
template <typename T> 
inline bool Vector<T>::isfull() const {
    if(max_size == _actual_size)
        return true;
    else return false;
}
template <typename T> 
inline bool Vector<T>::isempty() const{
    return !(_actual_size);
}

template <typename T>
int Vector<T>::current_size() const{
    return _actual_size;
}

template <typename T>
int Vector<T>::max_size() const{
    return _max_size;
}
/////////////////////////////////////////////////
//Operatory
template <typename T>
T& Vector<T>::operator[](int pos) const {
    if((pos >= _actual_size ) | (pos < 0 ))
       return _tab[0];// cerr << "Out of range!\n";
    else
        return _tab[pos];
}
template <typename T>
Vector<T>& Vector<T>::operator= (const Vector<T>& source){

    if(!(this == &source)){
        if(_tab!= NULL)
            delete [] _tab;
        
        _actual_size =  source._actual_size;
        _max_size = source._max_size;

        _tab  = new T[_max_size];
        for(int i = 0 ; i < _actual_size; i++){
            _tab[i] = source._tab[i];
        }
    }
    return *this;
}

#endif