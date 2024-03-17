#include <iostream>
#include <bits/stdc++.h>

using namespace std;

int cutRod(int p[], int n)
{
    if (n == 0)
    {
        return 0;
    }
    int q = -9999999999;
    for (int i = 0; i < n; i++)
    {
        q = max(q, (p[i] + cutRod(p, n - i - 1)));
    }
    return q; // Return the maximum value
}

int main()
{
    int p[] = {1, 5, 8, 9, 10, 17, 17, 20, 24, 30};
    int n;
    cin >> n;

    int maxProfit = cutRod(p, n);
    cout << "Maximum profit: " << maxProfit << endl;

    // Print the array p
    cout << "Array p: ";
    for (int i = 0; i < sizeof(p) / sizeof(p[0]); i++)
    {
        cout << p[i] << " ";
    }
    cout << endl;

    return 0;
}
