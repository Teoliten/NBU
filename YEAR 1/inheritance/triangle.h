#ifndef TRIANGLE_H
#define TRIANGLE_H

#include "polygon.h"

class Triangle:public Polygon
{
public:
    Triangle();

    void read();

    virtual void print() const;
private:
    enum{NUMB_VRTC = 3};

};
#endif