#include <iostream>

using namespace std;

#include "dictionary.h"

int main() {
    Dictionary<int, string> dict;

    // Insert key value pairs
    dict.insert(1, "one");
    cout << "Inserting(Key = 1, Val = one)" << endl;
    dict.insert(2, "two");
    cout << "Inserting(Key = 2, Val = two)" << endl;
    dict.insert(1, "one.2");
    cout << "Inserting(Key = 1, Val = one.2)" << endl;
    dict.insert(3, "three");
    cout << "Inserting(Key = 3, Val = three)" << endl;
    dict.insert(2, "two.2");
    cout << "Inserting(Key = 2, Val = two.2)" << endl;

    Iterator<int, string> iterator = dict.begin();
    auto currentPair = *iterator;
    cout << "Key: " << currentPair.first << endl;

    // Check if the dictionary is empty
    cout << "Empty: " << dict.empty() << endl;

    // Get the size of the dictionary
    cout << "Size: " << dict.size() << endl;

    // Find a key in the dictionary using find 
    auto it = dict.find(3);
    if (it != dict.end()) {
        cout << "Found key 3 with values: ";
        for (const auto& value : (*it).second) 
        {
            cout << value << " ";
        }

        cout << endl;
    } 
    else 
    {
        cout << "Key 3 not found" << endl;
    }

    it = dict.begin();
    if (it != dict.end() && !(*it).second.empty()) 
    {
        cout << "Key = " << (*it).first << ", First Value = " << (*it).second[0] << endl;
    } 
    else 
    {
        cout << "Iterator is at the end or values vector is empty." << endl;
    }

    // Erase a key from the dictionary
    dict.erase(1);
    cout << "Erased key 1" << endl;

    // Try to find the erased key
    it = dict.find(1);
    cout << "Find erased key 1: " << (it != dict.end() ? "Found" : "Not found") << endl;

    // Iterate through the dictionary using the iterator
    cout << "All elements in dictionary:" << endl;
    for (auto it = dict.begin(); it != dict.end(); ++it) 
    {
        cout << "Key = " << (*it).first << ", Values = ";

        for (const auto& value : (*it).second) 
        {
            cout << value << " ";
        }
        cout << endl;
    }
   
    return 0;
}
