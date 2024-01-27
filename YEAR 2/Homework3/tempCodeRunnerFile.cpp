#include <iostream>
#include "dictionary.h"

int main() {
    SortedDictionary<int, std::string> dict;

    // Insert key-value pairs
    dict.insert(1, "Apple");
    dict.insert(2, "Banana");
    dict.insert(1, "Cherry");
    dict.insert(3, "Date");
    dict.insert(2, "Elderberry");

    // Check if the dictionary is empty
    std::cout << "Is the dictionary empty? " << (dict.empty() ? "Yes" : "No") << std::endl;

    // Get the size of the dictionary
    std::cout << "Size of the dictionary: " << dict.size() << std::endl;

    // Find a key in the dictionary
    auto it = dict.find(3);
    if (it != dict.end()) {
        std::cout << "Found key 3 with values: ";
        for (const auto& value : it->second) {
            std::cout << value << " ";
        }
        std::cout << std::endl;
    } else {
        std::cout << "Key 3 not found" << std::endl;
    }

    // Erase a key from the dictionary
    dict.erase(1);
    std::cout << "Erased key 1" << std::endl;

    // Iterate through the dictionary using the iterator
    std::cout << "Entries in ascending order:" << std::endl;
    for (auto it = dict.begin(); it != dict.end(); ++it) {
        std::cout << "Key = " << it->first << ", Values = ";
        for (const auto& value : it->second) {
            std::cout << value << " ";
        }
        std::cout << std::endl;
    }

    // Try to find the erased key
    it = dict.find(1);
    std::cout << "Find erased key 1: " << (it != dict.end() ? "Found" : "Not found") << std::endl;

    return 0;
}
