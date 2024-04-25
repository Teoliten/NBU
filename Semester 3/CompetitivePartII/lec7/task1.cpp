#include <bits/stdc++.h>

using namespace std;

int main()
{
    cout << "A len: " << endl;
    int a, b;
    cin >> a;

    cout << "B len: " << endl;
    cin >> b;

    vector<int> A, B;

    cout << a << " integers for array A" << endl;
    while (a--)
    {
        int input;
        cin >> input;
        A.push_back(input);
    }

    cout << b << " integers for array B" << endl;
    while (b--)
    {
        int input;
        cin >> input;
        B.push_back(input);
    }

    vector<int> result;
    

    
    return 0;
}//main