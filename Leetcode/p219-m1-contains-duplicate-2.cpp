#include <iostream>
#include <vector>
using namespace std;

bool containsNearbyDuplicate(vector<int>& nums, int k) {
    for(int i = 0; i < nums.size(); i++) {
        for(int j = i + 1; j < nums.size(); j++) { 
            if(nums[i] == nums[j] && j - i <= k && j > i) { // here i have added j>i to consider the case where t checks whether the absolute difference between indices i and j is less than or equal to k, it doesn't consider that j should be greater than i to ensure that the elements are distinct.
                return true;
            }
        }
    }
    return false;
}

int main() {
    vector<int> nums = {1, 2, 3, 1};
    int k = 3;

    cout<<containsNearbyDuplicate(nums, k);

    return 0;
}


// this code have more time complexity about n^2 due to for loop inside for loop, so we will avoid doing this