#include <iostream>
#include <sstream>
#include <string>

using namespace std;

int strToDouble(const string &str)
{
    istringstream in_strm;
    in_strm.str(str);
    int result;
    in_strm >> result;

    return result;
}//strToDouble

int main()
{
    string hello;
    cin >> hello;
    cout << typeid(hello).name();
    cout << strToDouble(hello) << endl;
    cout << typeid(strToDouble(hello)).name();
    return 0;
}//main