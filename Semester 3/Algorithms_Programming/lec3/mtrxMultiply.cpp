#include <iostream>
#include <vector>

using namespace std;

vector<vector<int>> mtrxMultiply(const vector<vector<int>>& a, const vector<vector<int>>& b) {
    int m = a.size();
    int n = a[0].size();
    int p = b[0].size();

    if (n != b.size()) {
        cerr << "Incompatible dimensions" << endl;
        return {};
    }

    vector<vector<int>> c(m, vector<int>(p, 0));

    for (int i = 0; i < m; ++i) {
        for (int j = 0; j < p; ++j) {
            for (int k = 0; k < n; ++k) {
                c[i][j] += a[i][k] * b[k][j];
            }
        }
    }

    return c;
}

void printMtrx(const vector<vector<int>>& a) {
    for (const auto& row : a) {
        for (int val : row) {
            cout << val << " ";
        }
        cout << endl;
    }
}

int main() {
    vector<vector<int>> a = {{6, 5, 2, 3}, {1, 9, 2, 8}, {5, 1, 2, 8}, {5, 1, 2, 1}};
    vector<vector<int>> b = {{1, 5, 2, 8}, {1, 1, 6, 6}, {3, 1, 3, 3}, {3, 2, 2, 8}};

    vector<vector<int>> res = mtrxMultiply(a, b);

    cout << "a:" << endl;
    printMtrx(a);

    cout << "b:" << endl;
    printMtrx(b);

    cout << "Result:" << endl;
    printMtrx(res);

    return 0;
}
