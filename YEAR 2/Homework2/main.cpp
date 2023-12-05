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

    cout << "Original Tree:" << endl;
    cout << "Root: " << (*bt.getRoot()) << endl;        // print root value
    cout << "External: " << (pos.isExternal()) << endl; // print whether the current position is external
    cout << "Size: " << bt.size() << endl;              // print the size of the tree
    cout << "Empty: " << bt.empty() << endl;            // print whether the tree is empty

    cout << endl;
    cout << "Print Tree:" << endl;
    bt.print(); // print the tree
    cout << endl;

    
    BTree<int> btCopy(bt); // copy using copy constructor
    cout << "Copied Tree:" << endl;
    btCopy.print();
    cout << endl;

    // Test overloaded assignment operator
    BTree<int> btAssigned;
    btAssigned = bt;
    cout << "Assigned Tree:" << endl;
    btAssigned.print();
    cout << endl;

    // Modify the original tree
    bt.setLeft(pos, 8);
    bt.setRight(pos, 9);

    cout << "Modified Original Tree:" << endl;
    bt.print();
    cout << endl;

    // Verify that the copied and assigned trees remain unchanged
    cout << "Copied Tree After Modification (should be unchanged):" << endl;
    btCopy.print();
    cout << endl;

    cout << "Assigned Tree After Modification (should be unchanged):" << endl;
    btAssigned.print();
    cout << endl;
  }
  catch (const TreeExcept &ex)
  {
    cerr << "Tree Exception: " << ex.what() << endl;
  }

  return 0;
} // main
