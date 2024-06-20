#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;


vector<int> targetIndices(vector<int>& nums, int target) {
    sort(nums.begin(), nums.end());
    vector<int> result;
    int n = nums.size();
    int l = 0;
    int r = n - 1;
    
    while (l <= r) {
        int mid = l + (r - l) / 2;
        if (nums[mid] == target) {
            int left = mid;
            while (left >= 0 && nums[left] == target) {
                left--;
            }
            
            int right = mid;
            while (right < n && nums[right] == target) {
                right++;
            }
            
            for (int i = left + 1; i < right; i++) {
                result.push_back(i);
            }
            
            break;
        }
        else if (nums[mid] < target) {
            l = mid + 1;
        } else {
            r = mid - 1;
        }
    }
    
    return result;
}


int main() {
    vector<int> nums = {1, 2, 5, 2, 3};
    int target = 2;
    vector<int> result = targetIndices(nums, target);
    
    for (int i : result) {
        cout<<i<< " ";
    }
    cout << endl;
    
    return 0;
}
