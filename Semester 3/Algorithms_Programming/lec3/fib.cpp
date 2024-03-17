#include <iostream>

using namespace std;

int fibSeq(int n)
{
  if(n <= 1)
  {
    return n;
  }
  else
  {
    return fibSeq(n - 1) + fibSeq(n - 2);
  }
}//fibSeq

int main()
{
  int input;
  cin >> input;
  cout << "result: " << fibSeq(input) << endl;
  return 0;
}//main