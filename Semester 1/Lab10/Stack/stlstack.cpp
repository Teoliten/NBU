#include <iostream>
#include <stack>

using namespace std;

void operator <<(stack<int> &istack, int data)
{
    istack.push(data);
}//operator <<

int main()
{
    stack<int> istack;
    istack << 42;

    cout << istack.top() << endl;

    return 0;
}//main
