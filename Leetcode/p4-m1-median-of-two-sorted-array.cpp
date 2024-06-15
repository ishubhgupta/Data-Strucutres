#include <iostream>
#include <vector>
#include <algorithm>
#include <math.h>

using namespace std;


double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
    vector<int> nums(nums1.begin(), nums1.end());
    nums.insert(nums.end(), nums2.begin(), nums2.end());
    sort(nums.begin(), nums.end());
    int n = nums.size();
    int mid = nums.size()/2;
    if(n%2 == 1){
        return nums[mid];
    }
    else{
        return (nums[mid-1]+nums[mid])/2.0;
    }
}

int main(){
    vector<int> vec1 = {1,3};
    vector<int> vec2 = {2};
    cout<<findMedianSortedArrays(vec1, vec2);
    return 0;
}