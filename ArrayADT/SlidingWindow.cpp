#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

int maxSumM1(vector<int> nums, int k){
    int n = nums.size();
    int sum =0;
    
    int l = 0;
    int r = k-1;
    for(int i =0;i<k;i++){
        sum += nums[i];
    }
    int maxs = sum;
    while(r<n-1){
        sum -= nums[l];
        r++;
        l++;
        sum += nums[r];

        maxs = max(maxs, sum);
    }

    return maxs;
}

// maximum number of subarray with sum less than equal to k
int sumLessthankM1(vector<int> nums, int k){
    int n = nums.size();
    int sum =0;
    int count = 0;
    
    for(int i =0;i<n;i++){
        int tempSum = 0;
        for(int j=i;j<n;j++){
            tempSum+=nums[j];
            if(tempSum<k){
                count++;
            }
            else if (tempSum>k){
                break;
            }
        }
    }

    return count;

}


// longest subarray with sum less than k
int longestArrayWithSumLessThanKM1(vector<int> nums, int k ){
    int n = nums.size();
    int l = 0;
    int r = 0;
    int maxLen = 0;
    int sum = 0;

    while(r<n){
        sum += nums[r];
        while(sum>k){
            sum -= nums[l];
            l++;
        }

        if(sum<=k){
            maxLen = max(maxLen, r-l+1);
        }
        r++;

    }
    return maxLen;
}

int longestArrayWithSumLessThanKM2(vector<int> nums, int k ){
    int n = nums.size();
    int l = 0;
    int r = 0;
    int maxLen = 0;
    int sum = 0;

    while(r<n){
        sum += nums[r];
        if(sum>k){
            sum -= nums[l];
            l++;
        }

        if(sum<=k){
            maxLen = max(maxLen, r-l+1);
        }
        r++;

    }
    return maxLen;
}

int main(){
    // vector<int> vec1 = {-7, 3, 5, -2, 9, 4, -8, -1, 6, 2, 7};
    // cout<<maxSumM1(vec1, 4);

    vector<int> vec2 = {1, 2, 5};
    cout<<sumLessthankM1(vec2, 4)<<endl;

    vector<int> vec3 = {2, 5, 1, 10, 10};
    cout<<longestArrayWithSumLessThanKM1(vec3,10<<endl);

    cout<<longestArrayWithSumLessThanKM2(vec3,10);
    return 0;
}