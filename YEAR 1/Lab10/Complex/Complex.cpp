#include <iostream>

using namespace std;

#include "Complex.h"

Complex::Complex()
{
    imag = 0.0;
    real = 0.0;
}//Complex

Complex::Complex(double real, double imag)
{
    this->real = real;
    this->imag = imag;
}//Complex

void Complex::print() const
{
    cout << "(" << real << ", " << imag << ")";
}//print

Complex Complex::operator +(const Complex &z) const
{
    Complex result;

    result.real = real + z.real;
    result.imag = imag + z.imag;

    return result;
}

Complex Complex::operator -(const Complex &z) const
{
    Complex result;

    result.real = real - z.real;
    result.imag = imag - z.imag;

    return result;
}
Complex Complex::operator *(const Complex &z) const
{
    Complex result;

    result.real = real * z.real - imag * z.imag;
    result.imag = real * z.imag + imag * z.real;

    return result;
}//operator *

Complex Complex::operator /(const Complex &z) const
{
    Complex result;

    double div = z.real * z.real + z.imag * z.imag;
    result.real = (real * z.real + imag * z.imag) / div;
    result.imag = (imag * z.real - real * z.imag) / div;

    return result;
}//operator /

istream &operator >>(istream &in, Complex &z)
{
    in >> z.real >> z.imag;

    return in;
}//operator >>

ostream &operator <<(ostream &out, const Complex &z)
{
    cout << z.real << "+ i" << z.imag;

    return out;
}
