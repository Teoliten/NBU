#include <iostream>

using namespace std;

int factorial(int user)
{
    int result = 1;
    for(int i = 0; i < user; i++)
    {
        result = (user - i) * result;
    }
    return result;
}//facotorial

int main()
{
    cout << "Enter INTEGER: " << endl << "> ";
    int user;
    cin >> user;
    int fac = factorial(user);
    cout << fac;
    return 0;
}//main