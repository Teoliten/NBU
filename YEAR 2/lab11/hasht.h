#ifndef HASHT_H
#define HASHT_H

#include <list>
#include <vector>
#include <stdexcept>

using namespace std;

//! Complete hash table exception class
/*!
    Implements exceptions that are thrown by complete hash table class member functions.
 */
class HashTExcept : public runtime_error
{
public:
  //! Parameter constructor
  /*!
      Construct an exception with an input message.
      \param msg      exception message
   */
  HashTExcept(const string &msg);
};

// class HashTExcept implementation

// parameter constructor
HashTExcept::HashTExcept(const string &msg)
    : runtime_error(msg)
{
} // PQueueExcept

//! HashT
/*!
    Implements hash map based on hashing with separate chaining.
    \tparam TKey        type of the keys
    \tparam TVal        type of the data values
    \tparam TCmp        type of the hash comparator
 */
template <typename TKey, typename TVal, typename TCmp>
class HashT
{
public:
  //! Entry data type.
  /*!
      Implement the pair of key and data value.
   */
  class Entry;

  //! Iterator data type.
  /*!
      The Iterator will store the position of an element defined by:
      (1) the bucket position; (2) the entry position in the particular bucket.
   */
  class Iterator;

  //! Parameter constructor.
  /*!
      Initialize hash table with the given capacity.
      \param cpct     capacity of the bucket array
   */
  HashT(int cpct = CPCT);

  //! Check if hash table is empty.
  /*!
      Check if hash table is empty. Empty if no entries inside.
      \return         true if empty, false otherwise
   */
  bool empty() const;

  //! Return size of the hash table.
  /*!
      Return size of the hash table. The size is the number of entries.
      \return        size of the hash table
   */
  int size() const;

  //! Return iterator to the beginning of the hash table.
  /*!
      Return iterator to the beginning of the has table, that is the beginning of the bucket array.
      \return         iterator to the beginning
   */
  Iterator begin();

  //! Return iterator to the end of the hash table.
  /*!
      Return iterator to the end of the has table, that is the end of the bucket array.
      \return         iterator to the end
   */
  Iterator end();

  //! Find an entry.
  /*!
      Function to find an entry, and return an iterator to it.
      \return         iterator to the entry
   */
  Iterator find(const TKey &key);

  //! Put an entry.
  /*!
      Function to put an entry as key-value pair, and return an iterator to it.
      \param  key     key
      \param  val     value
      \return         iterator to the entry
   */
  Iterator put(const TKey &key, const TVal &val);

  //! Erase an entry given an iterator.
  /*!
      Erase an entry given an iterator that points to it.
      \param  iter    iterator pointing to the entry to be erased
   */
  void erase(const Iterator &iter);

  //! Erase an entry given its key.
  /*!
      Erase an entry given its key, or throw an exception if key is not in the table.
      \param  key     key of an entry to erase
   */
  void erase(const TKey &key);

private:
  //! Integer constants enumerator.
  /*!
      Integer constants enumerator, stores the default capacity.
   */
  enum
  {
    CPCT = 109
  };

  //! Bucket data type.
  /*!
      Bucket is a linked list that contains Entry objects.
   */
  typedef list<Entry> Bucket;

  //! Bucket array data type.
  /*!
      Bucket array is a vector of Bucket objects.
   */
  typedef vector<Bucket> BArray;

  //! Entry iterator data type.
  /*!
      Entry iterator navigates position into a given bucket object.
   */
  typedef typename Bucket::iterator EIter;

  //! Bucket iterator data type.
  /*!
      Bucker iterator navigates position into the array of buckets.
   */
  typedef typename BArray::iterator BIter;

  int numb;    /*!< number of elements, different from capacity */
  TCmp hash;   /*!< hash code comparator */
  BArray barr; /*!< bucket array, it stores capacity */

  //! Utility to find an entry.
  /*!
      Utility function to find an entry, and return an iterator to it.
      \param  key     key to be found
      \return         iterator to the entry
   */
  Iterator finder(const TKey &key);

  //! Utility to insert an entry.
  /*!
      Utility function to insert an entry, and return an iterator to it.
      \param  iter    insert before iterator
      \param  ent     entry to insert
      \return         iterator to the entry
   */
  Iterator inserter(const Iterator &iter, const Entry &ent);

  //! Utility to erase an entry.
  /*!
      Utility function to erase an entry.
      \param  iter    iterator pointing to the entry to be erased
   */
  void eraser(const Iterator &iter);
};

//! Entry
/*!
    Implement the pair of key and data value. Entry is a nested class for class HashT.
    \tparam TKey        type of the keys
    \tparam TVal        type of the data values
    \tparam TCmp        type of the hash comparator
 */
