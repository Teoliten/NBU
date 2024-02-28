#ifndef STRING_H
#define STRING_H

#include <iostream>

using namespace std;

class String
{
public:
    String();
    String(const String &str);
    ~String();
    String &operator =(const String &str);

private:
    char* arr;
    int len;

friend istream &operator >>(istream &in, String &str);
friend ostream &operator <<(ostream &out, const String &str);
};

#endif