#include<iostream>

using namespace std;

#include "point.h"

//default contructor
Point::Point()
{
    x = 0.0;
    y = 0.0;
}//Point

//parameter contructor
Point::Point(const double x, const double y)
{
    this->x = x;
    this->y = y;
}//Point

//set x-coordinate
void Point::setX(const double x)
{
    this->x = x;
}//setX

void Point::setY(const double y)
{
    this->y = y;
}//setY

//get x-coordinate
double Point::getX() const
{
    return x;
}//getX

double Point::getY() const
{
    return y;
}//getY

void Point::print() const
{
    cout << "(" << x << ", " << y << ")";
}//print