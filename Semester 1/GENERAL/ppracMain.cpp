#include <iostream>

using namespace std;

#include "ppracHeader.h"

int main()
{
    Header hd;

    cout << "Enter integer: " << endl << "> ";
    int x;
    cin >> x;

    hd.setX(x);
    hd.print();

    return 0;
}//main