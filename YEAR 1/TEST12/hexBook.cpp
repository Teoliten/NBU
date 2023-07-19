#include <iostream>
#include <fstream>
#include <sstream>
#include <string>

using namespace std;

class HexBook
{
public:
    HexBook();
    ~HexBook();
    void read();
    void write(/*const string &hex, const string &name*/);
private:
    string hex;
    string name;
    fstream f_strm;
    static const char* FILENAME;
    

};//HexBook

const char* HexBook::FILENAME = "colors.txt";

HexBook::HexBook()
{
    f_strm.open(FILENAME, ios::app);
    if(!f_strm.fail())
    {
        cout << "Opening: " << FILENAME << endl;
        string line;
        string hexP = line.substr(0, 7);
        string nameP = line.substr(8);
    }
    else
    {
        cout << "Error opening: " << FILENAME << endl;
    }
    

}//HexBook

HexBook::~HexBook()
{
    if(!f_strm.fail())
    {
        f_strm.close();
    }
}//~HexBook

void HexBook::write(/*const string &hex, const string &name*/)
{
    //f_strm BINGBONG("colors.txt", ios::app);
    f_strm << hex << " " << name << "\n";
}//write

void HexBook::read()
{
    cout << "Enter color in HEX format (#RRGGBB):" << endl << "> ";
    cin >> hex;

    cout << "Enter name for " << hex << endl << "> ";
    cin >> name;
}//read

int main()
{
    HexBook hx;
    hx.read();
    hx.write();
    
    
    return 0;
}//main