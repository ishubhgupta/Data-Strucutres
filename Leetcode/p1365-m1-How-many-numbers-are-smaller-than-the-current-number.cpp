#include<iostream>
#include<vector>

using namespace std;

vector<int> smallerNumbersThanCurrent(vector<int>& nums) {
    int n = nums.size();
    vector<int> result;
    for(int i =0;i<n;i++){
        int count=0;
        for(int j = 0;j<n;j++){
            if(nums[i]>nums[j] && j!=i){
                count++;
            }
        }
        result.push_back(count);
    }
    return result;
}


int main(){
    vector<int> vec1 = {8, 1, 2, 2, 3};
    for(auto x:vec1){
        cout<<x<<" ";
    }
}