// #include <iostream>
// #include <vector>
// #include <algorithm>

#include <bits/stdc++.h>

using namespace std;

int main() {
    cout << "A len: " << endl;
    int a, b;
    cin >> a;

    cout << "B len: " << endl;
    cin >> b;

    vector<int> A(a);
    vector<int> B(b);

    cout << a << " integers for array A" << endl;
    for (int i = 0; i < a; i++) 
    {
        cin >> A[i];
    }

    sort(A.begin(), A.end());

    cout << b << " integers for array B" << endl;
    for (int i = 0; i < b; i++) 
    {
        cin >> B[i];
    }

    vector<int> result;

    for (int i = 0; i < b; i++) 
    {
        for (int j = 0; j < a; j++) 
        {
            if (A[j] == B[i]) 
            {
                A[j] = 0;
                result.push_back(B[i]);
            }
        }
    }

    for (int i = 0; i < a; i++) 
    {
        if (A[i] != 0) {
            result.push_back(A[i]);
        }
    }

    cout << "Result: ";
    for (int i = 0; i < result.size(); i++) 
    {
        cout << result[i] << " ";
    }
    cout << endl;

    return 0;
}
