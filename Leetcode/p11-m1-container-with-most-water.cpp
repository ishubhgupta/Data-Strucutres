#include <iostream>
#include <vector>
#include <algorithm> 

using namespace std;

class Solution {
public:
    int maxArea(vector<int>& height) {
        int left = 0;
        int right = height.size() - 1;
        int maxVolume = 0;

        while (left < right) {
            int width = right - left;
            int h = min(height[left], height[right]);
            int volume = h * width;
            maxVolume = max(maxVolume, volume);
            
            if (height[left] < height[right]) {
                ++left;
            } else {
                --right;
            }
        }
        
        return maxVolume;
    }
};

int main() {
    Solution sol;
    vector<int> height = {1, 8, 6, 2, 5, 4, 8, 3, 7};

    int result = sol.maxArea(height);
    cout << "The maximum area is: " << result << endl;

    return 0;
}
