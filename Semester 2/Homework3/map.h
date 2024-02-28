#ifndef MAP_H
#define MAP_H

#include <string>
#include <list>
#include <stdexcept>

using namespace std;

//! Complete map exception class 
/*!
    Implements exceptions that are thrown by complete tree class member functions.  
 */
class MapExcept : public runtime_error
{
    public:

        //! Parameter constructor 
        /*!
            Construct an exception with an input message.
            \param msg      exception message 
         */
        MapExcept(const string &msg);
};

// class CTreeExcept implementation

// parameter constructor
MapExcept::MapExcept(const string &msg)
    : runtime_error(msg)
{
}//PQueueExcept

//! Map 
/*!
    Implements linked-list based map.
    \tparam TKey        type of the keys
    \tparam TVal        type of the data values 
 */
template <typename TKey, typename TVal>
class Map
{
    public:

        //! Entry data type. 
        /*!
            Implement the pair of key and data value.
         */
        class Entry;

        //! Iterator data type. 
        /*!
            The Iterator data type for the map is represented by the iterator of the linked list.
         */
        typedef typename list<Entry>::iterator Iterator;

        //! Put an entry in the map.
        /*!
            If an entry with the provided key already exists, replace the provided data value.
            Otherwise, append the new key-data value pair in the map list.
            \param key      key value
            \param val      data value
            \return         iterator to the position of the modified or new entry
         */
        Iterator put(const TKey &key, const TVal &val);

        //! Find an entry in the map.
        /*!
            If an entry with the provided key exists return an iterator pointing to it.
            Otherwise, return iterator that points to the sentinel end.
            \param key      key value
            \return         iterator to the position of the found entry
         */
        Iterator find(const TKey &key);

        //! Erase an entry given its key.
        /*!
            Search for a given key in the map, and if the entry with this key exists, delete it.
            If the key does not exist in the map, throw an exception.
            \param key      key value
         */
        void erase(const TKey &key);

        //! Erase an entry given its position.
        /*!
            Erase the entry given an iterator to its position. Set the iterator to sentinel.
            If the position already points to the sentinel, throw an exception.
            \param iter     position to the element to erase, set it to sentinel
         */
        void erase(Iterator &iter);

        //! Return iterator to the first entry.
        /*!
            Return iterator to the first element in the map linked list.
            \return         iterator to the first entry
         */
        Iterator begin();

        //! Return iterator to the sentinel entry.
        /*!
            Return iterator to the sentinel element in the map linked list.
            \return         iterator to the sentinel
         */
        Iterator end();

        //! Return the size of the map. 
        /*!
            Return the size of the map as number of entries stored in it.
            \return         size of the map
         */
        int size() const;

        //! Check whether the map is empty. 
        /*!
            Check whether the map is empty. Map is empty if the linked list is empty.
            \return         true if empty, false otherwise
         */
        bool empty() const;

    private:

        list<Entry> mlist;          /*!< list that contains map entries */

};

//! Entry 
/*!
    Implement the pair of key and data value. Entry is a nested class for class Map.
    \tparam TKey        type of the keys
    \tparam TVal        type of the data values 
 */
template <typename TKey, typename TVal>
class Map<TKey, TVal>::Entry
{
    public:

        //! Parameter constructor.
        /*!
            Initialize an entry object as a pair of key and data value.
            \param key      key value
            \param val      data value
         */
        Entry(const TKey &key, const TVal &val);

        //! Set key. 
        /*!
            Set key value of the pair.
            \param  key     key value
         */
        void setKey(const TKey &key);

        //! Set value. 
        /*!
            Set data value of the pair.
            \param  val     data value
         */
        void setVal(const TVal &val);

        //! Get key. 
        /*!
            Get key value of the pair.
            \returns        key value
         */
        const TKey &getKey() const;

        //! Get data value. 
        /*!
            Get key value of the pair.
            \returns        data value
         */
        const TVal &getVal() const;

