#include <iostream>
#include <vector>
using namespace std;

int differenceOfSums(int n, int m) {
    int sum1 = 0;
    int sum2 = 0;
    
    for(int i = 1; i <= n; i++) {
        if(i % m == 0) {
            sum2 += i;
        } else {
            sum1 += i;
        }
    }
    
    return sum1 - sum2;
}


int main(){

    cout<<differenceOfSums(18, 56);
    return 0;
}