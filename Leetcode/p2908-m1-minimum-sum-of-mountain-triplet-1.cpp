#include <iostream>
#include <vector>
#include <climits>

using namespace std;

int minSumMountainTriplet(const vector<int>& nums) {
    int n = nums.size();
    
    if (n < 3) {
        return -1;
    }
    
    vector<int> left_min(n, INT_MAX);
    vector<int> right_min(n, INT_MAX);
    
    int min_left = INT_MAX;
    for (int j = 1; j < n; ++j) {
        min_left = min(min_left, nums[j-1]);
        left_min[j] = min_left;
    }
    
    int min_right = INT_MAX;
    for (int j = n-2; j >= 0; --j) {
        min_right = min(min_right, nums[j+1]);
        right_min[j] = min_right;
    }
    
    int min_sum = INT_MAX;
    for (int j = 1; j < n-1; ++j) {
        if (left_min[j] < nums[j] && right_min[j] < nums[j]) {
            int current_sum = left_min[j] + nums[j] + right_min[j];
            min_sum = min(min_sum, current_sum);
        }
    }
    
    return min_sum == INT_MAX ? -1 : min_sum;
}

int main() {
    vector<int> nums1 = {8, 6, 1, 5, 3};
    vector<int> nums2 = {5, 4, 8, 7, 10, 2};
    vector<int> nums3 = {6, 5, 4, 3, 4, 5};
    
    cout << minSumMountainTriplet(nums1) << endl; 
    cout << minSumMountainTriplet(nums2) << endl; 
    cout << minSumMountainTriplet(nums3) << endl; 
    
    return 0;
}
