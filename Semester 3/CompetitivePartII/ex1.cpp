
#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

void countAndSay(int n)
{
  if (n == 0)
  {
    cout << "" << endl;
    return;
  }
  if (n == 1)
  {
    cout << "1" << endl;
    return;
  }

  string result = "1";
  cout << "result_frst: " << result << endl;
  string tmp;

  for (int i = 1; i < n; i++)
  {
    int len = result.length();
    for (int j = 0; j < len; j++)
    {
      int count = 1;
      cout << "result: " << result << endl;
      // tmp = "";
      while ((j + 1 < len) && result[j] == result[j + 1])
      {
        count++;
        j++;
      }

      tmp += to_string(count) + result;
      cout << "tmp:" << tmp << endl;
    }

    result = tmp;
    cout << result << endl;
    tmp = "";
  }
}

int main()
{
  int n = 5;
  // while (cin >> n)
  // {
  countAndSay(n);
  // }
  return 0;
}

// 1
// 11
// 21
// 1211
// 111221