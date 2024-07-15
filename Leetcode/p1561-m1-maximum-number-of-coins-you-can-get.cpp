#include<iostream>
#include <vector>
#include <algorithm>
using namespace std;

int maxCoins(vector<int>& piles) {
    sort(piles.begin(), piles.end());
    int n = piles.size();
    int coins = 0;
    for(int i = n / 3; i < n; i += 2) {
        coins += piles[i];
    }
    return coins;
}

int main(){
    vector<int> vec1 ={5, 3, 2, 6,7 ,3};
    int r1 = maxCoins(vec1);
    cout<<r1;
    return 0;
}