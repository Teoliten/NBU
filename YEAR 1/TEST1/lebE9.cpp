#include <iostream>
#include <sstream>
#include <fstream>
#include <string>

using namespace std;

class StudBook
{
public:
    StudBook();
    ~StudBook();
    void write(const string &fname, const string &surname, int fnumb);
    string read(int indx_rec);

private:
    //static const char* FILENAME;
    const string FILENAME = "students.dat";
    static const int REC_SIZE;

    fstream in_strm;
    int numb_rec;
    void writeStr(const string &str);
    void writeNum(int num);
};

//const char* StudBook::FILENAME = "students.dat";

const int StudBook::REC_SIZE = 16;

StudBook::StudBook()
{
    in_strm.open(FILENAME);
    if(!in_strm.fail())
    {
        in_strm.seekg(0, ios::end); //put getter at end of file
        long int file_len = in_strm.tellg();  // get file len from getters pos.
        numb_rec = file_len / (REC_SIZE * 3); // how many students
        in_strm.seekg(0, ios::beg);
    }
    else
    {
        cout << "Error opening file: " << FILENAME << endl;
    }
}

StudBook::~StudBook()
{
    if(!in_strm.fail())
    {
        in_strm.close();
    }
}

void StudBook::write(const string &fname, const string &sname, int fnumb)
{
    if(!in_strm.fail())
    {
        writeStr(fname);
        writeStr(sname);
        in_strm.write("F", 1);
        writeNum(fnumb);
    }
}//write

void StudBook::writeStr(const string &str)
{
    char buff[REC_SIZE + 1];
    for(int i = 0; i < str.size(); i++)
    {
        buff[i] = str[i];
    }
    for(int i = str.size(); i < REC_SIZE; i++)
    {
        buff[i] = ' ';
    }
    buff[REC_SIZE] = ' ';
    in_strm.write(buff, REC_SIZE);
}//writeStr

void StudBook::writeNum(int num)
{
    ostringstream out_strm;
    out_strm << num;
    writeStr(out_strm.str());
}

string StudBook::read(int indx_rec)
{
    string result = "null";
    if(indx_rec >= 0 && indx_rec < numb_rec)
    {
        ostringstream out_strm;
        in_strm.seekg(indx_rec * REC_SIZE * 3);
        result = "";
        for(int i = 0; i < 3; i++)
        {
            string buff;
            in_strm >> buff;
            result += buff;
        }
    }
    return result;
}//read
    
int main()
{
    StudBook sbook;
    sbook.write("Apes", "Daniels", 111067);
    sbook.write("Rick", "Sanchez", 101010);
    sbook.write("Morty", "Smith", 202020);
    sbook.write("Summer", "Smith", 303030);

  
        cout << sbook.read(1) << endl;
    
    return 0;
}//main