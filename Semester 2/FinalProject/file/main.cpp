#include <iostream>

using namespace std;

#include "tree.h"

int main()
{
    Tree<int> t;

    t.insert(10);
    t.insert(20);
    t.insert(30);
    t.insert(40);
    t.insert(50);
    t.insert(60);
    t.insert(70);
    t.insert(80);
    t.insert(15);
    t.insert(25);
    t.insert(16);
    t.insert(17);
    t.insert(90);
    t.insert(100);
    t.insert(24);
    t.insert(26);
    t.insert(22);
    t.insert(99);
    t.insert(12);
    t.insert(1);
    t.print();

    t.deleteVal(80);
    t.deleteVal(30);

    t.print();
    return 0;
}