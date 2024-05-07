#include <iostream>
#include<vector>
using namespace std;

int removeDuplicates(vector<int> nums){
    int i =0; // total number of unique value
    for(int j = 1; j<nums.size();j++){
        if(nums[j] != nums [i]){
            i++;
            nums[i] = nums[j];
        }
    }

    return i+1;
}

int main(){
    vector<int> vec = {2, 3, 4, 5, 6, 6, 7, 8};
    cout<<removeDuplicates(vec);


}


// this is the most optimized and prefered solution for this problem which have time complexity of 1