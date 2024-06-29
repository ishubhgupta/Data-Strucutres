#include<iostream>
#include<vector>
using namespace std;

int oddCells(int m, int n, vector<vector<int>>& indices) {
    vector<vector<int>> zeroMat(n, vector<int>(m, 0));

    for (auto index : indices) {
        int r = index[0];
        int c = index[1];

        for (int i = 0; i < n; ++i) {
            zeroMat[i][r]++; 
        }

        for (int i = 0; i < m; ++i) {
            zeroMat[c][i]++;
        }
    }

    int count = 0;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            if (zeroMat[i][j] % 2 == 1) {
                count++;
            }
        }
    }
    return count;
}

int main() {
    int m = 3;
    int n = 4;
    vector<vector<int>> indices = {{0, 1}, {1, 2}, {2, 3}};

    int result = oddCells(m, n, indices);
    cout << "Number of odd-valued cells: " << result << endl;

    return 0;
}