template <typename TKey, typename TVal, typename TCmp>
class HashT<TKey, TVal, TCmp>::Entry
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
      \return         key value
   */
  const TKey &getKey() const;

  //! Get data value.
  /*!
      Get key value of the pair.
      \return         data value
   */
  const TVal &getVal() const;

private:
  TKey key; /*!< key value */
  TVal val; /*!< data value */
};

// class Entry implementation

// parameter constructor
template <typename TKey, typename TVal, typename TCmp>
HashT<TKey, TVal, TCmp>::Entry::Entry(const TKey &key, const TVal &val)
{
  this->key = key;
  this->val = val;
} // Entry

// set the key
template <typename TKey, typename TVal, typename TCmp>
void HashT<TKey, TVal, TCmp>::Entry::setKey(const TKey &key)
{
  this->key = key;
} // setKey

// set the value
template <typename TKey, typename TVal, typename TCmp>
void HashT<TKey, TVal, TCmp>::Entry::setVal(const TVal &val)
{
  this->val = val;
} // setVal

// get the key
template <typename TKey, typename TVal, typename TCmp>
const TKey &HashT<TKey, TVal, TCmp>::Entry::getKey() const
{
  return key;
} // getKey

// get the value
template <typename TKey, typename TVal, typename TCmp>
const TVal &HashT<TKey, TVal, TCmp>::Entry::getVal() const
{
  return val;
} // getVal

//! Iterator
/*!
    Implement the Iterator of the hash table.
    The Iterator will store the position of an element defined by:
    (1) the bucket position; (2) the entry position in the particular bucket.
    Iterator is a nested class in the class HashT.
    \tparam TKey        type of the keys
    \tparam TVal        type of the data values
    \tparam TCmp        type of the hash comparator
 */
template <typename TKey, typename TVal, typename TCmp>
class HashT<TKey, TVal, TCmp>::Iterator
{
public:
  //! Parameter constructor.
  /*!
      Initialize an iterator object.
      \param b_array          container bucket array object
      \param b_iter           bucket array iterator
      \param e_iter           entry iterator, default value by default constructor of vector::iterator
   */
  Iterator(const BArray &b_array, const BIter &b_iter, const EIter &e_iter = EIter());

  //! Dereference operator.
  /*!
      Redefine dereference operator for the iterator.
      \return         Entry object pointed by the iterator
   */
  Entry &operator*() const;

  //! Comparison equal to operator.
  /*!
      Redefine equal to for the iterator.
      \param iter             iterator that is right hand side operand
      \return                 true if equal, false otherwise
   */
  bool operator==(const Iterator &iter) const;

  //! Increment operator.
  /*!
      Redefine increment operator to move the iterator to the next position.
      \return         iterator to the new position
   */
  Iterator &operator++();

private:
  BIter b_iter;           /*!< iterator to the bucket in the bucket array */
  EIter e_iter;           /*!< iterator to the entry inside the given bucket */
  const BArray *ptr_barr; /*!< pointer to the bucket array to which the iterator is attached */

  friend class HashT;
};

// class Iterator implementation

// parameter constructor
template <typename TKey, typename TVal, typename TCmp>
HashT<TKey, TVal, TCmp>::Iterator::Iterator(
    const BArray &b_array,
    const BIter &b_iter,
    const EIter &e_iter)
{
  this->ptr_barr = &b_array;
  this->b_iter = b_iter;
  this->e_iter = e_iter;
} // Iterator

// dereference operator
template <typename TKey, typename TVal, typename TCmp>
typename HashT<TKey, TVal, TCmp>::Entry &
HashT<TKey, TVal, TCmp>::Iterator::operator*() const
{
  return *e_iter;
} // operator *

// equal to operator
template <typename TKey, typename TVal, typename TCmp>
bool HashT<TKey, TVal, TCmp>::Iterator::operator==(
    const Iterator &iter) const
{
  bool result = false;
  // check if same hash table, and same bucket
  if (ptr_barr == iter.ptr_barr && b_iter == iter.b_iter)
  {
    // both point to the end of the bucket array
    // at that point b_iter and iter.b_iter point to the same bucket
    if (b_iter == ptr_barr->end())
    {
      result = true;
    }
    else
    {
      // result depend on whether two entry iterators are equal
      result = (e_iter == iter.e_iter);
    }
  }

  return result;
} // operator ==

// increment operator
template <typename TKey, typename TVal, typename TCmp>
typename HashT<TKey, TVal, TCmp>::Iterator &
HashT<TKey, TVal, TCmp>::Iterator::operator++()
{
  // move entry iterator to next in the current bucket
  ++e_iter;
  // check whether the end of the bucket is reached
  if (e_iter == b_iter->end()) // !!!
  {
    // move to the next bucket
    ++b_iter;
    // find next non-empty bucket
    while (b_iter != ptr_barr->end() && b_iter->empty())
    {
      ++b_iter;
    }
    // check whether the end of the bucket array is reached
    if (b_iter != ptr_barr->end())
    {
      // first non-empty entry
      e_iter = b_iter->begin();
    }
  }
  return *this;
} // operator ++

