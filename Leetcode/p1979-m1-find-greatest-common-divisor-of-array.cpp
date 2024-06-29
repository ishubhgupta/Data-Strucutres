#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int findGCD(vector<int>& nums) {
    sort(nums.begin(), nums.end());
    int s = nums[0];
    int l = nums[nums.size() - 1];
    int i = 1; 
    int j = 1;
    vector<int> sfac;
    vector<int> lfac;

    while (i <= s) {
        if (s % i == 0) {
            sfac.push_back(i);
        }
        i++;
    }

    while (j <= l) {
        if (l % j == 0) {
            lfac.push_back(j);
        }
        j++;
    }

    vector<int> res;
    for (int factor : sfac) {
        if (find(lfac.begin(), lfac.end(), factor) != lfac.end()) {
            res.push_back(factor);
        }
    }

    return res.back();
}

int main() {
    vector<int> nums = {12, 18, 24};
    int result = findGCD(nums);
    cout << "GCD of the given numbers: " << result << endl;
    return 0;
}
