#ifndef COMPLEX_H
#define COMPLEX_H

class Complex
{
public:
    Complex();//default constructor
    Complex(double real, double imag);//parameter constructor

    //--
    Complex operator +(const Complex &z) const;
    Complex operator -(const Complex &z) const;
    Complex operator *(const Complex &z) const;
    Complex operator /(const Complex &z) const;
    //--
    void print() const;

private:
    double imag;
    double real;
    
    friend istream &operator >>(istream &in, Complex &z);
    friend ostream &operator <<(ostream &out, const Complex &z);
};

#endif