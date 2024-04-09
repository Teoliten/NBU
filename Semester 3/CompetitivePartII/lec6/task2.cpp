#include <bits/stdc++.h>

using namespace std;

int minAddToMakeValue(string g)
{
  stack<char> st;
  int count = 0;
  for (int i = 0; i < g.length(); i++)
  {
    if (g[i] == '(')
      st.push('(');
    else
    {
      if (st.empty())
      {
        count++;
        continue;
      }
      else if (g[i] == ')' && st.top() != ')')
      {
        count++;
      }
      st.pop();
    }
  }

  count += st.size();

  return count;
}

int check(string i)
{
  int count = 0;
  int track = 0;

  for (int j = 0; j < i.length(); j++)
  {
    if (i[j] == '(')
    {
      track--;
    }

    if (i[j] == ')' && track == 0)
    {
      count++;
    }
    else if (i[j] == ')')
    {
      track++;
    }
  }

  count += abs(track);

  return count;
}

int main()
{
  string i;

  while (cin >> i)
  {
    cout << "count: " << check(i) << endl;
    cout << "count: " << minAddToMakeValue(i) << endl;
  }

  return 0;
}