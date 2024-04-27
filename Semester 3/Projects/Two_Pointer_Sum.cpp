#include <bits/stdc++.h>

using namespace std;

void findNumbers(vector<int> list, int target)
{
    int pointer1 = 0;
    int pointer2 = list.size() - 1;

    int sum = 0;
    while(pointer1 != pointer2)
    {
        sum = list[pointer1] + list[pointer2];

        if(sum == target)
        {
            cout << "Result: \n" << list[pointer1] << " + " << list[pointer2] << " = " << sum << endl;
            return;
        }

        if(sum > target)
            pointer2--;
        if(sum < target)
            pointer1++;
    }

    cout << "No solution found." << endl;
    
}

int main()
{
    //Given a sorted array, and target number, find two numbers that sum to target number.
    //Finds and displayed first solution, even if theres potentially more.
    int target;
    cin >> target;

    int input;
    cin >> input;
    vector<int> list;
    while(input)//read until 0;
    {
        list.push_back(input);
        cin >> input;
    }

    findNumbers(list, target);

    return 0;
}//main