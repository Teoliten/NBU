#include <iostream>
#include <fstream>
#include <istream>
#include <string>

using namespace std;

void getput(const string &in_filename)
{
    fstream in_strm;
    in_strm.open(in_filename.c_str(), fstream::app);
    if(!in_strm.fail())
    {
        in_strm.seekg(0, ios::end);
        long int file_len = in_strm.tellg();

        /*
        long int get = in_strm.tellg(); // extract get position
        cout << "Get position:" << get << endl;
        long int put = in_strm.tellp();
        cout << "Put position:" << put << endl;*/
        cout << file_len << " characters." << endl;
        in_strm.close();
    }
    else
    {
        cout << "Cannot open " << in_filename << endl;
    }

}

int main()
{
    cout << "Enter file name: " << endl << ">";
    string filename;
    cin >> filename;
    getput(filename);
    return 0;
}//main