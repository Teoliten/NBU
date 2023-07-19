#include<iostream>

using namespace std;

#include "polygon.h"
#include "triangle.h"

//default contructor
Triangle::Triangle():Polygon(NUMB_VRTC)
{
}//Triangle

//read data for the triangle
void Triangle::read()
{
    Polygon::read();
}//read

//print data
void Triangle::print() const
{
    for(int i = 0; i < NUMB_VRTC; i++)
    {
        cout << "Vertex " << i << ": ";
        vrtc[i].print();
        cout << endl;
    }
}//print