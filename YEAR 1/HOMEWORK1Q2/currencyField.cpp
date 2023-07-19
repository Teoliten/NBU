#include <iostream>
#include <string>

using namespace std;

#include "currencyField.h"

CurrencyField::CurrencyField() : TextField()
{

}//CurrencyField

void CurrencyField::read() const
{
    cout << "Enter currency: ";
    string text;
    cin >> text;
}//read