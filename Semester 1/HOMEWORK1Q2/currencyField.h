#ifndef CURRENCYFIELD_H
#define CURRENCYFIELD_H

#include "textField.h"

class CurrencyField : public TextField
{
public: 
    CurrencyField();//default constructor
    void read() const override;
};//CurrencyField

#endif