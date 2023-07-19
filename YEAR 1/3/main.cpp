#include <iostream>

using namespace std;

#include "point.h"
#include "polygon.h"
#include "triangle.h"
#include "rectangle.h"

int main()
{
    
    Point pnt_frst;
    Point pnt_scnd(1.1,2.1);

    pnt_frst.setX(3.1);
    pnt_frst.setY(4.1);
    
    cout << pnt_frst.getX() << " " << pnt_frst.getY() << endl;
    //cout << pnt_scnd.getX() << " " << pnt_scnd.getY() << endl;

    pnt_frst.print();
    cout << endl;
    
    Polygon poly(5);
    poly.read();
    poly.print();
    cout << endl;

    Triangle tr;
    tr.read();
    tr.print();

    Rectangle re;
    re.read();
    re.print();

    Polygon* ptr_plgn = &re;
    ptr_plgn->print();
    
    return 0;
}