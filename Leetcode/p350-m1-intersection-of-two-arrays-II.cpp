#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
    int n = nums1.size();
    int m = nums2.size();
    sort(nums1.begin(), nums1.end());
    sort(nums2.begin(), nums2.end());
    vector<int> res;
    int i=0, j=0;
    while(i<n && j<m){
        if(nums1[i] == nums2[j]){
            res.push_back(nums1[i]);
            i++;
            j++;
        }
        else if(nums1[i]<nums2[j]){
            i++;
        }
        else{
            j++;
        }
    }


    return res;
}

int main(){
    vector<int> vec1 = {5, 6, 7, 9, 2, 3};
    vector<int> vec2 = {8, 1, 3, 20, 7, 3};
    vector<int> res = intersect(vec1, vec2);

    for(auto x: res){
        cout<<x<<" ";
    }

    return 0;
}