#include <iostream>

using namespace std;

#include "ppracHeader.h"

Header::Header()
{
    x = 0;
}

Header::Header(const int x)
{
    this-> x = x;
}

void Header::setX(const int x)
{
    this-> x = x;
}

int Header::getX() const
{
    return x;
}//getX

void Header::print() const
{
    cout << "X: " << x << endl;
}