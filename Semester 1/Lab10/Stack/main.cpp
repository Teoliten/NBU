#include <iostream>

using namespace std;

//#include "Queue.h"
#include "Stack.h"

int main()
{
    /*
    Queue q;

    for (int i = 0; i < 10; i++)
    {
        q.push(i);
    }

    while (!q.empty())
    {
        cout << q.front() << " ";
        q.pop();
    }
    cout << endl;
    */

    Stack s;

    for (int i = 0; i < 10; i++)
    {
        s << i;
    }

    while (!s.empty())
    {
        cout << s.top() << " ";
        s.pop();
    }
    cout << endl;

    return 0;
}//main
