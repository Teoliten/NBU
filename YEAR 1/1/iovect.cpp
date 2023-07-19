#include <iostream>
#include <iomanip>
#include <vector>

using namespace std;

const int WIDTH = 4;

// read vector from standard input
void readVect(vector< vector<double> > &matr)
{
	for (int i = 0; i < matr.size(); i++)
	{
		for (int j = 0; j < matr[i].size(); j++)
		{
			cout << "[" << i << "][" << j << "] = ";
			cin >> matr[i][j];
		}
	}
}//readVect

// print vector to the standard output
void printVect(const vector< vector<double> > &matr)
{
	for (int i = 0; i < matr.size(); i++)
	{
		for (int j = 0; j < matr[i].size(); j++)
		{
			cout << setw(WIDTH) << matr[i][j] << " ";
		}
		cout << endl;
	}
}//printVect

int main()
{
	cout << "Rows: ";
	int row;
	cin >> row;
	cout << "Cols: ";
	int cols;
	cin >> cols;

	vector< vector<double> > matr(row, vector<double>(cols));

	readVect(matr); 
	printVect(matr);

	return 0;
}//main
