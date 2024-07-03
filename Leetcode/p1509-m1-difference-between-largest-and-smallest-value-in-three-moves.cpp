#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;

int minDifference(vector<int>& nums) {
    int n = nums.size();
    if (n <= 4) return 0;

    sort(nums.begin(), nums.end());

    int min_diff = min({ 
        nums[n-1] - nums[3],   
        nums[n-2] - nums[2],   
        nums[n-3] - nums[1],   
        nums[n-4] - nums[0]    
    });

    return min_diff;
}

int main() {
    vector<int> nums = {1, 5, 0, 10, 14};
    cout<<minDifference(nums)<<endl;
    return 0;
}
// this is correct solution for all test cases