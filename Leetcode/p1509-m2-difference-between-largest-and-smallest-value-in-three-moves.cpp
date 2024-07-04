// this is not correct solution for all test cases
#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;

int minDifference(vector<int>& nums) {
    if (nums.size() <= 4) return 0;

    sort(nums.begin(), nums.end());
    int n = nums.size();


    nums[n-1] = nums[n-2] = nums[n-3] = nums[0];

    return max_element(nums.begin(), nums.end()) - min_element(nums.begin(), nums.end());
}


int main() {
    vector<int> nums = {1, 5, 0, 10, 14};
    cout<<minDifference(nums)<<endl;

    vector<int> nums = {1, 6, 0, 10, 14};
    cout<<minDifference(nums)<<endl;
    return 0;
}
