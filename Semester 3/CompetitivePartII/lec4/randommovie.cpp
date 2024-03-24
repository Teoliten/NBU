#include <bits/stdc++.h>

using namespace std;

void print(vector<pair<string, int>> arr)
{
    int length = arr.size();
    // cout << length;

    while (length)
    {
        int randNR = rand() % arr.size();
        if(arr[randNR].second == 1)
        {
            cout << arr[randNR].first << endl;
            arr[randNR].second = 0;
            length--;
        }
    }
}

int main()
{
    srand (time(NULL));
    vector<pair<string, int>> arr = {{"movie1", 1}, {"movie2", 1}, {"movie3", 1}, {"movie4", 1}, {"movie5", 1}, {"movie6", 1}};
    print(arr);
    return 0;
}