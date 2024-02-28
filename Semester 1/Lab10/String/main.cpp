#include <iostream>

using namespace std;

#include "String.h"

int main()
{
    String str_frst;
    cin >> str_frst;
    cout << str_frst << endl;
   
    String str_scnd;
    str_scnd = str_frst;
    cout << str_scnd << endl;
    return 0;
}//main