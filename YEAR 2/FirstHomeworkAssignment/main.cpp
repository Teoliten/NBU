#include <iostream>

using namespace std;
//--------Throw---------
class VectorFull : public runtime_error
{
public:
  VectorFull(const string &msg) : runtime_error(msg) 
  {
  }
};//VectorFull

class VectorEmpty : public runtime_error
{
public:
  VectorEmpty(const string &msg) : runtime_error(msg) 
  {
  }
};//VectorEmpty
//--------Throw---------

//--------Vector--------
template <typename E>
class Vector
{
public:
    Vector();
    ~Vector();
    E at(int indx);
    void set(int indx, E elmt);
    void insert(int indx, E elmt);
    void erase(int indx);
    void resize(int cpct);
    void print();
    int size();
    bool isEmpty();
private:
    enum {CPCT = 256};
    E arr[CPCT];
    int numb;
};//Vector

template <typename E>
Vector<E>::Vector()//Default constructor
{
    E arr[CPCT];
    numb = 0;
};//Vector

template <typename E>
Vector<E>::~Vector()
{
  if (arr)
  {
    cout << "Destructor" << endl;
    delete[] ptr_arr;
    arr = nullptr;
  }
}//~Vector

template <typename E>
E Vector<E>::at(int indx)
{

}//at

template <typename E>
void Vector<E>::set(int indx, E elmt)
{
    arr[indx] = elmt;//when to increase numb or not :/
}//set

template <typename E>
void Vector<E>::insert(int indx, E elmt)
{
    if (indx < 0 || indx > elmt)
    {
        throw out_of_range("...");
    }

    if (elmt >= CPCT)
    {
        resize(max(1, CPCT << 1));
    }

    for (int i = elmt - 1; i >= indx; i--)
    {
        arr[i + 1] = arr[i];
    }
    
    arr[indx] = elmt;
    numb++;
}//insert

template <typename E>
void Vector<E>::erase(int indx)
{

}//erase

template <typename E>
void Vector<E>::resize(int cpct)
{

}//rezise

template <typename E>
void Vector<E>::print()
{
    if(isEmpty())
    {
        throw VectorEmpty("Print_err: Vector is empty!");
    }
    //shouldnt be greater than cpct. schte go vidime
    cout << "Vector: ";
    for(int i = 0; i < numb; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
}//print

template <typename E>
int Vector<E>::size()
{
    return numb;
}//size

template <typename E>
bool Vector<E>::isEmpty()
{
    return (size() == 0);
}//isEmpty
//--------Vector--------

//-------Iterator-------
template <typename E>
class Iterator
{
public:

private:

friend class Vector<E>;//Vector is a friend class of Iterator.
};
//-------Iterator-------

//---------Main---------
int main()
{
    Vector<int> vctr;

    vctr.insert(0, 42);//insert integer '42' at index '0'.
    vctr.insert(1, 11);//insert integer '1' at index '1'.
    vctr.insert(0, 5);//insert integer '5' at index '0', "pushing" the two other elements to the right.

    vctr.print();//printing vector

    return 0;
}//main
//---------Main---------