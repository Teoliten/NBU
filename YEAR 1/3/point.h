#ifndef POINT_H
#define POINT_H

//point in Cartesian plane
class Point
{
public:
    //default contrctor
    Point();

    //parameter contructor
    Point(const double x, const double y);

    //set data fields
    void setX(const double x);
    void setY(const double y);

    //get data fields
    double getX() const;
    double getY() const;

    //print
    void print() const;
    
private:
    double x;   // x/y-coordinate
    double y;
};

#endif //has to be last line of file