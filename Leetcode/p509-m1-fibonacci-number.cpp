#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
    int fun(int n,vector<int> &dp){
        if(n<=1) return n;
        if(dp[n] != -1) return dp[n];
        return dp[n] = fun(n-1, dp)+fun(n-2, dp);
    }
    int fib(int n) {
        vector<int> dp(n+1, -1);
        return fun(n, dp);
    }
};

int main(){
    Solution s1;
    cout<<s1.fib(6);
    return 0;
}