#include <iostream>
#include <vector>

using namespace std;

int countPaths(int N)
{
  // Initialize a 2D vector to store the number of ways to reach each cell
  vector<vector<int>> dp(N + 1, vector<int>(N + 1, 0));

  // Base case: there is only 1 way to reach the starting cell
  dp[0][0] = 1;

  // Fill the dp array using dynamic programming
  for (int i = 0; i <= N; ++i)
  {
    for (int j = 0; j <= N; ++j)
    {
      if (i > 0)
        dp[i][j] += dp[i - 1][j]; // Move down
      if (j > 0)
        dp[i][j] += dp[i][j - 1]; // Move right
    }
  }

  cout << endl;
  for (int i = 0; i < N; i++)
  {
    for (int j = 0; j < N; j++)
    {
      cout << dp[i][j] << " ";
    }
    cout << endl;
  }

  return dp[N][N];
}

int main()
{
  // Process several test cases
  vector<int> test_cases = {5}; // Add more test cases as needed

  for (int N : test_cases)
  {
    cout << "For N = " << N << ", number of possible solutions: " << countPaths(N) << endl;
  }

  return 0;
}
