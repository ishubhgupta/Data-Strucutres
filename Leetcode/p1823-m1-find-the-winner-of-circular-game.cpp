#include<iostream>
#include<vector>

using namespace std;

int findTheWinner(int n, int k) {
    int result = 0;

    for (int i = 2; i <= n; i++) {
        result = (result + k) % i;
    }
    
    return result + 1;
}

int main(){
    cout<<findTheWinner(10,2);
    return 0;
}