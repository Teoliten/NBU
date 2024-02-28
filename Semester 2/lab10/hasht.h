#ifndef HASHT_H
#define HASHT_H

#include <list>

HashTExcept

const string &msg) : runtime_error(msg)
{

} // HashTExcept

template <typename TKey, typename TVal, typename TCmp>
class HashT
{
public:
  class Entry;

  class Iterator

      private : enum
  {
    CPCT = 109
  }; // prime number

  typedef list<Entry> Bucket;    // Bucket data type
  typedef vector<Bucket> BArray; // Bucket array data type
  typedef typename BArray::iterator BIter;
  typedef typename Bucket::iterator EIter;
};

template <typename TKey, typename TVal, typename TCmp>
class HashT<TKey, TVal, TCmp>::Entry
{
public:
  Entry(const TKey &key, TVal &val);
  void setKey(const TKey &key); // setter
  void setVal(const TVal &val); // setter

private:
  TKey key;
  TVal val;
}; // class HashT

template <typename TKey, typename TVal, typename TCmp>
HashT<Tkey, TVal, TCmp>::Entry::Entry(const TKey &key, const TVal &val)
{
  this->key = key;
  this->val = val;
}

template <typename TKey, typename TVal, typename TCmp>
void HashT<TKey, TVal, TCmp>::Entry::setKey(const TKey &key)
{
  this->key = key;
} // setKey

template <typename TKey, typename TVal, typename TCmp>
void HashT<TKey, TVal, TCmp>::Entry::setVal(const TVal &val)
{
  this->val = val;
} // setVal

template <typename TKey, typename TVal, typename TCmp>
const TKey &HashT<TKey, TVal, TCmp>::Entry::getKey() const
{
  return key;
} // getKey

template <typename TKey, typename TVal, typename TCmp>
const TVal &HashT<TKey, TVal, TCmp>::Entry::getVal() const
{
  return val;
} // getVal

template <typename TKey, typename TVal, typename TCmp>
class HashT<TKey, TVal, TCmp>::Iterator
{
public:
  Iterator(const BArray &b_array, const BIter &b_iter, const EIter &e_iter = EIter());
  Entry &operator*() const; // Dereference operator
  bool operator==(const Iterator &iter) const;
  Iterator &operator++();

private:
  BIter b_iter;           // to array
  EIter e_iter;           // to entry
  const BArray *ptr_barr; // pointer to bucket array

  friend class HashT;
};

template <typename TKey, typename TVal, typename TCmp>
HashT<TKey, TVal, TCmp>::Iterator::Iterator(const BArray &b_array, const BIter &b_iter, const EIter &e_iter)
{
  this->ptr_barr = &b_array;
  this->b_iter = b_iter;
  this->e_iter = e_iter;
} // Iterator Iterator

template <typename TKey, typename TVal, typename TCmp>
typename HashT<TKey, TVal, TCmp>::Entry &HashT<TKey, TVal, TCmp>::Iterator::operator*() const
{
  return *e_iter;
} // operator *

template <typename TKey, typename TVal, typename TCmp>
bool HashT<TKey, TVal, TCmp>::Iterator::operator==(const Iterator &iter) const
{
  bool result = false;
  if (ptr_barr == iter.ptr_barr && b_iter == iter.b_iter)
  {
    if (b_iter == ptr_barr->end())
    {
      result = true;
    }
    else
    {
      result = (e_iter == iter.e_iter);
    }
  }

  return result;
} // operator *

template <typename TKey, typename TVal, typename TCmp>
typename HashT<TKey, TVal, TCmp>::Iterator r &HashT<TKey, TVal, TCmp>::Iterator::operator++()
{
  ++e_iter;
  if (e_iter == b_iter->end()) // end of the array
  {
    ++b_iter;

    while (b_iter != ptr_barr->end() && b_iter->empty())
    {
      ++b_iter;
    }

    if (b_iter != ptr_barr->end())
    {
      e_iter = b_iter->begin();
    }

    return *this;
  }
} // operator *

#endif