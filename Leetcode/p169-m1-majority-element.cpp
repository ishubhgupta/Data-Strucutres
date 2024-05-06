#include<iostream>
#include <vector>
using namespace std;

int majorityElement(vector<int> nums){
    int candidate;
    int count=0;

    for(auto num:nums){
        if(count == 0){
            candidate = num;
        }

        count += (num == candidate)? 1:-1;
    }
    count = 0;
    
    for(auto x: nums){
        if(x == candidate){
            count += 1;
        }
    }

    if(count > nums.size() / 2){
        return candidate;
    } else {
        return -1;
    }
}

int main(){
    vector<int> vec = {2, 2, 3, 3, 2, 3, 4, 3};
    cout << majorityElement(vec);
}

// used moore's algorithm to solve this problem, description of this algorithm is on last page of dsa notebook