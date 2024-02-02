#include <iostream>

using namespace std;

#include "tree2.h"

int main() {
    Tree<int> t;

    t.insert(10);
    t.insert(20);
    t.insert(30);
    t.insert(40);
    t.insert(50);
    t.insert(60);
    t.insert(70);
    t.insert(80);
    // t.insert(90);
    // t.insert(100);

    t.print();

    return 0;
}