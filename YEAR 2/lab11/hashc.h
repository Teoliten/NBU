#ifndef HASHC_H
#define HASHC_H

#include <string>

using namespace std;

//! Polynomial hash code for character array
/*!
    Implements polynomial hash code for character array.
 */
class HCPolyCarr
{
public:
  //! Overloaded operator ()
  /*!
      Return the hash code for the given input string.
      \param carr     pointer to the character array
      \param length   number of characters
      \return         the calculated hash code
   */
  int operator()(
      const char *carr,
      int length);

private:
  static const int VAR; /*!< variable of the polynomial */
};

//! Polynomial hash code for strings
/*!
    Implements polynomial hash code for strings.
 */
class HCPolyStr
{
public:
  //! Overloaded operator ()
  /*!
      Return the hash code for the given input string.
      \param str      input string
      \return         the calculated hash code
   */
  int operator()(
      const string &str);
};

#endif