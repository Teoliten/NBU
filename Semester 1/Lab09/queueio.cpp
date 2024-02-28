#include <iostream>
#include <string>
#include <queue>

using namespace std;

void readNames(queue<string> &qnames)
{
    bool more = true;
    do
    {
        cout << "> ";
        string buff;
        cin >> buff;
        if (buff == "q" || buff == "Q")
        {
            more = false;
        }
        else
        {
            qnames.push(buff);
        }
    }
    while (more);
}//readNames

void printNames(queue<string> qnames)
{
    while (!qnames.empty())
    {
        cout << qnames.front() << " ";
        qnames.pop();
    }
    cout << endl;
}//printNames

int main()
{
    queue<string> qnames;
    readNames(qnames);
    printNames(qnames);

    return 0;
}//main

