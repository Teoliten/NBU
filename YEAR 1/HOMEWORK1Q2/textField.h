#ifndef TEXTFIELD_H
#define TEXTFIELD_H

#include <iostream>
#include <string>

using namespace std;

class TextField
{
public:
    TextField();//default constructor
    virtual void read() const;
protected:
    string text;
};//TextField

#endif