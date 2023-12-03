#ifndef PQUEUE_H
#define PQUEUE_H

#include <iostream>
#include <string>
#include <list>
#include <stdexcept>

using namespace std;

//! Priority queue exception class 
/*!
    Implements exceptions that are thrown by priority queue class member functions.  
 */
class PQueueExcept : public runtime_error
{
    public:

        //! Parameter constructor 
        /*!
            Construct an exception with an input message.
            \param msg      exception message 
         */
        PQueueExcept(const string &msg);
};

// class PQueueExcept implementation

// parameter constructor
PQueueExcept::PQueueExcept(const string &msg)
    : runtime_error(msg)
{
}//PQueueExcept

//! Priority queue 
/*!
    Implements priority queue based on sorted STL linked list.
    \tparam TElm        type of the elements to compare
    \tparam TCmp        type of the comparator  
 */
template <typename TElm, typename TCmp>
class PQueue
{
    public:

        //! Size of the priority queue 
        /*!
            Size of the priority queue is the number of elements.
            \return     number of elements in the priority queue
         */
        int size() const;

        //! Check whether the priority priority queue is empty 
        /*!
            Predicate function to check whether the priority queue is empty.
            \return         true if empty, false otherwise
         */
        bool empty() const;

        //! Insert an element in the priority queue 
        /*!
            Find the appropriate location, and insert a new element in the priority queue.
            \param  elm     element to be inserted in the priority queue
         */
        void insert(const TElm &elm);

        //! Access the minimum element 
        /*!
            Return constant reference to the minimum element. This function cannot change the value.
            \return         minimum element
         */
        const TElm &min() const;

        //! Remove the minimum element 
        /*!
            Remove the minimum element from the priority queue
         */
        void removeMin();
    private:
        list<TElm> llist;   /*!< linked list container */
        TCmp isLess;        /*!< comparator */
};

// implement class PQueue

// size of the priority queue
template <typename TElm, typename TCmp>
int PQueue<TElm, TCmp>::size() const
{
    return llist.size();
}//size

// check whether the priority queue is empty
template <typename TElm, typename TCmp>
bool PQueue<TElm, TCmp>::empty() const
{
    return llist.empty();
}//empty

// insert an element in the appropriate place
template <typename TElm, typename TCmp>
void PQueue<TElm, TCmp>::insert(const TElm &elm)
{
    typename list<TElm>::iterator iter;
    iter = llist.begin();
    while (iter != llist.end() && !isLess(elm, *iter))
    {
        ++iter;
    }
    llist.insert(iter, elm);
}//insert

// access the min element
template <typename TElm, typename TCmp>
const TElm &PQueue<TElm, TCmp>::min() const
{
    if (llist.empty())
    {
        throw PQueueExcept("PQueue::min(): access empty priority queue.");
    }
    return llist.front();
}//min

//remove minimum element
template <typename TElm, typename TCmp>
void PQueue<TElm, TCmp>::removeMin()
{
    if (llist.empty())
    {
        throw PQueueExcept("PQueue::removeMin(): access empty priority queue.");
    }

    llist.pop_front();
}//removeMin

#endif
