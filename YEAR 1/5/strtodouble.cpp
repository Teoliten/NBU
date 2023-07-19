#include <iostream>
#include <string>
#include <sstream>

using namespace std;

double strToDouble(const string &inp)
{
    istringstream in_strm;
    in_strm.str(inp);
    double result;
    in_strm >> result;

    if(in_strm.fail())//if input is not double will enter fail state.
    {
        cerr << "Warning: wrong input data." << endl;
    }

    return result;
}//strToDouble

int main()
{
    cout << "Enter a floating point number: ";
    string inp;
    cin >> inp;

    double numb = strToDouble(inp);
    cout << numb << endl;
    return 0;
}//main