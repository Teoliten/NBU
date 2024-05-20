// #include <iostream>
#include <bits/stdc++.h>

using namespace std;

int main()
{
  int t;
  
  t = 1;
  while (t--)
  {
    string input;
    // cin >> input;
    input = "123+*8+";
    stack<int> stack;

    int n1, n2;
    for (int i = 0; i < input.length(); i++)
    {
      if(input[i] != '+' && input[i] != '-' && input[i] != '*' && input[i] != '/')
      {
        stack.push(input[i] - '0');
      }
      else
      {
        n2 = stack.top();
        stack.pop();
        n1 = stack.top();
        stack.pop();

        if(input[i] == '+')
        {
          stack.push(n1 + n2);
          cout <<" +" << n1 << " " << n2 << endl;
        }
          
        else if(input[i] == '-')
          stack.push(n1 - n2);
        else if(input[i] == '*')
          stack.push(n1 * n2);
        else if(input[i] == '/')
          stack.push(n1 / n2);
      }
    }
    cout << stack.top() << endl;
  }

  return 0;
}