#include <iostream>
#include <string>


using namespace std;

#include "tree.h"

int main()
{
    try
    {
        GTree<int> gt;
        gt.setRoot(1);

        GTree<int>::Position rootPos = gt.Position(gt.setRoot(rootPos));
        cout << "Root value: " << *rootPos << endl;
        cout << "Is root? " << rootPos.isRoot() << endl;
        cout << "Is external? " << rootPos.isExternal() << endl;

        gt.addChld(rootPos, 2);
        gt.addChld(rootPos, 3);

        cout << "Tree size: " << gt.size() << endl;

        GTree<int>::Position childPos = rootPos.chldList().front();
        cout << "Child value: " << *childPos << endl;

        GTree<int>::Position parentPos = childPos.parent();
        cout << "Parent value: " << *parentPos << endl;

        // Add more tests as needed...

        cout << "Tree size: " << gt.size() << endl;
    }
    catch (const exception &e)
    {
        cerr << "Exception: " << e.what() << endl;
    }

    return 0;
}
