#include <iostream>
#include <string>

using namespace std;

#include "btree.h"

int main()
{
  BTree<int> bt; // creating class object

  try
  {
    bt.setRoot(1); // initializing tree, creating a node, and giving it the value 1

    BTree<int>::Position pos = bt.getRoot(); // initializing Position pos at the root of the tree

    bt.setLeft(pos, 2);  // setting root's left child value
    bt.setRight(pos, 3); // setting root's right child value

    pos = pos.left();

    bt.setLeft(pos, 4);
    bt.setRight(pos, 5);

    pos = pos.parent().right(); // navigating in the tree: go one up, then go to the right child

    bt.setLeft(pos, 6);
    bt.setRight(pos, 7);

    std::cout << "Root: " << (*bt.getRoot()) << std::endl;        // print root value
    std::cout << "External: " << (pos.isExternal()) << std::endl; // print whether the current position is external
    std::cout << "Size: " << bt.size() << std::endl;              // print the size of the tree
    std::cout << "Empty: " << bt.empty() << std::endl;            // print whether the tree is empty

    std::cout << std::endl;
    std::cout << "Print Tree:" << std::endl;
    bt.print(); // print the tree
    std::cout << std::endl;
  }
  catch (const TreeExcept &ex)
  {
    std::cerr << "Tree Exception: " << ex.what() << std::endl;
  }

  return 0;
} // main