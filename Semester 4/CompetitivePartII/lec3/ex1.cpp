#include <iostream>
#include <bits/stdc++.h>

using namespace std;

int main()
{
  // int T = 1, N = 6;
  // // cin >> T >> N;

  // int arr[N] = {10, 4, 5, 90, 120, 80};

  // stack<int> stack;
  // int input;

  // for (int i = 0; i < N; i++)
  // {
  //   // cin >> input;
  //   // arr[i] = input;
  // }

  // for (int i = 0; i < N; i++)
  // {
  //   if (i == 0)
  //   {
  //     cout << 1 << " ";
  //   }
  //   int output = 0;
  //   for (int j = i; j > 0; j--)
  //   {
  //     output = 1;
  //     if (arr[j] > arr[j - 1])
  //     {
  //       output++;
  //     }
  //     else
  //     {
  //       break;
  //     }
  //   }
  //   if (output)
  //     cout << output << " ";
  // }

  int t;
  // cin >> t;
  t = 1;
  while (t--)
  {
    int n;
    // cin >> n;
    n = 6;
    // int arr[n];
    int arr[n] = {10, 4, 5, 90, 120, 80};
    // for (int i = 0; i < n; i++)
    // {
    //   cin >> arr[i];
    // }

    stack<pair<int, int>>
        st;
    vector<int> v1;

    st.push({INT_MAX, -1});

    for (int i = 0; i < n; i++)
    {
      bool flag = false;
      cout << "size: " << st.size() << endl;
      while (!st.empty())
      {
        if (st.top().first > arr[i])
        {
          cout << st.top().first << endl;
          v1.push_back(i - st.top().second);
          flag = true;
          break;
        }
        else
        {
          st.pop();
        }
      }

      if (flag == false)
      {
        v1.push_back(1);
      }

      st.push({arr[i], i});
    }

    for (int i = 0; i < n; i++)
    {
      cout << v1[i] << " ";
    }
    cout << "\n";
  }

  return 0;
}
