#include <iostream>
#include <string>

using namespace std;

#include "tree.h"

int main()
{
    // Create a GTree object with int keys
    GTree<int> gt;

    // Set the root of the tree
    gt.setRoot(10);

    // Get the root position
    GTree<int>::Position rootPos = gt.getRoot();

    // Add child nodes to the root
    GTree<int>::Position child1 = gt.addChld(rootPos, 20);
    GTree<int>::Position child2 = gt.addChld(rootPos, 30);

    // Add child nodes to child1
    GTree<int>::Position grandchild1 = gt.addChld(child1, 40);
    GTree<int>::Position grandchild2 = gt.addChld(child1, 50);

    // Accessing keys using dereference operator *
    int rootKey = *rootPos;
    int child1Key = *child1;
    int grandchild2Key = *grandchild2;

    // Output the keys
    cout << "Root key: " << rootKey << endl;
    cout << "Child1 key: " << child1Key << endl;
    cout << "Grandchild2 key: " << grandchild2Key << endl;

    return 0;
    // try
    // {
    //     GTree<int> gt;
    //     gt.setRoot(1);

    //     GTree<int>::Position rootPos = gt.getRoot();
    //     cout << "Root value: " << *rootPos << endl;
    //     cout << "Is root? " << rootPos.isRoot() << endl;
    //     cout << "Is external? " << rootPos.isExternal() << endl;

    //     gt.addChld(rootPos, 2);
    //     gt.addChld(rootPos, 3);

    //     cout << "Tree size: " << gt.size() << endl;

    //     GTree<int>::Position childPos = rootPos.chldList().front();
    //     cout << "Child value: " << *childPos << endl;

    //     GTree<int>::Position parentPos = childPos.parent();
    //     cout << "Parent value: " << *parentPos << endl;

    //     // Add more tests as needed...

    //     cout << "Tree size: " << gt.size() << endl;
    // }
    // catch (const exception &e)
    // {
    //     cerr << "Exception: " << e.what() << endl;
    // }

    return 0;
}
