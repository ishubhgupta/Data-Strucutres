#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

int maxProfitAssignment(vector<int>& difficulty, vector<int>& profit, vector<int>& worker) {
    sort(worker.begin(), worker.end());
    int n = worker.size();
    int m = profit.size();
    int sum = 0;

    for (int i = 0; i < n; ++i) {
        int maxp = 0;
        for (int j = 0; j < m; ++j) {
            if (worker[i] >= difficulty[j]) {
                maxp = max(maxp, profit[j]);
            }
        }
        sum += maxp;
    }

    return sum;
}

int main(){
    vector<int> difficulty = {2, 4, 6, 8};
    vector<int> profit = {10, 20, 30, 40};
    vector<int> worker = {4, 5, 6, 7};
    cout<<maxProfitAssignment(difficulty, profit, worker);
    return 0;
}