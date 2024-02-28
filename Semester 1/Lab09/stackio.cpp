#include <iostream>
#include <string>
#include <stack>

using namespace std;

void readNames(stack<string> &snames)
{
    bool more = true;
    do
    {
        cout << "> ";
        string buff;
        cin >> buff;
        if(buff == "q" || buff == "Q")
        {
            more = false;
        }
        else
        {
            snames.push(buff);
        }
    }while(more);
}//readNames

void printNames(stack<string> snames)
{
    while(!snames.empty())
    {
        cout << snames.top() << ", ";
        snames.pop();
    }
    cout << endl;
}//printNames

int main()
{
    stack<string> snames;
    readNames(snames);
    printNames(snames);
    return 0;
}//main