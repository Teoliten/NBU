#include <iostream>
#include <string>

using namespace std;

#include "hashc.h"
#include "hasht.h"

int main()
{
  // throw HashTExcept("Test. Do not panic");
  HashT<string, int, HCPolyStr>::Entry ent("apple", 42);

  ent.setKey("world");
  ent.setVal(11);

  cout << "Key: " << ent.getKey() << endl;
  cout << "Val: " << ent.getVal() << endl;
  return 0;
} // main