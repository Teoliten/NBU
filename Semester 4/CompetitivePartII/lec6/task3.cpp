#include <bits/stdc++.h>

using namespace std;

int findNoOfOperations(vector<int> a, int i, int j)
{
  if (i == j)
  {
    return 0;
  }

  if (i <= j)
  {
    if (a[i] == a[j])
    {
      return findNoOfOperations(a, i + 1, j + 1);
    }
    else if (a[i] > a[j])
    {
      a[j - 1] = a[j] + a[j + 1];
      return findNoOfOperations(a, i, j - 1) + 1;
    }
    else
    {
      a[i + 1] = a[i] + a[i - 1];
      return findNoOfOperations(a, i + 1, j) + 1;
    }
  }
}

int palindrome(vector<int> arr)
{
  int result = 0;
  int length = arr.size();

  int middle = -1, middle2 = -1;

  middle = length / 2;

  if (length % 2 == 0)
  {
    middle2 = middle - 1;
  }
  cout << middle << ", " << middle2 << endl;

  // check lower half
  for (int i = 0; i < length - middle; i++)
  {
    bool palin = true;

    if (1)
    {
    }
  }

  return result;
}

int main()
{
  int cases;
  cin >> cases;

  int n;

  while (cases--)
  {
    cin >> n;
    vector<int> arr;

    for (int i = 0; i < n; i++)
    {
      int val;
      cin >> val;
      arr.push_back(val);
    }

    palindrome(arr);
  }

  return 0;
}