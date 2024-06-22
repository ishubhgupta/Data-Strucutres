#include<iostream>
#include<vector>

using namespace std;

int numberOfSubarrays(vector<int>& nums, int k) {
    int n = nums.size();
    int ans = 0;
    for (int i = 0; i < n; ++i) {
        int tempCount = 0;
        for (int j = i; j < n; ++j) {
            if (nums[j] % 2 == 1) {
                tempCount++;
            }
            if (tempCount == k) {
                ans++;
            }
        }
    }
    return ans;
}

int main() {
    vector<int> nums = {2, 2, 2, 1, 2, 2, 1, 2, 2, 2};
    int k = 2;
    int result = numberOfSubarrays(nums, k);
    cout << "Number of subarrays with " << k << " odd numbers: " << result << endl;
    return 0;
}