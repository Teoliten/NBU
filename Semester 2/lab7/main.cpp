#include <iostream>
#include <string>

using namespace std;

#include "pqueue.h"
#include "comparator.h"

//! Print minimum of two elements 
/*!
    Print the minimum of two elements of parametrized data type, and parametrized comparator. 
    \tparam TElm        type of the elements to compare
    \tparam TCmp        type of the comparator
    \param  frst        first element
    \param  scnd        second element
    \param  isLess      comparator    
 */
template <typename TElm, typename TCmp>
void printMin(const TElm &frst, const TElm &scnd, TCmp &isLess)
{
    cout << (isLess(frst, scnd) ? frst : scnd) << endl;
}//printMin

//! Main function of the program 
/*!
    Main function of the program. Contains the code to test the priority queue.  
 */
int main()
{
    string frst = "14";
    string scnd = "7";
    CmpLexi cmpLexi;
    printMin(frst, scnd, cmpLexi);
    CmpInte cmpInte;
    printMin(frst, scnd, cmpInte);

   
    PQueue<string, CmpInte> pqueue;

    cout << "Size: " << pqueue.size() << endl;
    cout << pqueue.empty() << endl;

    pqueue.insert("14");
    pqueue.insert("023");
    pqueue.insert("5");
    pqueue.insert("423");
    pqueue.insert("7");

    cout << "Size: " << pqueue.size() << endl;
    cout << pqueue.empty() << endl;

    while (!pqueue.empty())
    {
        cout << pqueue.min() << endl;
        pqueue.removeMin();
    } 

    return 0;
}//main
