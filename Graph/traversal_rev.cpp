#include <bits/stdc++.h>
using namespace std;

vector<int> bfs(int start, vector<int> adj[], int n){
    int visited[n+1] ={0};
    queue<int> q;
    visited[start] = 1;
    q.push(start);

    vector<int> bfsOrder;
    while(!q.empty()){
        int node = q.front();
        q.pop();
        bfsOrder.push_back(node);
        for(auto x: adj[node]){
            if(!visited[x]){
                visited[x] = 1;
                q.push(x);
            }
        }
    }
    return bfsOrder;
}

void dfs(vector<int> adj[], vector<int> &dfsOrder, int start, vector<int> &visited, int n){
    visited[start] = 1;
    dfsOrder.push_back(start);
    for(auto x: adj[start]){
        if(!visited[x]){
            dfs(adj, dfsOrder, x, visited, n);
        }
    }
}

int main() {
    int n = 9;
    vector<int> adj[n+1];

    adj[1] = {2, 6};
    adj[2] = {1, 3, 4};
    adj[3] = {2};
    adj[4] = {2, 5};
    adj[5] = {4, 8};
    adj[6] = {1, 7, 9};
    adj[7] = {6, 8, 9};
    adj[8] = {5, 7};
    adj[9] = {6};

    vector<int> bfsorder = bfs(1, adj, n);
    for(auto x: bfsorder){
        cout<<x<<" ";
    }
    cout<<endl;

    vector<int> dfsorder;
    vector<int> visited(n+1, 0);  // Create visited array in main
    dfs(adj, dfsorder, 1, visited, n);
    for(auto x: dfsorder){
        cout<<x<<" ";
    }
    cout<<endl;


    return 0;
}