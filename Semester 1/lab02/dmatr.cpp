#include <iostream>
#include <cassert>

using namespace std;

int main()
{
	cout << "Rows: ";
	int rows;
	cin >> rows;
	assert(rows > 0);
	cout << "Cols: ";
	int cols;
	cin >> cols;
	assert(cols > 0);

	int** ptr_arr = new int*[rows];
	for (int i = 0; i < rows; i++)
	{
		ptr_arr[i] = new int[cols];
	}

	for (int i = 0; i < rows; i++)
	{
		if (ptr_arr[i])
		{
			delete[] ptr_arr[i];
			ptr_arr[i] = NULL;
		}
	}
	if (ptr_arr)
	{
		delete[] ptr_arr;
		ptr_arr = NULL;
	}

	return 0;
}//main
