#include <iostream>
#include <iomanip>

using namespace std;

const int SIZE = 5;

void readMtrx(double mtrx[][SIZE])
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

void printMtrx(double mtrx[][SIZE])
{
    cout << setw(5);
    for(int i = 0; i < SIZE; i++)
    {
        for(int j = 0; j < SIZE; j++)
        {
            cout << mtrx[i][j] << setw(5);
        }
        cout << endl;
    }
}//printMtrx

void printMtrxL(double mtrx[][SIZE * 2])
{
    cout << setw(5);
    for(int i = 0; i < SIZE; i++)
    {
        for(int j = 0; j < SIZE * 2; j++)
        {
            cout << mtrx[i][j] << setw(5);
        }
        cout << endl;
    }
}//printMtrx

void inverseMtrx(double mtrx[][SIZE])
{
    int n = SIZE;
    double B[n, n * 2];
    //Matrix B(n, vector<double>(n * 2, 0));
    printMtrxL(B);
    // Augment the matrix with the identity matrix
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            B[i][j] = A[i][j];
        }
        B[i][i + n] = 1;
    }
    printMtrxL(B);

    // Perform row operations
    for (int i = 0; i < n; i++) {
        // Divide the current row by the pivot element
        double pivot = B[i][i];
        for (int j = i; j < n * 2; j++) {
            B[i][j] /= pivot;
        }

        // Subtract the pivot row from all other rows
        for (int j = 0; j < n; j++) {
            if (i != j) {
                double factor = B[j][i];
                for (int k = i; k < n * 2; k++) {
                    B[j][k] -= factor * B[i][k];
                }
            }
        }
    }

    // Extract the inverse matrix from the augmented matrix
    Matrix inverse(n, vector<double>(n, 0));
    for (int i = 0; i < n; i++) {
        for (int j = n; j < n * 2; j++) {
            inverse[i][j - n] = B[i][j];
        }
    }
}

int main()
{
    cout << "Enter INTEGERS for a 5x5 matrix." << endl << endl;
    double mtrx[SIZE][SIZE];

    readMtrx(mtrx);
    cout << "Matrix: " << endl;
    printMtrx(mtrx);

    inverseMtrx(mtrx);


    return 0;
}//main