    private:
        TKey key;           /*!< key value */
        TVal val;           /*!< data value */
};

// class Entry implementation

// parameter constructor
template <typename TKey, typename TVal>
Map<TKey, TVal>::Entry::Entry(const TKey &key, const TVal &val)
{
    this->key = key;
    this->val = val;
}//Entry

// set the key
template <typename TKey, typename TVal>
void Map<TKey, TVal>::Entry::setKey(const TKey &key)
{
    this->key = key;
}//setKey

// set the value
template <typename TKey, typename TVal>
void Map<TKey, TVal>::Entry::setVal(const TVal &val)
{
    this->val = val;
}//setVal

// get the key
template <typename TKey, typename TVal>
const TKey &Map<TKey, TVal>::Entry::getKey() const
{
    return key;
}//getKey

// get the value
template <typename TKey, typename TVal>
const TVal &Map<TKey, TVal>::Entry::getVal() const
{
    return val;
}//getVal

// class Map implementation

// put an entry into the map
template <typename TKey, typename TVal>
typename Map<TKey, TVal>::Iterator      // return iterator to the modified or new entry
    Map<TKey, TVal>::put(
            const TKey &key,            // key value 
            const TVal &val             // data value
            )
{
    Iterator result;                    // resulting iterator
    bool found = false;                 // determines whether the key is found in the map 
    for (result = mlist.begin(); result != mlist.end(); ++result)
    {
        if (result->getKey() == key)
        {
            found = true;               // key is found, stop on next iteration
            result->setVal(val);        // modify existing entry 
            break;
        }
    } 
    if (!found)                         // the key is not found
    {
        Entry entr(key, val);           // create a new entry         
        mlist.push_back(entr);          // append it at the end of the list
        result = mlist.end();           // result points to the new entry
        --result;
    }  

    return result;
}//put

// find an entry into the map
template <typename TKey, typename TVal>
typename Map<TKey, TVal>::Iterator      // return iterator to the modified or new entry
    Map<TKey, TVal>::find(
            const TKey &key             // key value 
            )
{
    Iterator result;                    // resulting iterator 
    for (result = mlist.begin(); result != mlist.end(); ++result)
    {
        if (result->getKey() == key)
        {
            break;
        }
    } 

    return result;                      // if not found, will point to the sentinel
}//find

// erase an element by its key
template <typename TKey, typename TVal>
void Map<TKey, TVal>::erase(const TKey &key)
{
    bool found = false;
    for (Iterator iter = mlist.begin(); !found && iter != mlist.end(); ++iter)
    {
        if (iter->getKey() == key)
        {
            found = true;
            mlist.erase(iter);
        }
    }

    if (!found)
    {
        throw MapExcept("Map::erase: Attempt to erase an non-existing key.");
    }
}//erase

// erase an element by its position
template <typename TKey, typename TVal>
void Map<TKey, TVal>::erase(Iterator &iter)
{
    if (iter == mlist.end())
    {
        throw MapExcept("Map::erase: Attempt to erase the sentinel entry.");
    }

    mlist.erase(iter);
    iter = mlist.end();
}//erase

// return iterator to the first entry
template <typename TKey, typename TVal>
typename Map<TKey, TVal>::Iterator      // return iterator to the first element in the list
    Map<TKey, TVal>::begin()
{
    return mlist.begin();
}//begin

// return iterator to the sentinel entry
template <typename TKey, typename TVal>
typename Map<TKey, TVal>::Iterator      // return iterator to the end
    Map<TKey, TVal>::end()
{
    return mlist.end();
}//end

// size of the map
template <typename TKey, typename TVal>
int Map<TKey, TVal>::size() const
{
    return mlist.size();
}//size

// check whether the map is empty 
template <typename TKey, typename TVal>
bool Map<TKey, TVal>::empty() const
{
    return mlist.empty();
}//empty

#endif
