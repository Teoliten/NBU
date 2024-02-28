#include <iostream>
#include <iomanip>
#include <cassert>

using namespace std;

const int ROW = 3;
const int COL = 5;
const int WIDTH = 4;

// read array from standard input
void readArr(int arr[][COL], int row, int col)
{
	assert(row <= ROW && col <= COL);
	for (int i = 0; i < row; i++)
	{
		for (int j = 0; j < col; j++)
		{
			cout << "[" << i << "][" << j << "] = ";
			cin >> arr[i][j];
		}
	}	
}//readArr

// print array to standard output
void printArr(const int arr[][COL], int row, int col)
{
	assert(row <= ROW && col <= COL);
	for (int i = 0; i < row; i++)
	{
		for (int j = 0; j < col; j++)
		{
			cout << setw(WIDTH) << arr[i][j] << " ";
		}
		cout << endl;
	}	
}//readArr

// generate multiplicatin table
void multtable(int arr[][COL], int row, int col)
{
	assert(row <= ROW && col <= COL);
	for (int i = 0; i < row; i++)
	{
		for (int j = 0; j < col; j++)
		{
			arr[i][j] = (i + 1) * (j + 1);
		}
	}	
}//multtable

int main()
{
	int arr[ROW][COL];
	//readArr(arr, ROW, COL);
	multtable(arr, ROW, COL);
	printArr(arr, ROW, COL);

	return 0;
}//main
