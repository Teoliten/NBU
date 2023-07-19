#include <iostream>

using namespace std;

int triang(int n)
{
    if(n == 1)
    {
        return 1;
    }
    else
    {
        return n + triang(n - 1);
    }
}

int main()
{
    cout << "Enter N: ";
    int n;
    cin >> n;
    cout << triang(n) << endl;
    return 0;
}