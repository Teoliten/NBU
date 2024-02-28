#ifndef POLYGON_H
#define POLYGON_H

#include <vector>

using namespace std;

#include "point.h"

class Polygon
{   
public: 

    //parameter constructor
    Polygon(int numb);
    
    //read data for a polygon from the std. input
    void read();

    //print data for a polygon in the std output
    virtual void print() const;
protected:
    vector<Point> vrtc;
};

#endif