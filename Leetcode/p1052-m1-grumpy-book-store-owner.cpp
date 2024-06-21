#include<iostream>
#include<vector>
using namespace std;

int maxSatisfied(vector<int>& customers, vector<int>& grumpy, int minutes) {
    int n = customers.size();
    int maxc = 0;

    int totalSatisfied = 0;
    for(int i = 0; i < n; i++) {
        if(grumpy[i] == 0) {
            totalSatisfied += customers[i];
        }
    }

    for(int i = 0; i < n; i++) {
        int sum = 0;
        for(int j = 0; j < minutes && i + j < n; j++) {
            if(grumpy[i + j] == 1) {
                sum += customers[i + j];
            }
        }
        if(sum > maxc) {
            maxc = sum;
        }
    }

    return totalSatisfied + maxc;
}

int main() {
    vector<int> customers = {1, 0, 1, 2, 1, 1, 7, 5};
    vector<int> grumpy = {0, 1, 0, 1, 0, 1, 0, 1};
    cout << maxSatisfied(customers, grumpy, 3);
    return 0;
}
