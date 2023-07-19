#include <iostream>
#include <iomanip>
#include <vector>

using namespace std;

const int SIZE = 5;

void readMtrx(vector< vector<double> > &mtrx)
{
	for(int i = 0; i < SIZE; i++)
    {
        for(int j = 0; j < SIZE; j++)
        {
            cout << "Enter INTEGER for position: [" << i
            << "][" << j << "]" << endl << "> ";
            cin >> mtrx[i][j];
        }
    }
}//readMtrx

void printMtrx(const vector< vector<double> > &mtrx)
{
	for (int i = 0; i < SIZE; i++)
	{
		for (int j = 0; j < SIZE; j++)
		{
			cout << setw(5) << mtrx[i][j] << " ";
		}
		cout << endl;
	}
}//printMtrx

void inverseMtrx(vector< vector<double> > &mtrx)
{
    vector< vector<double> > calcMtrx(SIZE, vector<double>(SIZE * 2));

    for (int i = 0; i < SIZE; i++)//adding the identity matrix to the matrix
    {
        for (int j = 0; j < SIZE; j++) 
        {
            calcMtrx[i][j] = mtrx[i][j];
        }
        calcMtrx[i][i + SIZE] = 1;
    }

    for (int i = 0; i < SIZE; i++)//doing row opperations with gaussian elimination
    {
        
        double leadingNumb = calcMtrx[i][i];
        for (int j = i; j < SIZE * 2; j++)//divide the current row by the leading element 
        {
            calcMtrx[i][j] = calcMtrx[i][j] / leadingNumb;
        }

        
        for (int j = 0; j < SIZE; j++) //subtract the leading row from all other rows
        {
            if (i != j) 
            {
                double factor = calcMtrx[j][i];
                for (int k = i; k < SIZE * 2; k++) 
                {
                    calcMtrx[j][k] = calcMtrx[j][k] - (factor * calcMtrx[i][k]);
                }
            }
        }
    }

    vector< vector<double> > invMtrx(SIZE, vector<double>(SIZE));
    for (int i = 0; i < SIZE; i++)//putting the identity matrix part of our "calcMtrx", which is the inverse of our matrix in a new final inverted matrix
    {
        for (int j = SIZE; j < SIZE * 2; j++) 
        {
            invMtrx[i][j - SIZE] = calcMtrx[i][j];
        }
    }
    cout << endl << "Inverted matrix: " << endl;
    printMtrx(invMtrx);
}//inverseMtrx

int main()
{
	vector< vector<double> > mtrx(SIZE, vector<double>(SIZE));

	readMtrx(mtrx); 
    cout << endl << "Entered matrix: " << endl;
	printMtrx(mtrx);

    inverseMtrx(mtrx);

	return 0;
}//main
