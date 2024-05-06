#include <iostream>
#include <vector>
#include <unordered_set>
#include <algorithm>
using namespace std;

bool containsDuplicate(vector<int> nums) {
        unordered_set<int> seen; 
        for (int num : nums) {
            if (seen.count(num) > 0) {
                return true;
            }
            seen.insert(num);
        }
        return false;
}

int main() {
    vector<int> vec = {1, 2, 3, 4, 4};
    cout<<containsDuplicate(vec);
    return 0;
}


// this question is done by using concept of un-ordered set in which one can insert only unique element