#ifndef DATEFIELD_H
#define DATEFIELD_H

#include "textField.h"

class DateField : public TextField
{
public:
    DateField();//default constructor
    void read() const override;
};//DateField

#endif