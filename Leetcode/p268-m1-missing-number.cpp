#include <iostream>
#include <vector>

using namespace std;

int missingNumber(vector<int>& nums) {
    int n = nums.size();
    int Tsum= (n*(n+1))/2;
    int sum = 0;
    for(auto x:nums){
        sum += x;
    }
    return Tsum-sum;
}

int main(){
    vector<int> vec1 = {3, 2, 4, 5, 1};
    cout<<missingNumber(vec1);
    return 0;
}