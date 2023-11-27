#include <iostream>
using namespace std;

int fact(int n){
    if (n == 0) return 1;
    return fact(n-1)*n;
}

// using function
int nCr(int n, int r){
    int t1 = fact(n);
    int t2 = fact(r);
    int t3 = fact(n-r);
    return t1/(t2*t3);
}

// using recursion
int nCr_r(int n,int r){
    if(r==0 || r==n) return 1;
    return nCr_r(n-1, r-1) + nCr_r(n-1, r);
}


int main(){
    // cout<<fact(6);
    cout<<nCr_r(5,2);
}