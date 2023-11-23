#include <iostream>

using namespace std;

const int SIZE = 8;

void readArr(double arr[], int size)
{
	for (int i = 0; i < size; i++)
	{
		cout << i << ": ";
		cin >> *(arr + i); // arr[i]
	}
}//readArr

void printArr(const double arr[], int size)
{
	for (int i = 0; i < size; i++)
	{
		cout << *(arr + i) << " ";
	}

	cout << endl;
}//printArr

int main()
{
	double arr[SIZE];

	readArr(arr, SIZE);
	printArr(arr, SIZE);

	return 0;	
}//main
