#include <iostream>
#include <string>
#include <sstream>

using namespace std;

inline int hexToDecChar(char hex_char)
{
    return ((hex_char >= 0 && hex_char <= '9') ? hex_char - '0': 10 + hex_char - 'A');
}//hexToDecChar

int hexToDec(const string &hex_str)
{
    const int RAD = 16;
    
    int result = hexToDecChar(hex_str[0]);
    for(int i = 1; i < hex_str.length(); i++)
    {
        result *= RAD;
        result += hexToDecChar(hex_str[i]);
    }

    return result;
}//hexToDec

string hexToRGB(const string &hex_color)
{
    ostringstream out_strm;
    out_strm << "(";
    for(int i = 0; i <= 2; i+=2)
    {
        string color = hex_color.substr(i, 2);
        out_strm << hexToDec(color) << ", ";
    }
    string color = hex_color.substr(4, 2);
    out_strm << hexToDec(color) << ")";

    return out_strm.str();
}//hexToRGB

int main()
{
    cout << "Color code in HEX: ";
    string inp;
    cin >> inp;

    //cout << hexToDec(inp) << endl;
    cout << hexToRGB(inp) << endl;
    
    return 0;
}//main