#include <bits/stdc++.h>
using namespace std;

int main()
{
    map<int, string> mp;
    mp[1] = "one";
    mp[2] = "two";
    mp[3] = "three";
    mp[4] = "four";
    mp[5] = "five";
    mp[6] = "six";

    srand(time(NULL));

    for (int i = mp.size() - 1; i < 1; i--)
    {
        int ran = rand()% i - 1;
    }
    
    
    return 0;
}