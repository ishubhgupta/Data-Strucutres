// recursion 

// #include <iostream>
// using namespace std;
// int fab(int n){
//     if(n <=1)
//         return n;
//     return fab(n-1)+fab(n-2);
// }


// loop
#include <iostream>
using namespace std;

// int fabloop(int n){
//     int t0 =0;
//     int t1 =1;
//     int s;
//     if (n<=1) return n;
//     for (int i =2; i<=n;i++){
//         s = t0+t1;
//         t0 = t1;
//         t1 = s;
//     }
//     return s;
// }

// recursion method 2 - memorization
#include <iostream>
using namespace std;
int f[10];
int fibo(int n) {
    if (n <= 1) {
        f[n] = n;
        return n; 
    }
    else {
        if (f[n - 2] == -1) {
            f[n - 2] = fibo(n - 2);
        }
        if (f[n - 1] == -1) {
            f[n - 1] = fibo(n - 1);
        }
        return f[n - 2] + f[n - 1]; // Return the sum of the two previous values
    }
}

int main() {
    for (int i = 0; i < 10; i++) {
        f[i] = -1; // Initialize the memoization array to -1
    }
    cout << fibo(8) << endl;
    return 0;
}
