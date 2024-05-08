#include <iostream>
#include<vector>
using namespace std;

int removeDuplicate(vector<int> &nums, int val){
    int k=0;
    for(int i=0;i<nums.size(); i++){
        if(nums[i]!= val){
            nums[k] = nums[i];
            k++;
        }
    }
    return k;
}
int main(){
    vector<int> vec = {1, 2, 3, 3, 4, 5};
    removeDuplicate(vec, 3);
    for(auto x:vec){
        cout<<x<<" ";
    }
}