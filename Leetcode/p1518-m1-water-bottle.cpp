#include<iostream>
#include<vector>

using namespace std;

class Solution {
public:
    int numWaterBottles(int numBottles, int numExchange) {
        int ans = 0;
        int rem = 0;

        while (numBottles > 0) {
            ans += numBottles;
            int totalBottles = numBottles + rem;
            numBottles = totalBottles / numExchange;
            rem = totalBottles % numExchange;
        }

        return ans;
    }
};

int main(){
    Solution s1;
    cout<<s1.numWaterBottles(15, 4);
}