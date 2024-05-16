#include <iostream>
#include <vector>
using namespace std;

int maximumWealth(vector<vector<int>>& accounts) {
    int wealth = 0;

    for(int i=0; i<accounts.size();i++){
        int balance =0;
        for(int j = 0;j<accounts[i].size();j++){
            balance += accounts[i][j];
        }
        wealth = max(wealth, balance);
    }
    return wealth;
}

int main(){
    vector<vector<int>> vec1 = {{1,2,3},{3,2,1}};
    cout<<maximumWealth(vec1);
    return 0;
}