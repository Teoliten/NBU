#ifndef STUDBOOK_H
#define STUDBOOK_H

#include <fstream>
#include <string>

using namespace std;

class StudBook
{
    public:
        StudBook();
        ~StudBook();
        void write(
            const string &fname,
            const string &sname,
            int fnumb
            );
        string read(int indx_rec);

    private:
        static const char* FILENAME;
        static const int REC_SIZE;
        
        fstream in_strm;
        int numb_rec;
        void writeStr(
                 const string &str
                );
        void writeNum(int num);
};

#endif
