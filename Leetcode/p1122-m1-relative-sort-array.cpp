#include <iostream>
#include<vector>
#include<algorithm>

using namespace std;

vector<int> relativeSortArray(vector<int>& arr1, vector<int>& arr2) {
    vector<int> result;
    int n = arr2.size();
    int m = arr1.size();
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            if (arr2[i] == arr1[j]) {
                result.push_back(arr1[j]);
                arr1.erase(arr1.begin() + j);
                --j; 
                --m; 
            }
        }
    }

    sort(arr1.begin(), arr1.end());
    result.insert(result.end(), arr1.begin(), arr1.end());
    return result;
}

int main() {
    vector<int> arr1 = {2, 3, 1, 3, 2, 4, 6, 7, 9, 2, 19};
    vector<int> arr2 = {2, 1, 4, 3, 9, 6};
    vector<int> result = relativeSortArray(arr1, arr2);
    
    for (int num : result) {
        cout << num << " ";
    }
    return 0;
}