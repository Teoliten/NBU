#ifndef READMEAN_H
#define READMEAN_H

#include <fstream>
#include <string>

using namespace std;

class ReadMean()
{
public:
    ReadMean(const string in_file_name); // parameter constructor
    ~ReadMean(); //destructor
    double calculate();
private:
    ifstream in_strm;
};

#endif