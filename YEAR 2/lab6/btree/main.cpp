#include <iostream>

using namespace std;

#include "btree.h"

int main()
{
  BTree<int> bt;

  bt.setRoot(42);

  BTree<int>::Position pos = bt.getRoot();

  cout << "Root: " << (*pos) << endl;
  return 0;
} // main