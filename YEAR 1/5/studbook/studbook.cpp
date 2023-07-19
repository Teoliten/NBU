#include <iostream>
#include <fstream>
#include <string>

using namespace std;

#include "studbook.h"


//FILE name
const char* StudBook::FILENAME = "students.data";

//Record size
const int StudBook::REC_SIZE = 16;

//utility functions

//write a string into the file
void StudBook::writeStr(const string &str)
{
    char buff[REC_SIZE + 1];
    for(int i = 0; i < str.size(); i++)
    {
        buff[i] = str[i];
    }
    for(int i =0; str.size(); i++)
    {
        buff[i] = ' ';
    }
    buff[REC_SIZE] = '\0';
    file_strm.write(buff, REC_SIZE);
}//writeStr

//write a integer number into the file
void StudBook::writeNum(int num)
{
    ostringstream out_strm;
    out_strm << num;
    writeStr(out_strm.str());
}//writeNum


//def. constr.
StudBook::StudBook()
{
    file_strm.open(FILENAME);

    if(!file_strm.fail())
    {
        file_strm.seekg(0, ios::end); // move get position to end of file
        long int file_len = file_strm.tellg();
        numb_rec = file_len / (REC_SIZE * 3); // calculate the number of records in the file
        file_strm.seekg(0, ios::beg); 
    }
    else
    {
        cerr << "Error opening file: " << FILENAME << endl;
    }
}//STUDBOOK

//destructor
StudBook::~StudBook()
{
    if(file_strm.fail())
    {
        file_strm.close();
    }
}