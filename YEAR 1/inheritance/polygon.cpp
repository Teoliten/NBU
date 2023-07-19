#include <iostream>
#include <vector>
#include <cassert>

using namespace std;

#include "polygon.h"

Polygon::Polygon(int numb)
{
    assert(numb > 0);
    vrtc.resize(numb);
}
    
void Polygon::read()
{
    for(int i = 0; i < vrtc.size(); i++)
    {
        cout << "Point " << i << " x: ";
        double x; 
        cin >> x;
        vrtc[i].setX(x);

        cout << "Point " << i << " y: ";
        double y;
        cin >> y;
        vrtc[i].setY(y);
    }
}

void Polygon::print() const
{
    //cout << "POLYGON PRINT: ";
    cout << "[";
    for(int i = 0; i < vrtc.size(); i++)
    {
        vrtc[i].print();//POINT PRINT
    }
    cout << "]" << endl;
}