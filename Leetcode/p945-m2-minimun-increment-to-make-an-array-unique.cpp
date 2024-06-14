#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int minIncrementForUnique(vector<int>& nums) {
    sort(nums.begin(),nums.end());
    int m = nums.size();
    int count = 0;
    for(int i = 1; i < m; i++){
        if(nums[i] <= nums[i-1]){
            int a = nums[i-1] - nums[i] + 1;
            nums[i] = nums[i] + a;
            count = count + a;
        }
    }
    return count;
}


int main(){
    vector<int> vec1 = {3,2,1,2,1,7};

    cout<<minIncrementForUnique(vec1);
    return 0;
}

