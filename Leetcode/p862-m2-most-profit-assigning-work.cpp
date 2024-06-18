#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

int maxProfitAssignment(vector<int>& difficulty, vector<int>& profit, vector<int>& worker) {
    vector<pair<int, int>> naukari;
    int n = difficulty.size();
    
    for (int i = 0; i < n; ++i) {
        naukari.push_back(make_pair(difficulty[i], profit[i]));
    }

    sort(naukari.begin(), naukari.end());

    int sum = 0;
    int maxp = 0;
    int j = 0;
    int m = worker.size();
    
    for (int i = 0; i < m; ++i) {
        while (j < n && naukari[j].first <= worker[i]) {
            maxp = max(maxp, naukari[j].second);
            ++j;
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