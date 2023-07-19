#include <iostream>
#include <string>

using namespace std;

#include "textField.h"

TextField::TextField()
{

}//TextField

void TextField::read() const
{
    cout << "Enter text: ";
    string text;
    cin >> text;
}//read