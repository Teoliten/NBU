#ifndef HEADER_H
#define HEADER_H

class Header
{
public:
    Header();
    Header(const int x);

    void setX(const int x);
    int getX() const;

    void print() const;
private:
    int x;
};

#endif