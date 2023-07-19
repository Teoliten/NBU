#include<iostream>
#include<cassert>
#include<vector>

using namespace std;

#include "point.h"
#include "polygon.h"

//parameter constructor
Polygon::Polygon(int numb)
{
    assert(numb > 0);
    vrtc.resize(numb);
}//Polygon

//read data
void Polygon::read()
{
    for(int i = 0; i < vrtc.size(); i++)
    {
        cout << "Point " << i <<  " x: ";
        double x;
        cin >> x;
        vrtc[i].setX(x);

        cout << "Point " << i << " y: ";
        double y;
        cin >> y;
        vrtc[i].setY(y);
    }
}//read

void Polygon::print() const
{
    cout << "[";
    for(int i = 0; i < vrtc.size(); i++)
    {
        vrtc[i].print();
    }
    cout << "]";
}//print