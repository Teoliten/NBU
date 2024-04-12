#include <bits/stdc++.h>

using namespace std;

int rotTime(vector<vector<int, int>> matrix, int r, int c)
{
  int time = 0;

  return time;
}

int main()
{
  int T, r, c;
  cin >> T;

  while (T--)
  {
    cin >> r >> c;
    vector<vector<int, int>> matrix;

    for (int i = 0; i < r; i++)
    {
      for (int j = 0; j < c; j++)
      {
        int input;
        cin >> input;
        matrix[i][j] = input;
      }
    }

    rotTime(matrix, r, c);
  }

  return 0;
}