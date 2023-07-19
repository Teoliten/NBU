#ifndef TRIANGLE_H
#define TRIANGLE_H

#include "polygon.h"

class Triangle:public Polygon
{
public:
    //default contructor
    Triangle();

    //read data for the triangle
    void read();

    //print triangle data in std. output
    virtual void print() const;
private:

    //constants
    enum{NUMB_VRTC = 3};
};

#endif