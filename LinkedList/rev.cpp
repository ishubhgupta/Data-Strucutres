#include <iostream>
#include <vector>
#include <climits> // Include for INT_MIN
using namespace std;

// int maximumEnergy(vector<int>& energy, int k) {
//     int n = energy.size();
//     int maxEnergy = INT_MIN;

//     for (int i = 0; i < n; ++i) {
//         int currentEnergy = 0;
//         int j = i;
//         while (j < n) {
//             currentEnergy += energy[j];
//             j += k;
//         }
//         maxEnergy = max(maxEnergy, currentEnergy);
//     }

//     return maxEnergy;
    
// }

int maximumEnergy(vector<int>& energy, int k) {
    int n = energy.size();
    int maxEnergy = INT_MIN;
    vector<int> vec;

    for (int i = 0; i < n; ++i) {
        int currentEnergy = 0;
        int j = i;
        while (j < n) {
            currentEnergy += energy[j];
            j += k;
        }
        maxEnergy = max(maxEnergy, currentEnergy);
    }

    return maxEnergy;
    
}

int main() {
    vector<int> vec1 = {5, 2, -10, -5, 1};
    cout << "Example 1: " << maximumEnergy(vec1, 3) << endl;
    vector<int> vec2 = {-2, -3, -1};
    cout << "Example 2: " << maximumEnergy(vec2, 2) << endl;

    return 0;
}
