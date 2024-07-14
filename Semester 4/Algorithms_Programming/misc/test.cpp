#include <iostream> // Use <iostream> for C++

void swapnum(int &i, int &j)
{
  int temp = i;
  i = j;
  j = temp;
}

void swapnum2(int i, int j)
{
  int temp = i;
  i = j;
  j = temp;
}

int main()
{
  int a = 10;
  int b = 20;

  swapnum(a, b);
  std::cout << "After swapnum: A is " << a << " and B is " << b << std::endl;

  // Reset a and b for the next swap
  int c = 30;
  int d = 50;

  swapnum2(c, d);
  std::cout << "After swapnum2: C is " << c << " and D is " << d << std::endl;

  return 0;
}
