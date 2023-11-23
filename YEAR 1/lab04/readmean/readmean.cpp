#include <iostream>
#include <string>

using namespace std;

#include "readmean.h"

ReadMean::ReadMean(const string in_file_name)
{
    in_strm.open(in_file_name.c_str())
}

ReadMean::~ReadMean()
{
    cout << "Destructor." << endl;
    if(!in:strm.fail())
    {
        in_strm.close();
    }
}

double ReadMean::calculate()
{
    
}