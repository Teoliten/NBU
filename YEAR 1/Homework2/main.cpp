#include <iostream>

using namespace std;

#include "LList.h"
#include "Iterator.h"

int main()
{
    LList llist;

    for (int i = 0; i < 10; i++)
    {
        llist.pushBack(i);
    }

    Iterator pos = llist.begin();
    pos.next();
    llist.insert(pos, 100);

    for (Iterator pos = llist.begin(); !pos.equals(llist.end()); pos.next())
    {
        cout << pos.get() << " ";
    }
    cout << endl;

    pos.next();
    cout << pos.get() << endl;

    llist.erase(pos);

    for (Iterator pos = llist.begin(); !pos.equals(llist.end()); pos.next())
    {
        cout << pos.get() << " ";
    }
    cout << endl;    

    LList l2;
    l2.pushBack(42);
    l2.pushBack(11);
    for (Iterator pos = l2.begin(); !pos.equals(l2.end()); pos.next())
    {
        cout << pos.get() << " ";
    }
    cout << endl;
    Iterator pos2 = l2.begin();
    l2.erase(pos2);

    for (Iterator pos = l2.begin(); !pos.equals(l2.end()); pos.next())
    {
        cout << pos.get() << " ";
    }
    
    cout << endl;
    

    return 0;
}//main
