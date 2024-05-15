#include <iostream>
#include <vector>

using namespace std;

int numIdenticalPairs(vector<int>& nums) {
    const int MAX_NUM = 101; 
    int count[MAX_NUM] = {0};
    int goodPairs = 0;
    
    // Count occurrences of each number
    for (int num : nums) {
        count[num]++;
    }
    
    // Calculate good pairs
    for (int i = 0; i < MAX_NUM; ++i) {
        if (count[i] > 1) {
            goodPairs += count[i] * (count[i] - 1) / 2;
        }
    }
    
    return goodPairs;
}

int main() {
    vector<int> nums1 = {1,2,3,1,1,3};
    cout << numIdenticalPairs(nums1) << endl;  
    
    return 0;
}
