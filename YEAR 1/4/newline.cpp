#include <iostream>

using namespace std;

int main()
{
    char ch = cin.get();
    do
    {
        cout << (ch == '\n' ? ' ' : ch);
        ch = cin.get();
    }
    while(!cin.fail());

    return 0;
}