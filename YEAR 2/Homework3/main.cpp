#include <iostream>

using namespace std;

#include "dictionary.h"

int main() {
    Dictionary<int, string> dict;

    // Insert key-value pairs
    dict.insert(1, "one");
    dict.insert(2, "two");
    dict.insert(1, "one.2");
    dict.insert(3, "three");
    dict.insert(2, "two.2");

    // Check if the dictionary is empty
    cout << "Empty: " << dict.empty() << endl;

    // Get the size of the dictionary
    cout << "Size: " << dict.size() << endl;

    // Find a key in the dictionary
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

    // Erase a key from the dictionary
    dict.erase(1);
    cout << "Erased key 1" << endl;

    // Iterate through the dictionary using the iterator
    cout << "Entries in ascending order:" << endl;
    for (auto it = dict.begin(); it != dict.end(); ++it) 
    {
        cout << "Key = " << (*it).first << ", Values = ";

        for (const auto& value : (*it).second) 
        {
            cout << value << " ";
        }
        cout << endl;
    }

    // Try to find the erased key
    it = dict.find(1);
    cout << "Find erased key 1: " << (it != dict.end() ? "Found" : "Not found") << endl;

    return 0;
}
