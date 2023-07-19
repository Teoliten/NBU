#include <iostream>
#include <fstream>
#include <string>

using namespace std;

#include "StudBook.h"

int main()
{
    StudBook sbook;
/*
    sbook.write("Rick", "Sanchez", 101010);
    sbook.write("Morty", "Smith", 202020);
    sbook.write("Summer", "Smith", 303030);
    */

    cout << sbook.read(1) << endl;

    return 0;
}//main
