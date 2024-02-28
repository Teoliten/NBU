// Header Files
#include<iostream>
#include<string>
#include<vector>
using namespace std;


/*
 * 
 */

template <typename S>
ostream& operator<<(ostream& os, const vector<S>& vector)
{
    for (auto element : vector) {
        os << element << " ";
    }
    return os;
}

int checkForMeat(vector<int> displayed, int size)
{
	for(int i = 0; i < size; i++)
	{
		if(displayed[i] < 0)
		{
			
			return displayed[i];
		}
	}
	return 0;
}

vector<int> orderPizza (vector<int> orderPlaced, int size)
{
    vector<int>  answer;
    // Write your code here
	vector<int> displayed;
	for(int i = 0; i < size; i++)
	{
		displayed.push_back(orderPlaced[i]);
	}
	cout << "On Screen: " << displayed << endl;
    answer.push_back(checkForMeat(displayed, size));

	for(int i = 0; i < size; i++)
	{
		displayed.erase(displayed.begin());
		displayed.push_back(orderPlaced[size + i]);
		cout << "D: " << displayed << endl;
		answer.push_back(checkForMeat(displayed, size));
	}
    return answer;
}

int main()
{
    
	//input for orderPlaced
	int orderPlaced_size;
	cin >> orderPlaced_size;
	vector<int> orderPlaced;
	for ( int idx = 0; idx < orderPlaced_size; idx++ )
	{
		int temp;
		cin >> temp;
		orderPlaced.push_back(temp);
	}
	//input for size
	int size;
	cin >> size;
	
	
    //output
	vector<int> result = orderPizza(orderPlaced, size);
	for ( int idx = 0; idx < result.size() - 1; idx++ )
	{
		cout << result[idx] << " ";
	}
	cout << result[result.size() - 1];
	
    return 0;
}
