#ifndef QUADRATICINT_H
#define QUADRATICINT_H

#include <iostream>

using namespace std;

class QuadraticInt
{
public:
	QuadraticInt();//Default constructor
	QuadraticInt(const QuadraticInt &z);//Copy constructor
	QuadraticInt& operator =(const QuadraticInt &arr);//Asignment operator
	double solveQ(const int value);//Sole quadratic equation 
	~QuadraticInt();//Destructor
	
	QuadraticInt operator +(const QuadraticInt &z) const;
	QuadraticInt operator -(const QuadraticInt &z) const;
	bool operator *(const QuadraticInt &z);
	
	
private:
	int* arr;
	int len;
	bool rRoots;

friend ostream &operator <<(ostream &out, const QuadraticInt &arr);
friend istream &operator >>(istream &in, QuadraticInt &arr);
};

#endif