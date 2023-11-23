#include <iostream>

using namespace std;

#include "btree.h"

int main()
{
    BTree<int> tr;
    tr.setRoot(0);
    BTree<int>::Position pos = tr.getRoot();

    cout << "Root: " << *pos << endl;

    tr.setLeft(pos, -1);
    tr.setRight(pos, 1);

    pos = pos.left();

    tr.setLeft(pos, -2);
    tr.setRight(pos, 2);

    cout << "Size: " << tr.size() << endl;

    tr.print();

    return 0;
}//main
