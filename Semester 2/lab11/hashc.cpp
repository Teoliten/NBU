#include <string>

using namespace std;

#include "hashc.h"

// class HCPolyStr

// variable of the polynomial
const int HCPolyCarr::VAR = 33;

// return the hash code for the given input string
// implements Horner's method
int // the calculated hash code
HCPolyCarr::operator()(
    const char *carr, // pointer to the character array
    int length        // number of characters
)
{
  int result = 0;
  for (int indx_pos = 0; indx_pos < length; indx_pos++)
  {
    result *= VAR;
    result += (int)carr[indx_pos];
  }

  return result;
} // operator()

// class HCPolyStr

// return the hash code for the given input string
int // the calculated hash code
HCPolyStr::operator()(
    const string &str // input string
)
{
  HCPolyCarr hesh_code;

  return hesh_code(str.c_str(), str.length());
} // operator()