#include <iostream>

using namespace std;

#include "textField.h"
#include "dateField.h"
#include "timeField.h"
#include "currencyField.h"

int main()
{
    TextField tf;
    tf.read();

    DateField df;
    TextField* text1 = &df;
    text1->read();

    TimeField tif;
    TextField* text2 = &tif;
    text2->read();

    CurrencyField cf;
    TextField* text3 = &cf;
    text3->read();

    return 0;
}//main
