#ifndef RECTANGLEE_H
#define RECTANGLEH

#include "polygon.h"

class Rectangle:public Polygon
{
public:
    //default contructor
    Rectangle();

    //read data for the triangle
    void read();

    //print triangle data in std. output
    virtual void print() const;
private:

    //constants
    enum{NUMB_VRTC = 4};
};

#endif