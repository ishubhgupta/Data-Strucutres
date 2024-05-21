#include<iostream>
#include <vector>
using namespace std;

int countPairs(vector<int>& nums, int target) {
    int n = nums.size();
    int count=0;
    for(int i=0;i<n;i++){
        for(int j=i+1; j<n; j++){
            if(nums[i]+nums[j] < target){
                count++;
                
            }
        }
    }
    return count;
}
int main(){
    vector<int> vec1 = {3, 5, 6,7 ,3, 6, 3};
    cout<<countPairs(vec1, 8);
    return 0;
}