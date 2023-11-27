#include <iostream>
using namespace std;

int main() {
    int *a[3];

    a[0] = new int[9];
    a[1] = new int[9];
    a[2] = new int[9];

    a[2][7] = 8;
    a[0][8] = 6;
    a[1][5] = 1;

    for (int i = 0; i < 3; i++) {
        for (int j = 0; j <= 8; j++) {
            cout << a[i][j] << " ";
        }
        cout << endl;
    }

    // Don't forget to free the allocated memory
    for (int i = 0; i < 3; i++) {
        delete[] a[i];
    }

    return 0;
}
