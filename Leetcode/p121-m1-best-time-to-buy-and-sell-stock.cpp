#include <iostream>
#include<vector>
using namespace std;

int maxProfit(vector<int> prices){
    int max = 0;
    int n = prices.size()-1;

    for(int i = 0;i<n;i++){
        for(int j = i+1; j<n;j++){
            int diff = prices[j] - prices[i];
            if(diff>=max){
                max = diff;
            }
            
        }
    }
    return max;
}

int main(){
    vector<int> vec1 = {7, 1, 5, 3, 6, 4};
    cout<<maxProfit(vec1);
    return 0;
}

// this is one of method to solve this problem but have higher time complexity order of n^2