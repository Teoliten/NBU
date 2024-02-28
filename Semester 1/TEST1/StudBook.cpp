#include <iostream>
#include <fstream>
#include <sstream>
#include <string>

using namespace std;

#include "StudBook.h"

const char* StudBook::FILENAME
    = "students.dat";

const int StudBook::REC_SIZE
    = 16;

StudBook::StudBook()
{
    in_strm.open(FILENAME);
    if (!in_strm.fail())
    {
        in_strm.seekg(0, ios::end);
        long int file_len = in_strm.tellg();
        numb_rec = file_len / (REC_SIZE * 3);
        in_strm.seekg(0, ios::beg);
    }
    else
    {
        cerr << "Error opening: "
            << FILENAME
            << endl;
    }
}//StudBook

StudBook::~StudBook()
{
    if (!in_strm.fail())
    {
        in_strm.close();
    }
}//~StudBook

void StudBook::write(
        const string &fname,
            const string &sname,
            int fnumb
            )
{
    if(!in_strm.fail())
    {
        writeStr(fname);
        writeStr(sname);
        in_strm.write("F", 1);
        writeNum(fnumb);
    }
}//write 

void StudBook::writeStr(
        const string &str
        )
{
    char buff[REC_SIZE + 1];
    for (int i = 0; i < str.size(); i++)
    {
        buff[i] = str[i];
    }
    for (int i = str.size(); i < REC_SIZE; i++)
    {
        buff[i] = ' ';
    }
    buff[REC_SIZE] = '\0';
    in_strm.write(buff, REC_SIZE);
}//writeStr

void StudBook::writeNum(int num)
{
    ostringstream out_strm;
    out_strm << num;
    writeStr(out_strm.str());
}//writeNum

string StudBook::read(int indx_rec)
{
    string result = "null";
    if (indx_rec >= 0 && indx_rec < numb_rec)
    {
        ostringstream out_strm;
        in_strm.seekg(indx_rec * REC_SIZE * 3);
        result = "";
        for (int i = 0; i < 3; i++)
        {
            string buff;
            in_strm >> buff;
            result += buff;
        }
    }

    return result;
}//read
