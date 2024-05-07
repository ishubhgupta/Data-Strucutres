#include <iostream>
#include <vector>
#include <unordered_set>
using namespace std;

void removeDuplicates(vector<int> &nums) {
    int duplicate = nums[0];

    for (int i = 1; i < nums.size();) {
        if (nums[i] == nums[i - 1] && nums[i] != duplicate) {
            duplicate = nums[i];
            nums.erase(nums.begin() + i);
        } else {
            ++i;
        }
    }
}

int main() {
    vector<int> nums = {1, 2, 2, 3, 3, 4, 5};
    removeDuplicates(nums);
    for (auto num : nums) {
        cout << num << " ";
    }
    cout << endl;
    cout<<nums.size();
    return 0;
}
