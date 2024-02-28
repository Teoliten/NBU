#include <iostream>
#include <string>

using namespace std;

#include "hashc.h"
#include "hasht.h"

int main()
{
  // create a hash table of (string, int) pairs
  HashT<string, int, HCPolyStr> hash_table;

  // put data in the table
  hash_table.put(string("apple"), 42);
  hash_table.put(string("pear"), 17);
  hash_table.put(string("apricot"), 21);
  hash_table.put(string("banana"), 11);
  hash_table.put(string("grapes"), 61);

  // table empty and number of entries
  cout << "Hash table is " << (hash_table.empty() ? "empty" : "not empty") << "." << endl;
  cout << "Size: " << hash_table.size() << endl;

  // find an entry using the string key
  HashT<string, int, HCPolyStr>::Iterator iter = hash_table.find("pear");
  cout << (*iter).getKey() << " " << (*iter).getVal() << endl;

  // erase from the hash table
  hash_table.erase("banana");

  // print all entries in the hash table
  for (iter = hash_table.begin(); !(iter == hash_table.end()); ++iter)
  {
    cout << (*iter).getKey() << " " << (*iter).getVal() << endl;
  }

  return 0;
} // main