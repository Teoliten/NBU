#include <iostream>

using namespace std;

#include "QuadraticInt.h"
#include <cmath>

QuadraticInt::QuadraticInt()//Default constructor
{
	len = 3;
	rRoots = false;
	arr = new int[len];
	for(int i = 0; i < len; i++)//initializing array
	{
		arr[i] = 0;
	}
}//QuadraticInt

QuadraticInt::QuadraticInt(const QuadraticInt &z)
{
    cout << endl << "<[Copy constructor]>" << endl;
    len = 3;
	rRoots = false;
	arr = new int[len];
	for(int i = 0; i < len; i++)
	{
		arr[i] = z.arr[i];
	}
}//copy constructor

QuadraticInt &QuadraticInt::operator =(const QuadraticInt &arr1)
{
	cout << endl << "<[Assignment operator]>" << endl;
    if (this != &arr1)
    {
        if (arr)
        {
            delete[] arr;
            arr = nullptr;
        }
        arr = new int[len];
        for (int i = 0; i < len; i++)
        {
            arr[i] = arr1.arr[i];
        }
    }
    return *this;
}//operator =

double QuadraticInt::solveQ(const int value)
{
	double result; 
    result = (this->arr[0] * value * value) + (this->arr[1] * value) + (this->arr[2]);
    //ax^2 + bx + c ------  a * value^2 + b * value + c
    cout << this->arr[0] << "*(" << value << ")^2 + " << this->arr[1] << "*" << value << " + " << this->arr[2] << " = ";
    cout << result << endl;
    return result;
}//solveQ

QuadraticInt::~QuadraticInt()//Destructor
{
	cout << endl << "<[Destructor]>" << endl;
	if(arr)
	{
		delete[] arr;
		arr = nullptr;
	}
}//~QuadraticInt / Destructor

QuadraticInt QuadraticInt::operator +(const QuadraticInt &z) const
{
	//cout << "Adding two quadratic equations:" << endl;
	QuadraticInt result;
	
	result.arr[0] = arr[0] + z.arr[0];
	result.arr[1] = arr[1] + z.arr[1];
	result.arr[2] = arr[2] + z.arr[2];
	
	return result;
}//operator +

QuadraticInt QuadraticInt::operator -(const QuadraticInt &z) const
{
	//cout << "Subtracting two quadratic equations:" << endl;
	QuadraticInt result;
	
	result.arr[0] = arr[0] - z.arr[0];
	result.arr[1] = arr[1] - z.arr[1];
	result.arr[2] = arr[2] - z.arr[2];
	
	return result;
}//operator -
	
bool QuadraticInt::operator *(const QuadraticInt &z)
{
	//cout << "Checking real roots" << endl;
	int a = arr[0];
    int b = arr[1];
    int c = arr[2];

    int discriminant = b * b - 4 * a * c;
    
    if(discriminant >= 0)
    {
    	rRoots = true;
    }
    else
    {
    	rRoots = false;
    }
	return rRoots;
}//operator -

ostream &operator <<(ostream &out, const QuadraticInt &arr)
{
    out << "Coefficients are " << arr.arr[0] << ", "
    << arr.arr[1] << " and " << arr.arr[2] << endl;
    
    return out;
}//operator <<

istream &operator >>(istream &in, QuadraticInt &arr)
{
	if (arr.arr)
    {
        delete[] arr.arr;
        arr.arr = nullptr;
    }
    arr.arr = new int[3];

	cout << "Enter coefficients (int) for the quadratic polynomial: " << endl;
	cout << "ax^2 + bx + c" << endl << "a = ";
	in >> arr.arr[0];
	cout << "b = ";
	in >> arr.arr[1];
	cout << "c = ";
	in >> arr.arr[2];	
    
    return in;
}//operator >>