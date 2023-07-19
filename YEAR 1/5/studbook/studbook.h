#ifndef STUDBOOK_H
#define STUDBOOK_H

#include <string>

#include <fstream>

using namespace std;

class StudBook
{
public:
    //default constructor
    StudBook();

    //destructor
    ~StudBook();

    //store data record in the file
    void write(
        const string&fname, 
        const string &lname, 
        int fnumb
    );

private:
    //constants
    static const char* FILENAME; // file name
    static const int REC_SIZE; // record size

    //data fields
    fstream file_strm;          //file stream
    int numb_rec;                 //numbers of records

    //utility functions 
    void writeStr(const string &str);
    void writeNum(int num);
};

#endif