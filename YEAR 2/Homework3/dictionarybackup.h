#ifndef DICTIONARY_H
#define DICTIONARY_H

#include <string>
#include <list>
#include <stdexcept>

using namespace std;

// ----------------- EXCEPTION HANDLERS -----------------
class DictionaryExcept : public runtime_error
{
    public:
        DictionaryExcept(const string &msg) : runtime_error(msg) {}
};

// ----------------- DICTIONARY -----------------
template <typename tkey, typename tval>
class Dictionary
{
public:
    class Entry;

    typedef typename list<Entry>::iterator Iterator;

    Iterator put(const tkey &key, const tval &val);
    int size() const;
    bool empty() const;
    Iterator find(const tkey &k);
    Iterator findAll(const tkey &k);
    bool erase(const tkey &key);
    bool erase(Iterator &iterator);
    Iterator begin();
    Iterator end();

private:
    int nr_entries;
    list<Entry> dictionary;
};//Class Dictionary


template <typename tkey, typename tval>
typename Dictionary<tkey, tval>::Iterator      // return iterator to the modified or new entry
    Dictionary<tkey, tval>::put(
            const tkey &key,            // key value 
            const tval &val             // data value
            )
{
    Iterator result;                    // resulting iterator
    bool found = false;                 // determines whether the key is found in the Dictionary 
    for (result = dictionary.begin(); result != dictionary.end(); ++result)
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
        dictionary.push_back(entr);          // append it at the end of the list
        result = dictionary.end();           // result points to the new entry
        --result;
    }  

    return result;
}//put

// find an entry into the Dictionary
template <typename tkey, typename tval>
typename Dictionary<tkey, tval>::Iterator      // return iterator to the modified or new entry
    Dictionary<tkey, tval>::find(
            const tkey &key             // key value 
            )
{
    Iterator result;                    // resulting iterator 
    for (result = dictionary.begin(); result != dictionary.end(); ++result)
    {
        if (result->getKey() == key)
        {
            break;
        }
    } 

    return result;                      // if not found, will point to the sentinel
}//find

template <typename tkey, typename tval>
bool Dictionary<tkey, tval>::erase(const tkey &key)
{
    for (Iterator iter = dictionary.begin(); iter != dictionary.end(); ++iter)
    {
        if (iter->getKey() == key)
        {
            dictionary.erase(iter);
            return true;
        }
    }

    return false;
}//erase(key)

template <typename tkey, typename tval>
bool Dictionary<tkey, tval>::erase(Iterator &iter)
{
    if (iter == dictionary.end())
    {
        return false;
    }

    dictionary.erase(iter);
    iter = dictionary.end();

    return true;
}//erase(iterator)

template <typename tkey, typename tval>
typename Dictionary<tkey, tval>::Iterator      // return iterator to the first element in the list
    Dictionary<tkey, tval>::begin()
{
    return dictionary.begin();
}//begin

// return iterator to the sentinel entry
template <typename TKey, typename tval>
typename Dictionary<TKey, tval>::Iterator      // return iterator to the end
    Dictionary<TKey, tval>::end()
{
    return dictionary.end();
}//end

// size of the Dictionary
template <typename TKey, typename tval>
int Dictionary<TKey, tval>::size() const
{
    return dictionary.size();
}//size

// check whether the Dictionary is empty 
template <typename TKey, typename tval>
bool Dictionary<TKey, tval>::empty() const
{
    return dictionary.empty();
}//empty

// ----------------- DICTIONARY -----------------

// ----------------- ENTRY -----------------
template <typename tkey, typename tval>
class Dictionary<tkey, tval>::Entry
{
    public:
        Entry(const tkey &key, const tval &val);
        void setKey(const tkey &key);
        void setVal(const tval &val);
        const tkey &getKey() const;
        const tval &getVal() const;

    private:
        tkey key;
        tval val;
};//Class Entry

template <typename tkey, typename tval>
Dictionary<tkey, tval>::Entry::Entry(const tkey &key, const tval &val)
{
    this->key = key;
    this->val = val;
}//Entry

template <typename tkey, typename tval>
void Dictionary<tkey, tval>::Entry::setKey(const tkey &key)
{
    this->key = key;
}//setKey

template <typename tkey, typename tval>
void Dictionary<tkey, tval>::Entry::setVal(const tval &val)
{
    this->val = val;
}//setVal

template <typename tkey, typename tval>
const tkey &Dictionary<tkey, tval>::Entry::getKey() const
{
    return key;
}//getKey

template <typename tkey, typename tval>
const tval &Dictionary<tkey, tval>::Entry::getVal() const
{
    return val;
}//getVal
// ----------------- ENTRY -----------------
#endif