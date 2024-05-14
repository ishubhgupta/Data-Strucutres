#include<iostream>
#include<vector>
#include<limits.h>
using namespace std;

int maxProfit(vector<int> prices){
    int maxProfit = 0;
    int minPrice = INT_MAX;

    for(auto price: prices){
        minPrice = min(minPrice, price);
        maxProfit = max(maxProfit, price - minPrice);
    }

    return maxProfit;
}

int main(){
    vector<int> vec1 = {7, 1, 5, 3, 6, 4, 10};
    cout<<maxProfit(vec1);
    return 0;
}