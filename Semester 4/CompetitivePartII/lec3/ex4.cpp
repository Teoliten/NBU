#include <bits/stdc++.h>
using namespace std;

int main()
{
    cout << "Enter number of test cases: ";
    int t;
    cin >> t;

    while (t--) {
        int n;

        cout << "Enter size of array: ";
        cin >> n;

        int A[n];

        cout << "Enter elements: ";
        for (int i = 0; i < n; i++)
            cin >> A[i];

        unordered_map<int, int> ma;
        ma[0] = -1;
        int maxlen = 0;
        int counter = 0;

        for (int i = 0; i < n; i++) {
            if (A[i] == 0)
                counter--;
            else if (A[i] == 1)
                counter++;
            if (ma.find(counter) != ma.end())
                maxlen = max(maxlen, i - ma[counter]);
            else {
                ma[counter] = i;
            }
        }

        cout << "Maximum size is: ";
        cout << maxlen << "\n";
    }

    return 0;
}