#include <iostream>
#include <string>
#include <map>

using namespace std;

int main()
{
  string input = "XY3BFA9KA2";

  map<char, int> mp;
  int sum = 0;

  for (int i = 0; i < input.length(); i++)
  {
    if (input[i] >= 48 && input[i] <= 57)
    {
      sum += input[i] - 48;
    }
    else
    {
      mp[input[i]]++;
    }
  }

  for (auto it = mp.begin(); it != mp.end(); it++)
  {
    for (int i = 0; i < it->second; i++)
    {
      cout << it->first;
    }
    }

  // for (int i = 0; i < mp.size(); i++)
  // {
  //   while (mp[i]--)
  //   {
  //     cout << mp[i];
  //   }
  // }
  cout << sum << endl;

  return 0;
}