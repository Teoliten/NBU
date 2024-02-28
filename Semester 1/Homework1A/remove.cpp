#include <iostream>
#include <vector>

using namespace std;

typedef vector<vector<double>> Matrix;

// Function to print a matrix
void printMatrix(Matrix A) {
    for (int i = 0; i < A.size(); i++) {
        for (int j = 0; j < A[i].size(); j++) {
            cout << A[i][j] << "\t";
        }
        cout << endl;
    }
}

// Function to perform Gauss-Jordan elimination
Matrix gaussJordan(Matrix A) {
    int n = A.size();
    Matrix B(n, vector<double>(n * 2, 0));
    printMatrix(B);
    // Augment the matrix with the identity matrix
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            B[i][j] = A[i][j];
        }
        B[i][i + n] = 1;
    }
    printMatrix(B);

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

    return inverse;
}

int main() {
    // Read the matrix from the user
    Matrix A(5, vector<double>(5));
    cout << "Enter the matrix (5x5):" << endl;
    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 5; j++) {
            cin >> A[i][j];
        }
    }

    // Calculate the inverse using Gauss-Jordan elimination
    Matrix inverse = gaussJordan(A);

    // Print the inverse matrix
    cout << "Inverse matrix:" << endl;
    printMatrix(inverse);

    return 0;
}