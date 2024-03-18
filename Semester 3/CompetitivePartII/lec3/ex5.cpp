#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int main()
{
  int T, N; // t, repitions, n array size
  cin >> T;
  while (T--)
  {
    cin >> N;

    int A[N];
    int B[N];

    for (int i = 0; i < N; i++)
    {
      cin >> A[i] >> B[i];
    }

    priority_queue<int, vector<int>, greater<int>> pq;
    int max1 = INT_MIN, max2 = INT_MIN, max3 = INT_MIN;
    for (int i = 0; i < N; i++)
    {
      for (int j = 0; j < N; j++)
      {
        pq.push(A[i] + B[j]);
        if (pq.size() > N)
        {
          pq.pop();
        }
      }
    }

    while (!pq.empty())
    {
      cout << pq.top() << " ";
      pq.pop();
    }
    cout << endl;
  }
  return 0;
}
