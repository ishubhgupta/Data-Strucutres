#include <iostream>
#include <vector>

using namespace std;

int numIdenticalPairs(vector<int>& nums) {
    int count =0;
    int n = nums.size();
    for(int i =0;i<n;i++){
        for(int j=i+1;j<n;j++){
            if(nums[i] == nums[j]){
                count++;
            }
        }
    }

    return count;
}

int main() {
    vector<int> nums1 = {1,2,3,1,1, 3};
    cout << numIdenticalPairs(nums1) << endl;  
    
    return 0;
}

// this method have higher time complexity so we will use method 2 for this problem