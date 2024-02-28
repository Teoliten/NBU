#include <iostream>
#include <string>

using namespace std;

#include "map.h"

//_______________MAIN_______________
int main()
{
  Map<int, string> map;

  map.put(2, "Test");
  map.put(2, "Test2");
  map.put(3, "Test3");

  cout
      << "Size: " << map.size() << endl;
  cout << "Empty: " << map.empty() << endl;

  Map<int, string>::Iterator iter = map.begin();
  iter = map.end();
  map.begin();

  // Entry<int, string> ent(42, "Rick");

  // cout << ent.getKey() << endl;
  // cout << ent.getVal() << endl;

  // ent.setKey(0);
  // ent.setVal("Morty");

  // cout << ent.getKey() << endl;
  // cout << ent.getVal() << endl;

  return 0;
} // main
//_______________MAIN_______________
