#include <iostream>

using namespace std;

#include "clist.h"

int main()
{
  const int NUMB = 16;
  Clist cl;

  for (int i = 0; i < NUMB; i++)
  {
    cl.add(i);
  }

  for (int i = 0; i < NUMB; i++)
  {
    cout << "___" << endl;
    cout << "Front: " << cl.front() << endl;
    cout << "Back: " << cl.back() << endl;
    cl.advance();
  }
  return 0;
} // main