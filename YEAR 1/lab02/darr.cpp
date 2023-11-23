#include <iostream>
#include <cassert>

using namespace std;

void readArr(int* ptr_arr, int size)
{
	for (int i = 0; i < size; i++)
	{
		cout << "[" << i << "] = ";
		cin >> ptr_arr[i];
	}
}//readArr

void printArr(const int* ptr_arr, int size)
{
	for (int i = 0; i < size; i++)
	{
		cout << ptr_arr[i] << " ";
	}
	cout << endl;
}//readArr

int main()
{
	cout << "How many elements: ";
	int numb;
	cin >> numb;
	assert(numb > 0);
	int* ptr_arr = NULL;
	ptr_arr = new int[numb];

	readArr(ptr_arr, numb);
	printArr(ptr_arr, numb);

	if (ptr_arr)
	{
		delete[] ptr_arr;
		ptr_arr = NULL;
	}

	return 0;
}//main
