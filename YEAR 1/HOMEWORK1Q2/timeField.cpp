#include <iostream>
#include <string>

using namespace std;

#include "timeField.h"

TimeField::TimeField() : TextField()
{

}//TimeField

void TimeField::read() const
{
    cout << "Enter time: ";
    string text;
    cin >> text;
}//read