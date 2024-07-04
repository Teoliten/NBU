// Header Files
#include<iostream>
#include<string>
#include<vector>

#include <cmath> //sqrt function
using namespace std;


/*
 * bill, representing the bill amounts
 */
int countCustomers (vector<int> bill)
{
    int answer = 0;
    // Write your code here
	for(int i = 0; i < bill.size(); i++)
	{
		int sqr = sqrt(bill[i]);
		if(sqr * sqr == bill[i])
		{
			answer++;
		}
	}
    
    return answer;
}

int main()
{
    
	//input for bill
	int bill_size;
	cin >> bill_size;
	vector<int> bill;
	for ( int idx = 0; idx < bill_size; idx++ )
	{
		int temp;
		cin >> temp;
		bill.push_back(temp);
	}
	
    int result = countCustomers(bill);
	cout << result;
	
	
    return 0;
}
