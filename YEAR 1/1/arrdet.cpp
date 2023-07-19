#include <iostream>
#include <iomanip>
#include <cassert>

using namespace std;

const int ROW = 3;
const int COL = 5;
const int WIDTH = 4;

// read array from standard input
void readArr(double arr[][COL], int row, int col)
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
void printArr(const double arr[][COL], int row, int col)
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

inline double det2(const double arr[][COL])
{
	return arr[0][0] * arr[1][1] - arr[0][1] * arr[1][0];
}//det2

inline double det31(const double arr[][COL])
{
	return arr[0][0] * arr[1][1] * arr[2][2]
			+ arr[1][0] * arr[2][1] * arr[0][2]
			+ arr[0][1] * arr[1][2] * arr[2][0]
			- arr[0][2] * arr[1][1] * arr[2][0]
			- arr[2][1] * arr[1][2] * arr[0][0]
			- arr[1][0] * arr[0][1] * arr[2][2];
}//det3

inline double det32(const double arr[][COL])
{
	double tmp[ROW][COL];
	double result = 0;
	tmp[0][0] = arr[1][1];
	tmp[0][1] = arr[1][2];
	tmp[1][0] = arr[2][1];
	tmp[1][1] = arr[2][2];
	result += arr[0][0] * det2(tmp);
	tmp[0][0] = arr[1][0];
	tmp[0][1] = arr[1][2];
	tmp[1][0] = arr[2][0];
	tmp[1][1] = arr[2][2];
	result -= arr[0][1] * det2(tmp);
	tmp[0][0] = arr[1][0];
	tmp[0][1] = arr[1][1];
	tmp[1][0] = arr[2][0];
	tmp[1][1] = arr[2][1];
	result += arr[0][2] * det2(tmp);

	return result;
}//det32

int main()
{
	double arr[ROW][COL];
	readArr(arr, 3, 3);
	printArr(arr, 3, 3);

	cout << det32(arr) << endl;

	return 0;
}//main