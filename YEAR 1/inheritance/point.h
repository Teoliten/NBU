#ifndef POINT_H
#define POINT_H

class Point
{
public:
    Point();
    Point(const double x, const double y);

    void setX(const double x);
    void setY(const double y);

    double getX() const;
    double getY() const;

    void print() const;
private:
    double x;
    double y;
};
#endif