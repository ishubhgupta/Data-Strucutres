#include <bits/stdc++.h>
using namespace std;

void printName(string name, int n){
    if (n == 0) return;
    cout<<name<<endl;
    n--;
    printName(name, n);
}

void printLinear(int start, int n){
    if(start > n) return;
    cout<<start<<" ";
    return printLinear(start+1, n);
    
}

void printLinear(int n) {
    if (n == 0) {
        return;
    }
    printLinear(n - 1);
    cout << n << " ";
}

void printReverse(int n){
    if(n == 0){
        return;
    }
    cout<<n<<" ";
    printReverse(n-1);
}

int sumFirstN(int n){
    if(n<1){
        return 0;
    }
    return n + sumFirstN(n-1);
}


int main() {
    printName("Shubh Gupta", 5);
    printLinear(1, 10);
    cout<<endl;
    printLinear(10);
    cout<<endl;
    printReverse(5);
    cout<<endl;
    cout<<sumFirstN(5)<<endl;
    return 0;
}