#include <bits/stdc++.h>
using namespace std;

// Function to perform BFS traversal
vector<int> bfsTraversal(vector<int> adj[], int start) {
    vector<int> bfs;
    vector<bool> visited(adj->size(), false);
    queue<int> q;
    q.push(start);
    visited[start] = true;
    while (!q.empty()) {
        int frnt = q.front();
        q.pop();
        bfs.push_back(frnt);
        for (auto x : adj[frnt]) {
            if (!visited[x]) {
                q.push(x);
                visited[x] = true;
            }
        }
    }
    return bfs;
}

void dfs(int node, vector<int> adj[], vector<int> &ls, vector<bool> visited){
    ls.push_back(node);
    visited[node] = true;
    for(auto x: adj[node]){
        if(!visited[x]){
            dfs(x, adj, ls, visited);
        }
    }
}
vector<int> dfsTraversal(vector<int> adj[], int start){
    vector<int> ls;
    vector<bool> visited(adj->size(), false);
    dfs(start, adj, ls, visited);
    return ls;
}

int main() {
    int n = 5;
    vector<int> adj[n+1];

    // Sample graph edges
    adj[0].push_back(1);
    adj[0].push_back(2);
    adj[1].push_back(3);
    adj[2].push_back(4);
    adj[3].push_back(4);
    adj[4].push_back(0);

    int start = 0; // Starting vertex

    vector<int> resultBFS = bfsTraversal(adj, start);
    vector<int> resultDFS = dfsTraversal(adj, start);

    // Print BFS traversal result
    for (int v : resultBFS) {
        cout << v << " ";
    }
    cout << endl;

    // Print DFS traversal result
    for (int v : resultDFS) {
        cout << v << " ";
    }
    cout << endl;

    return 0;
}