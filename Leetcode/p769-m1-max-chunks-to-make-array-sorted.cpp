#include <iostream>
#include <vector>
using namespace std;


class Solution {
public:
    int maxChunksToSorted(vector<int>& arr) {
        int maxSoFar = 0, chunks = 0;

        for (int i = 0; i < arr.size(); i++) {
            maxSoFar = max(maxSoFar, arr[i]);
            if (maxSoFar == i) {
                chunks++;
            }
        }
        
        return chunks;
    }
};

int main() {
    Solution solution;
    
    // Test case 1
    vector<int> arr1 = {4, 3, 2, 1, 0};
    cout << "Test 1 Output: " << solution.maxChunksToSorted(arr1) << endl;
    
    // Test case 2
    vector<int> arr2 = {1, 0, 2, 3, 4};
    cout << "Test 2 Output: " << solution.maxChunksToSorted(arr2) << endl;
    
    // Test case 3
    vector<int> arr3 = {0, 1, 2, 3, 4};
    cout << "Test 3 Output: " << solution.maxChunksToSorted(arr3) << endl;
    
    return 0;
}