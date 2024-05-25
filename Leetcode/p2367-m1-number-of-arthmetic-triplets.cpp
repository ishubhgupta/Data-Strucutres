#include<iostream>
#include<vector>
using namespace std;

int arithmeticTriplets(vector<int>& nums, int diff) {
    int n = nums.size();
    int count=0;
    for(int i=0;i<n;i++){
        for(int j = i+1;j<n;j++){
            for(int k=j+1;k<n;k++){
                if(nums[j]-nums[i] == diff && nums[k] - nums[j] == diff){
                    count++;
                }
            }
        }
    }
    return count;
}

int main(){
    vector<int> vec1 = {1, 2,3 , 4, 5, 6};
    cout<<arithmeticTriplets(vec1, 3);
    cout<<arithmeticTriplets(vec1, 8);
    cout<<arithmeticTriplets(vec1, 5);

    return 0;
}