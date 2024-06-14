#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int minIncrementForUnique(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int count = 0;
        int cmax = 0;
        for(auto x:nums){
            cmax = max(cmax, x);
            count += cmax-x;
            cmax+=1;
        }
        return count;
}


int main(){
    vector<int> vec1 = {3,2,1,2,1,7};

    cout<<minIncrementForUnique(vec1);
    return 0;
}

