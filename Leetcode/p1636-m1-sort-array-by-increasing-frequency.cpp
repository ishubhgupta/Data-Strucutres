#include <iostream>
#include <vector>
#include <algorithm>
#include<unordered_map>

using namespace std;

vector<int> frequencySort(vector<int>& nums){
    unordered_map<int, int> freq_map;

    for(auto num : nums){
        freq_map[num]++;
    }

    sort(nums.begin(), nums.end(), [&](int a, int b){
        if(freq_map[a]!=freq_map[b]){
            return freq_map[a]>freq_map[b];
        }
        return a<b;
    });

    return nums;
}
int main(){
    vector<int> vec1 = {1,1,2,2,2,3};
    frequencySort(vec1);
    for(auto a: vec1){
        cout<<a<< " ";
    }
    return 0;
}