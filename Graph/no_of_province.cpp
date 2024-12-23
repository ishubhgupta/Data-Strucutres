#include <bits/stdc++.h>
using namespace std;

void bfs(vector<int> adj[], int start, vector<int> &visited) {
    visited[start] = 1;
    queue<int> q;
    q.push(start);
    
    while(!q.empty()) {
        int node = q.front();
        q.pop();
        for(auto x: adj[node]) {
            if(!visited[x]) {
                visited[x] = 1;
                q.push(x);
            }
        }
    }
}

int main() {
    int n = 9;
    vector<int> adj[n+1];

    adj[1] = {2};
    adj[2] = {1, 3};
    adj[3] = {2};
    adj[4] = {5};
    adj[5] = {4, 6};
    adj[6] = {5};
    adj[7] = {8};
    adj[8] = {7, 9};
    adj[9] = {8};

    vector<int> visited(n+1, 0);
    int count = 0;
    for(int i = 1; i <= n; i++) {
        if(!visited[i]) {
            bfs(adj, i, visited);
            count++;
        }
    }
    cout << count;
    return 0;
}