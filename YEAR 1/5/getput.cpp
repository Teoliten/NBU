#include <iostream>
#include <fstream>
#include <string>

using namespace std;

//extract get and put positions and
void getput(const string &file_name)
{
    fstream in_strm;
    in_strm.open(file_name.c_str(), fstream::app);
    if(!in_strm.fail())
    {
        //extract get position
        long int get = in_strm.tellg();
        cout << "Get position: " << get << endl;

        //extract get position
        long int put = in_strm.tellp();
        cout << "Put position: " << put << endl;
    }
    else
    {
        cerr << "Cannot open file: " << file_name << endl;
    }
}//getput

int main()
{
    cout << ">";
    string file_name;
    cin >> file_name;

    getput(file_name);
    return 0;
}//main