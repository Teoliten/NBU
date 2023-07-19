#ifndef TIMEFIELD_H
#define TIMEFIELD_H

#include "textField.h"

class TimeField : public TextField
{
public: 
    TimeField();//default constructor
    void read() const override;
};//TimeField

#endif