// class HashT implementation

// utility to find an entry.
template <typename TKey, typename TVal, typename TCmp>
typename HashT<TKey, TVal, TCmp>::Iterator
HashT<TKey, TVal, TCmp>::finder(const TKey &key)
{
  // get index corresponding to the key: hash code and compress
  int indx = hash(key) % barr.size();

  // get the bucket at position indx
  BIter b_iter = barr.begin() + indx;

  // search for the key
  Iterator iter(barr, b_iter, b_iter->begin());
  while (iter.e_iter != iter.b_iter->end() && (*iter).getKey() != key)
  {
    ++(iter.e_iter); // next entry
  }

  return iter;
} // finder

// utility to insert an entry
template <typename TKey, typename TVal, typename TCmp>
typename HashT<TKey, TVal, TCmp>::Iterator
HashT<TKey, TVal, TCmp>::inserter(const Iterator &iter, const Entry &ent)
{
  EIter e_iter = iter.b_iter->insert(iter.e_iter, ent);
  numb++;

  return Iterator(barr, iter.b_iter, e_iter);
} // inserter

// utility to erase an entry.
template <typename TKey, typename TVal, typename TCmp>
void HashT<TKey, TVal, TCmp>::eraser(const Iterator &iter)
{
  // from the given bucket (linked list) erase the entry
  iter.b_iter->erase(iter.e_iter);
  numb--;
} // eraser

// parameter constructor
template <typename TKey, typename TVal, typename TCmp>
HashT<TKey, TVal, TCmp>::HashT(int cpct) : barr(cpct)
{
  numb = 0;
} // HashT

// check if the hash table is empty
template <typename TKey, typename TVal, typename TCmp>
bool HashT<TKey, TVal, TCmp>::empty() const
{
  return (numb == 0);
} // empty

// return size of the hash table
template <typename TKey, typename TVal, typename TCmp>
int HashT<TKey, TVal, TCmp>::size() const
{
  return numb;
} // size

// return iterator to the beginning of the hash table
template <typename TKey, typename TVal, typename TCmp>
typename HashT<TKey, TVal, TCmp>::Iterator
HashT<TKey, TVal, TCmp>::begin()
{
  // if empty, return the end
  if (empty())
  {
    return end();
  }

  // search an entry
  BIter b_iter = barr.begin();
  while (b_iter->empty())
  {
    // find non-empty bucket
    ++b_iter;
  }

  return Iterator(barr, b_iter, b_iter->begin());
} // end

// return iterator to the end of the hash table
template <typename TKey, typename TVal, typename TCmp>
typename HashT<TKey, TVal, TCmp>::Iterator
HashT<TKey, TVal, TCmp>::end()
{
  return Iterator(barr, barr.end());
} // end

// find an entry (uses utility function)
template <typename TKey, typename TVal, typename TCmp>
typename HashT<TKey, TVal, TCmp>::Iterator
HashT<TKey, TVal, TCmp>::find(const TKey &key)
{
  Iterator iter = finder(key);

  if (iter.e_iter == iter.b_iter->end())
  {
    return end();
  }
  else
  {
    return iter;
  }
} // finder

// put an entry
template <typename TKey, typename TVal, typename TCmp>
typename HashT<TKey, TVal, TCmp>::Iterator
HashT<TKey, TVal, TCmp>::put(const TKey &key, const TVal &val)
{
  // search for the key
  Iterator iter = finder(key);
  if (iter.e_iter == iter.b_iter->end())
  {
    // if key is not found, insert new pair
    iter = inserter(iter, Entry(key, val));
  }
  else
  {
    // if key exists, replace
    iter.e_iter->setVal(val);
  }

  return iter;
} // put

// erase an entry given an iterator to it
template <typename TKey, typename TVal, typename TCmp>
void HashT<TKey, TVal, TCmp>::erase(const Iterator &iter)
{
  // directly call utility function
  eraser(iter);
} // erase

// erase an entry given its key
template <typename TKey, typename TVal, typename TCmp>
void HashT<TKey, TVal, TCmp>::erase(const TKey &key)
{
  // find the key in the map
  Iterator iter = finder(key);
  if (iter.e_iter == iter.b_iter->end())
  {
    // end of the bucket
    // the key is not present in the hash table
    throw HashTExcept("HashT:erase(): key is not present in the hash table.");
  }

  // if the entry is found, call utility function
  eraser(iter);
} // erase

#endif