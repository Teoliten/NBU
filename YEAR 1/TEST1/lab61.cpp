#include <iostream>

using namespace std;

int factorial(int num)
{
    return num > 1 ? num * factorial(num-1) : 1;
}

int triang(int n)
{
    return n > 1 ? n + triang(n - 1) : 1;
}

int main()
{
    cout << "Enter integer: " << endl;
    int num; 
    cin >> num;
    cout << "fac " <<factorial(num) << endl;
    cout << "triang"<< triang(num) << endl;
    return 0;
}//main