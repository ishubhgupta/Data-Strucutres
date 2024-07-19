#include<iostream>
#include<vector>

using namespace std;

class Solution {
public:
    vector<int> luckyNumbers (vector<vector<int>>& matrix) {
        vector<int> result;
        int m = matrix.size();
        int n = matrix[0].size();
        
        for (int i = 0; i < m; ++i) {
            int minRowValue = matrix[i][0];
            int minRowIndex = 0;
            
            for (int j = 1; j < n; ++j) {
                if (matrix[i][j] < minRowValue) {
                    minRowValue = matrix[i][j];
                    minRowIndex = j;
                }
            }
            
            bool isLucky = true;
            for (int k = 0; k < m; ++k) {
                if (matrix[k][minRowIndex] > minRowValue) {
                    isLucky = false;
                    break;
                }
            }
            
            if (isLucky) {
                result.push_back(minRowValue);
            }
        }
        
        return result;
    }
};

int main() {
    Solution s1;
    vector<vector<int>> vec1 = {{3,7,8},{9,11,13},{15,16,17}};
    vector<int> luckyNumbers = s1.luckyNumbers(vec1);
    
    cout << "Lucky numbers are: ";
    for (int num : luckyNumbers) {
        cout << num << " ";
    }
    cout << endl;

    return 0;
}