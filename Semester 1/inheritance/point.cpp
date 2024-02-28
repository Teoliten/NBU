#include <iostream>

using namespace std;

#include "point.h"

Point::Point()
{
    x = 0.0;
    y = 0.0;
}

Point::Point(const double x, const double y)
{
    this->x = x;
    this->y = y;
}

void Point::setX(const double x)
{
    this->x = x;
}

void Point::setY(const double y)
{
    this->y = y;
}

double Point::getX() const
{
    return x;
}
double Point::getY() const
{
    return y;
}

void Point::print() const
{
    //cout << "POINT PRINT: ";
    cout << "(" << x << ", " << y << ")" << endl;
}