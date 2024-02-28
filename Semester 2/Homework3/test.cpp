#include <iostream>
#include <string>

using namespace std;

#include "map.h"

int main()
{
    Map<int, string> map;

    Map<int, string>::Iterator iter = map.put(2, "apple");
    iter = map.put(1, "pen");
    iter = map.put(3, "pineapple");

    iter = map.find(2);

    map.erase(iter);
    // map.erase(iter); // with throw exception

    if (iter != map.end())
    {
        cout << iter->getKey() << " " << iter->getVal() << endl;
    }

    map.erase(1);

    cout << "Map size: " << map.size() << endl;
    cout << (map.empty() ? "Empty." : "Contains entries.") << endl;

    return 0;
}//main