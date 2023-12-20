#ifndef MAP_H
#define MAP_H

#include <string>
#include <stdexcept>
#include <list>

using namespace std;

class MapExcept : public runtime_error
{
public:
  MapExcept(const string &msg);
}; // Exception for the Map data structure.

MapExcept::MapExcept(const string &msg) : runtime_error(msg)
{
} // MaxExcept

//_______________MAP_______________
template <typename TKey, typename TVal>
class Map
{
public:
  //! Definition of the Entry.
  class Entry;

  //! Map iterator.
  typedef typename list<Entry>::iterator Iterator;

  //! Iterator to beginning
  Iterator begin();

  //! Iterator to the sentinel end
  Iterator end();

  //! Put key value into map.
  Iterator put(const TKey &key, const TVal &val);

  //! Find value by key
  Iterator find(const TKey key);

  //! Size of the map
  int size() const;

  //! Check wheter map is empty
  bool empty() const;

private:
  list<Entry> mlist; // map list

}; // Class Map
//_______________MAP_______________

//_______________ENTRY_______________
template <typename TKey, typename TVal>
class Map<TKey, TVal>::Entry
{
public:
  Entry(const TKey &key, const TVal &val); // parameter constructor

  void setKey(const TKey &key); // setter for key
  void setVal(const TVal &val); // setter for value

  const TKey &getKey() const; // getter for key
  const TVal &getVal() const; // getter for value

private:
  TKey key; //*!< key of el*/
  TVal val; //*!< value of el*/
};          // Class Entry

template <typename TKey, typename TVal>
Map<TKey, TVal>::Entry::Entry(const TKey &parameter_key, const TVal &parameter_val)
{
  key = parameter_key;
  val = parameter_val;
}

template <typename TKey, typename TVal>
const TKey &Map<TKey, TVal>::Entry::getKey() const
{
  return key;
} // getKey

template <typename TKey, typename TVal>
const TVal &Map<TKey, TVal>::Entry::getVal() const
{
  return val;
} // getVal

template <typename TKey, typename TVal>
void Map<TKey, TVal>::Entry::setKey(const TKey &key)
{
  this->key = key;
} // setKey

template <typename TKey, typename TVal>
void Map<TKey, TVal>::Entry::setVal(const TVal &val)
{
  this->val = val;
} // setVal

// Map member functions implementation
// iterator to the beginning
template <typename TKey, typename TVal>
typename Map<TKey, TVal>::Iterator Map<TKey, TVal>::begin()
{
  return mlist.begin();
} // begin

// iterator to sentinel end
template <typename TKey, typename TVal>
typename Map<TKey, TVal>::Iterator Map<TKey, TVal>::end()
{
  return mlist.end();
} // end

// put a key value pair into the map
template <typename TKey, typename TVal>
typename Map<TKey, TVal>::Iterator Map<TKey, TVal>::put(const TKey &key, const TVal &val)
{
  Iterator result;
  bool found = false;
  for (result = mlist.begin(); result != mlist.end() && (!found); ++result)
  {
    if (result->getKey() == key)
    {
      found = true;
      result->setVal(val);
    }
  }
  if (!found)
  {
    Entry ent(key, val);
    mlist.push_back(ent);
    result = mlist.end();
    --result;
  }
  return result;
} // put

// iterator to sentinel end
// template <typename TKey, typename TVal>

template <typename TKey, typename TVal>
inline int Map<TKey, TVal>::size() const
{
  return mlist.size();
} // size

template <typename TKey, typename TVal>
inline bool Map<TKey, TVal>::empty() const
{
  return mlist.empty();
} // empty

//_______________ENTRY_______________

#endif