#include <iostream>

using namespace std;

int pow(int a, int b)
{
    int result = a;
    for(int i = 1; i < b; i++)
    {
        result = result * a;
    }

    return result;
}

int main()
{
    cout << "Enter two integers: a^b" << endl;
    int a, b;
    cin >> a >> b;
    
    int res = pow(a, b);
    cout << res;
    return 0;
}