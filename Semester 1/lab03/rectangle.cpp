#include<iostream>

using namespace std;

#include "polygon.h"
#include "rectangle.h"

//default contructor
Rectangle::Rectangle():Polygon(NUMB_VRTC)
{
}//Rectangle

//read data for the triangle
void Rectangle::read()
{
    Polygon::read();
}//read

//print data
void Rectangle::print() const
{
    for(int i = 0; i < NUMB_VRTC; i++)
    {
        cout << "Vertex " << i << ": ";
        vrtc[i].print();
        cout << endl;
    }
}//print