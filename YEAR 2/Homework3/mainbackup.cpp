#include <iostream>

using namespace std;

#include "dictionary.h"

int main()
{
    Dictionary<int, string> D;

    // Put entries into the dictionary
    Dictionary<int, string>::Iterator iterator = D.put(1, "one");
    D.put(3, "three");
    D.put(2, "two");

    // Find an entry
    iterator = D.find(2);

    // Erase the entry found
    if (D.erase(iterator))
    {
        cout << "Entry with key 2 successfully erased.\n";
    }
    else
    {
        cout << "Entry with key 2 not found or could not be erased.\n";
    }

    // Check if the dictionary is empty
    if (D.empty())
    {
        cout << "Dictionary is empty.\n";
    }
    else
    {
        cout << "Dictionary is not empty.\n";
    }

    return 0;
}
