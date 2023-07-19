#include <iostream>

using namespace std;

#include "polygon.h"
#include "triangle.h"

Triangle::Triangle():Polygon(NUMB_VRTC)
{
}

void Triangle::read()
{
    Polygon::read();
}

void Triangle::print() const
{
    for(int i = 0; i < NUMB_VRTC; i++)
    {
        cout << "Vertex: " << i << ": ";
        vrtc[i].print();//HOW IS IT "POINT PRINT"
        cout << endl;
    }
}