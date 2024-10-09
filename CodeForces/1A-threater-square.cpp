#include <iostream>
using namespace std;

int main() {
    long long n, m, a;
    cin >> n >> m >> a;

    long long vtile = (n + a - 1) / a; 
    long long htile = (m + a - 1) / a;

    cout << vtile * htile << endl;

    return 0;
}
