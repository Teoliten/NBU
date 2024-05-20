#include <iostream>
#include <string>
#include <vector>

using namespace std;

vector<int> longestPrefixSuffix(string B)
{
  int m = B.length();

  vector<int> lps(m);

  lps[0] = 0;
  int i = 1;
  int len = 0;

  while (i < m)
  {
    if (B[i] == B[len])
    {
      len++;
      lps[i] = len;
      i++;
    }
    else
    {
      if (len != 0)
      {
        len = lps[len - 1];
      }
      else
      {
        lps[i] = 0;
        i++;
      }
    }
  }
  return lps;
} // lps

vector<int> KMP(string A, string B)
{
  int n = A.length();
  int m = B.length();

  vector<int> lps = longestPrefixSuffix(B);

  int i = 0;
  int j = 0;

  vector<int> v1;

  while (i < n)
  {
    if (A[i] == B[j])
    {
      i++;
      j++;
    }

    if (j == m)
    {
      v1.push_back(i - j + 1);
      j = lps[j - 1];
    }
    else if (i < n && A[i] != B[j])
    {
      if (j != 0)
      {
        j = lps[j - 1];
      }
      else
      {
        i++;
      }
    }
  }
  return v1;
} // Knuth Morris Pratt

int main()
{
  int T;
  T = 1;
  // cin >> T;

  while (T--)
  {
    string A, B;
    A = "ababab";
    B = "ab";
    // cin >> A >> B;

    vector<int> v1 = KMP(A, B);

    cout << v1.size() << endl;
    for (int i = 0; i < v1.size(); i++)
    {
      cout << v1[i] << " ";
    }
    cout << endl;
  }

  // for (int i = 0; i < T; i++) // loop program T times
  // {
  //   int patterns = 0;
  //   vector<int> indicies;

  //   cin >> A >> B;

  //   bool matching = false;
  //   for (int i = 0; i < A.length(); i++)
  //   {
  //     if (A[i] == B[0])
  //     {
  //       matching = true;
  //       for (int j = 1; j < B.length(); j++)
  //       {
  //         if (!A[i + j] == B[j])
  //         {
  //           matching = false;
  //           break;
  //         }
  //       }
  //       if (matching)
  //       {
  //         indicies.push_back(i);
  //         patterns++;
  //       }
  //     }
  //   }
  // }

  return 0;
} // main