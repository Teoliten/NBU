#include <iostream>
#include <iomanip>
#include <vector>
#include <cassert>

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

inline double det2(const vector< vector<double> > &matr)
{
	assert(matr.size() == 2 && matr[0].size() == 2);
	return matr[0][0] * matr[1][1] - matr[0][1] * matr[1][0];
}//det2

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

	cout << det2(matr) << endl;

	return 0;
}//main
