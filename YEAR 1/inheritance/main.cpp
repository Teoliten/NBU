#include <iostream>

using namespace std;

#include "point.h"
#include "polygon.h"
#include "triangle.h"

int main()
{
    Point pt1;
    Point pt2(1.2, 266.6);

    pt1.setX(1.65);
    pt1.setY(2.0);
    pt1.print();
    pt2.print();
    cout << "pt1, x: " << pt1.getX() << endl;

    Polygon poly(2);
    poly.read();
    poly.print();

    Triangle tr;
    tr.read();
    tr.print();

    return 0;
}//main