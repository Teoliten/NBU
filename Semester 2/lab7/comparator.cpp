#include <string>
#include <sstream>
#include <stdexcept>

using namespace std;

#include "comparator.h"

// implement class CmpLexi

// overloaded () operator
bool CmpLexi::operator ()(
            const string &left, 
            const string &rght
            )
{
    return left < rght;
}//operator ()

// implement class CmpInte

// convert string to integer
int CmpInte::toInt(
            const string &str           // input string that contains integer
            )
{
    istringstream in_str_strm(str);

    int result;
    in_str_strm >> result;

    if (in_str_strm.fail())
    {
        throw runtime_error("Inte::toInt: fail to convert to integer.");
    }

    return result;
}//toInt

// overloaded () operator
bool CmpInte::operator ()(
            const string &left, 
            const string &rght
            )
{
    return toInt(left) < toInt(rght);
}//operator ()
