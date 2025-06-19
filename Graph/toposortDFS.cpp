#include <bits/stdc++.h>
using namespace std;

void dfs(int node, vector<vector<int>> & adj, vector<int> &visited, stack<int> &st){
    visited[node] = 1;
    for(auto it: adj[node]){
        dfs(it, adj, visited, st);
    }
    st.push(node);
}

int main() {
    int n = 6; 
    vector<vector<int>> adj = {
        {2, 3}, 
        {3, 4}, 
        {3},    
        {},     
        {5},    
        {}      
    };

    vector<int> visited(n, 0);
    stack<int> st;

    for (int i = 0; i < n; i++) {
        if (!visited[i]) {
            dfs(i, adj, visited, st);
        }
    }

    vector<int> topo;
    while (!st.empty()) {
        topo.push_back(st.top());
        st.pop();
    }

    for (int i : topo) {
        cout << i << " ";
    }
    cout << endl;

    return 0;
}