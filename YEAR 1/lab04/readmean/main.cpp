#include <iostream>
#include <string>

using namespace std;

#include "readmean.h"

int main()
{
    cout << "Enter file name: ";
    string in_file_name;
    cin >> in_file_name;

    ReadMean rm(in_file_name)
    return 0;
}