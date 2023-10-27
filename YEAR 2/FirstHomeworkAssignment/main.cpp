#include <iostream>

using namespace std;
//--------Throw---------
class VectorFull : public runtime_error
{
public:
    VectorFull(const string &msg) : runtime_error(msg)
    {
    }
}; // VectorFull

class VectorEmpty : public runtime_error
{
public:
    VectorEmpty(const string &msg) : runtime_error(msg)
    {
    }
}; // VectorEmpty
//--------Throw---------

//--------Vector--------
template <typename E>
class Vector
{
public:
    Vector();
    ~Vector();
    E at(int indx);
    const E &at(int indx) const;
    void set(int indx, E elmt);
    void insert(int indx, E elmt);
    void erase(int indx);
    void resize(int cpct);
    void print();
    int size() const;
    bool isEmpty() const;
    int getCPCT();

private:
    int CPCT;
    E *arr;
    int numb;
}; // Vector

template <typename E>
Vector<E>::Vector() // Default constructor
{
    CPCT = 256;
    arr = new E[CPCT];
    numb = 0;
}; // Vector

template <typename E>
Vector<E>::~Vector()
{
    delete[] arr;
} //~Vector

template <typename E>
E Vector<E>::at(int indx)
{
    return arr[indx];
} // at

template <typename E>
const E &Vector<E>::at(int indx) const
{
    if (indx < 0 || indx >= numb)
    {
        throw out_of_range("At_err: index out of range!");
    }
    return arr[indx];
}

template <typename E>
void Vector<E>::set(int indx, E elmt)
{
    arr[indx] = elmt; // when to increase numb or not :/
} // set

template <typename E>
void Vector<E>::insert(int indx, E elmt)
{
    if (indx < 0 || indx > numb)
    {
        throw out_of_range("Insert_err: out of range!");
    }

    if (numb >= CPCT)
    {
        resize(max(1, CPCT << 1));
    }

    for (int i = numb - 1; i >= indx; i--)
    {
        arr[i + 1] = arr[i];
    }

    arr[indx] = elmt;
    numb++;
} // insert

template <typename E>
void Vector<E>::erase(int indx)
{
    if (!(indx < numb && indx >= 0))
    {
        throw logic_error("Erase_err: index out of reach!");
    }
    if (!(indx == (numb - 1))) // if removing last element in vector.
    {
        for (int i = numb; i > indx; i--)
        {
            arr[i] = arr[i + 1];
        }
    }
    numb--;
} // erase

template <typename E>
void Vector<E>::resize(int newCPCT)
{
    if (newCPCT <= CPCT)
    {
        return;
    }
    E *newArr = new E[newCPCT];
    for (int i = 0; i < numb; i++)
    {
        newArr[i] = arr[i];
    }
    delete[] arr;

    arr = newArr;
    CPCT = newCPCT;
} // resize

template <typename E>
void Vector<E>::print()
{
    if (isEmpty())
    {
        throw VectorEmpty("Print_err: Vector is empty!");
    }
    // shouldnt be greater than cpct. schte go vidime
    cout << "Vector: ";
    for (int i = 0; i < numb; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
} // print

template <typename E>
int Vector<E>::size() const
{
    return numb;
} // size

template <typename E>
bool Vector<E>::isEmpty() const
{
    return (size() == 0);
} // isEmpty

template <typename E>
int Vector<E>::getCPCT()
{
    return CPCT;
}
//--------Vector--------

//-------Iterator-------
template <typename E>
class Iterator
{
public:
    Iterator(const Vector<E> &v);
    bool isNext() const;
    void next();
    const E &current() const; // Updated to return a const reference

private:
    const Vector<E> &vector;
    int currentIndx;

    friend class Vector<E>; // Vector is a friend class of Iterator.
};                          // Iterator

template <typename E>
Iterator<E>::Iterator(const Vector<E> &v) : vector(v), currentIndx(0)
{
}

template <typename E>
bool Iterator<E>::isNext() const
{
    return currentIndx < vector.size();
}

template <typename E>
void Iterator<E>::next()
{
    if (isNext())
    {
        currentIndx++;
    }
    else
    {
        throw out_of_range("Next_err: at end of vector!");
    }
}

template <typename E>
const E &Iterator<E>::current() const
{
    if (currentIndx < 0 || currentIndx >= vector.size())
    {
        throw out_of_range("Current_err: index out of range!");
    }
    return vector.at(currentIndx);
}

//-------Iterator-------

//---------Main---------
int main()
{
    Vector<int> vctr;
    Iterator<int> itrt(vctr);

    vctr.insert(0, 42); // insert integer '42' at index '0'.
    vctr.insert(1, 11); // insert integer '1' at index '1'.
    vctr.insert(0, 5);  // insert integer '5' at index '0', "pushing" the two other elements to the right.

    vctr.set(0, 99); // set integer '99' at index '0', overriding the previous integer '5'.

    cout << "Element in pos '1': " << vctr.at(1) << endl; // prints '42';

    cout << "Vector is empty: " << vctr.isEmpty() << endl; // showing .isEmpty() functionality.

    cout << "Vector size: " << vctr.size() << endl; // showing .size() functionality

    vctr.print(); // printing vector "'99', '42', '11'".

    vctr.erase(2); // erasing element at index '2', in this case '11'.

    vctr.print(); // printing vector "'99', '42'".

    cout << vctr.getCPCT() << endl;
    // vctr.resize(512);
    // cout << vctr.getCPCT() << endl;

    for (int i = 0; i < 256; i++)
    {
        cout << "i: " << i << endl;
        vctr.insert(0, i);
    }

    vctr.print(); // printing vector, added 256 elements, to the already existing 2 elements. Maximum capacity was reached and a new capacity by left shifting it by one bit, multiplying the previous capacity by two. 256 -> 512.
    cout << vctr.getCPCT() << endl;
    cout << vctr.size() << endl;

    cout << "Iterator printing: "; // showing all Iterator member functions.
    while (itrt.isNext())
    {
        cout << itrt.current() << " ";
        itrt.next();
    }

    return 0;
} // main
  //---------Main---------