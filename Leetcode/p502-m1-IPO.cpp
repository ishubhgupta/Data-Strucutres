#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

int findMaximizedCapital(int k, int w, vector<int>& profits, vector<int>& capital) {
    int n = profits.size();
    vector<pair<int, int>> prj(n);
    
    for (int i = 0; i < n; ++i) {
        prj[i] = {capital[i], profits[i]};
    }
    
    sort(prj.begin(), prj.end());

    priority_queue<int> pq;
    int i = 0;
    
    for (int j = 0; j < k; ++j) {
        while (i < n && prj[i].first <= w) {
            pq.push(prj[i].second);
            ++i;
        }
        
        if (pq.empty()) {
            break;
        }
        
        w += pq.top();
        pq.pop();
    }
    
    return w;
}

int main(){
    vector<int> profits= {1, 2, 3};
    vector<int> cap ={0, 1, 1};
    cout<<findMaximizedCapital(2, 0, profits, cap);
    return 0;
}