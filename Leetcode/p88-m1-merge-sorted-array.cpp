#include <iostream>
#include <vector>
using namespace std;

void merge(vector<int>& nums1, int m, vector<int>& nums2, int n){
    vector<int> vec3;
    int i =0;
    int j=0;
    while(i<m && j<n){
        if(nums1[i]<nums2[j]){
            vec3.push_back(nums1[i]);
            i++;
        }
        else{
            vec3.push_back(nums2[j]);
            j++;
        }
    }

    while(i<m){
        vec3.push_back(nums1[i]);
        i++;
    }
    while(j<n){
        vec3.push_back(nums2[j]);
        j++;
    }

    nums1 = vec3;
    for(auto x: nums1){
        cout<<x<<" ";
    }
}
int main(){
    vector<int> vec1 = {1, 2, 3};
    vector<int> vec2 = {2, 2, 5};

    int m = vec1.size();
    int n = vec2.size();
    merge(vec1, m, vec2, n);
}