#include <iostream>
#include <bits/stdc++.h>
#include <vector>

using namespace std;

vector<bool> kidsWithCandies(vector<int>& candies, int extraCandies) {
    vector<bool> result;
    int n = candies.size();
    int max = *max_element(candies.begin(), candies.end());
    for(int i = 0; i<n;i++){
        int tc = candies[i] + extraCandies;
        if(tc >= max) result.push_back(true);
            else{
                result.push_back(false);
            }
    }
    return result;
}

int main(){
    vector<int> vec1={2, 3, 5, 1, 3};
    vector<bool> res;
    res = kidsWithCandies(vec1, 4);
    for(auto x: res){
        cout<<x<<" ";
    }
}

// candies with count 