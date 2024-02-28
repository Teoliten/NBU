#ifndef COMPARATOR_H
#define COMPARATOR_H

#include <string>

using namespace std;

//! Lexicographic order comparator class for strings 
/*!
    Compare two strings in lexicographic order.  
 */
class CmpLexi
{
    public:

        //! Overloaded operator () 
        /*!
            Compare two strings in lexicographic order.
            \param left     left string operand
            \param rght     right string operand 
         */
        bool operator ()(
            const string &left, 
            const string &rght
            ); 
};

//! Numeric integer order comparator class for strings 
/*!
    Compare two strings as integer values that are stored in them.  
 */
class CmpInte
{
    public:

        //! Overloaded operator () 
        /*!
            Compare two strings in numeric integer order.
            \param left     left string operand
            \param rght     right string operand 
         */
        bool operator ()(
            const string &left, 
            const string &rght
            ); 

    private:

        //! Convert string to integer 
        /*!
            Convert a string that contains an integer to integer.
            \param str      string that contains an integer
            \return         resulting integer
         */
        int toInt(
            const string &str
            );
};

#endif
