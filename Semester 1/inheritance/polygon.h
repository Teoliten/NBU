#ifndef POLYGON_H
#define POLYGON_H

#include <vector>

using namespace std;

#include "point.h"

class Polygon
{
public:
    Polygon(int numb);

    void read();

    virtual void print() const;
    
protected:
    vector<Point> vrtc;
};

#endif