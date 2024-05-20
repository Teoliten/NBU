#include <iostream>
#include <string>
#include <stack>

using namespace std;

int main()
{
  string input = "IIDDIDD";

  stack<int> stack;

  for (int i = 0; i <= input.length(); i++)
  {
    stack.push(i + 1);
    if (i == input.length() || input[i] == 'I')
    {
      while (!stack.empty())
      {
        cout << stack.top();
        stack.pop();
      }
    }
  }

  return 0;
}