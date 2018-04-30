# ifndef ARRAYLIST_H
# define ARRAYLIST_H

template <typename T>
class ArrayList
{
public:
    ArrayList();

    // Copy constructor
    ArrayList(const ArrayList<T>& c);

    // Move constructor
    ArrayList (ArrayList<T>&& c) ;

/*
* Constructor with initialization of " initialized "
elements
*/
    ArrayList(int initialized);

    virtual ~ ArrayList() ;

/*
* Copy assignment operator
*/
    ArrayList<T>& operator =(const ArrayList<T>& a);

/*
* Move assignment operator
*/
    ArrayList<T>& operator =(ArrayList<T>&& a);


/*
* Add element to dynamic array
*/
    void add (const T& element)
    {
        if (_size == _reserved)
            extendStorage() ;

        _elems [_size] = element;
        ++ _size ;
    }

/*
* Inserts the element at placement " idx " in array and moves the remaining
* items by one place , restoring the old element at " idx".
* check whether it is needed to extend the storage .
* move all elements from _size to idx ( reverse ) one element to the right in the array
* set _elems [ idx ] equal to the element to be inserted
*/
    void add(int idx, const T& element);
/*
* Get a const reference to the element at idx
*/
    T &operator [](int idx) const;

/*
* Get a reference to the element at idx
*/
    T &operator [](int idx);

/*
* Removes the element at placement " idx " by moving all the remaining elements
* by one place to the left in the array
*/
    void remove(int idx);

/*
* Returns the number of elements stored
*/
    int size() const;
/*
* Returns the number of items currently reserved in memory
*/
    int reserved() const;

/*
* Returns true if number of elements in array is zero
*/
    bool isEmpty() const;

/*
* Trims the storage array to the exact number of elements
* stored .
*/
    void trimToSize();

/*
* Sorts the array using insertion sort (or another algorithm )
*/
    void sort();

/*
* Returns a new ArrayList with elements from " fromIdx " index to " toIdx "
*/
    ArrayList<T> subArrayList(int fromIdx, int toIdx) const;

/*
* Returns a new C++ style array ( copy created with new ) with all elements
*/
    T* toArray();

private:
/*
* extendStorage ():
* create new array with size 2* _reserved
* copy old data to the new array
* delete old array
* update pointer _elems to point to the new array
* ( Since this method is private , the method will only be used internally ,
* but the functionality is needed ).
*/
    void extendStorage();

/*
* Member variables
*/
    int _reserved ; // The current capacity of " _elems " array
    int _size ; // The number of elements stored
    T* _elems ; // Array for storing the elements
};

// Copy constructor
template<class T>
ArrayList<T>::ArrayList(const ArrayList<T>& c)
{
    _size = c._size;

    _elems = new T[_size];

    for (int i = 0; i < _size; ++i)
    {
        _elems[i] = c._elems[i];
    }
}

// Move constructor
template<class T>
ArrayList<T>::ArrayList(ArrayList<T> &&c)
{
    _size = c._size;
    _elems = c._elems;
    c._size = 0;
    c._elems = nullptr;
}

// Constructor with initialization of " initialized " elements
template<class T>
ArrayList<T>::ArrayList(int initialized)
{
    _size = initialized;
    _elems = new T[_size];
}

// Copy assignment operator
template<class T>
ArrayList<T>& ArrayList<T>::operator =(const ArrayList<T>& a)
{
    delete [] _elems;

    _size = a._size;
    _elems = new T[_size];

    for (int i = 0; i < _size; ++i)
    {
        _elems[i] = a._elems[i];
    }

    return *this;
}

// Move assignment operator
template<class T>
ArrayList<T>& ArrayList<T>::operator =(ArrayList<T>&& a)
{
    T* tempElems = _elems;
    int tempSize = _size;

    _elems = a._elems;
    _size = a._size;

    a._size = tempSize;
    a._elems = tempElems;

    return *this;
}

// Get a const reference to the element at idx
template<class T>
T& ArrayList<T>::operator [](int idx) const
{
    return _elems[idx];
}

// Get a reference to the element at idx
template<class T>
T& ArrayList<T>::operator [](int idx)
{
    return _elems[idx];
}

// Returns the number of elements stored
template<class T>
int ArrayList<T>::size() const
{
    return _size;
}

// Returns the number of items currently reserved in memory
template<class T>
int ArrayList<T>::reserved() const
{
    return _reserved;
}

// Returns true if number of elements in array is zero
template<class T>
bool ArrayList<T>::isEmpty() const
{
    if(_elems = 0)
    {
        return true;
    }
    else
    {
        return false;
    }
}

/*
* Sorts the array using insertion sort (or another algorithm )
*/
template<class T>
void ArrayList<T>::sort(){

       for(int i = 1; i < _size; ++i)
       {
          int index = _elems[i]; int j = i;
          while (j > 0 && _elems[j-1] > index)
          {
               _elems[j] = _elems[j-1];
               j--;
          }
          _elems[j] = index;
    } }

// Removes the element at placement " idx " by moving all the remaining elements by one place to the left in the array
template<class T>
void ArrayList<T>::remove(int idx)
{
    ArrayList<T> tempArray(_size-1);

    for(int i = 0;i <= _size;++i)
    {
        tempArray._elems[i] = _elems[i];
    }
    _reserved = _size;
}

// Returns a new ArrayList with elements from " fromIdx " index to " toIdx "
template<class T>
ArrayList<T> ArrayList<T>::subArrayList(int fromIdx, int toIdx) const
{
    ArrayList<T> resArray(fromIdx-toIdx);
    int j = 0;
    for (int i = fromIdx;i < toIdx;++i)
    {
        resArray._elems[j] = _elems[i];
        j++;
    }
    return resArray;
}











# endif // ARRAYLIST_H


