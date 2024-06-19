#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

bool isPossible(vector<int>& bloomDay, int m, int k, int mid) {
    int bc = 0;
    int af = 0;
    for (int day : bloomDay) {
        if (day <= mid) {
            af++;
            if (af == k) {
                bc++;
                af = 0;
            }
        } else {
            af = 0;
        }
        
    }
    return bc >= m;
}

int minDays(vector<int>& bloomDay, int m, int k) {
    int n = bloomDay.size();
    long long totalFlowers = m * k;
    if (n < totalFlowers) {
        return -1;
    }
    
    int l = *min_element(bloomDay.begin(), bloomDay.end());
    int r = *max_element(bloomDay.begin(), bloomDay.end());
    
    while (l < r) {
        int mid = l + (r - l) / 2;
        if (isPossible(bloomDay, m, k, mid)) {
            r = mid;
        } else {
            l = mid + 1;
        }
    }
    
    return l;
}

int main() {
    vector<int> bloomDay = {1, 10, 3, 10, 2};
    int m = 3, k = 1;
    cout << minDays(bloomDay, m, k) << endl;  // Output: 3
    
    bloomDay = {1, 10, 3, 10, 2};
    m = 3, k = 2;
    cout << minDays(bloomDay, m, k) << endl;  // Output: -1
    
    bloomDay = {7, 7, 7, 7, 12, 7, 7};
    m = 2, k = 3;
    cout << minDays(bloomDay, m, k) << endl;  // Output: 12
    
    return 0;
}
