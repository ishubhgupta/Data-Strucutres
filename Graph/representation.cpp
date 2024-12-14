#include <bits/stdc++.h>
using namespace std;

void representationUsingAdjMatOfUG(int n, int m) {
    int adj[n+1][m+1];
    for(int i = 0; i<m; i++){
        int u, v;
        cin>>u>>v;
        adj[u][v] = 1;
        adj[v][u] = 1;
    }
}

void representationUsingAdjListOfUG(int n, int m){
    vector<int> adj[n+1];
    for(int i = 0; i< m; i++){
        int u, v;
        cin >>u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
}


void representationUsingAdjListOfDG(int n, int m){
    vector<int> adj[n+1];
    for(int i = 0; i< m; i++){
        int u, v;
        cin >>u >> v;
        adj[u].push_back(v);
    }
}

void representationUsingAdjListOfDGWeighted(int n, int m, int w){
    vector<pair<int, int>> adj[n+1];
    for(int i = 0; i< m; i++){
        int u, v;
        cin >>u >> v >> w;
        adj[u].push_back({v, w});
    }
}

int main() {
    int n, m, w;
    cin>>n>>m;
    // representationUsingAdjMatOfUG(n, m);
    // representationUsingAdjListOfUG(n, m);
    // representationUsingAdjListOfDG(n, m);
    cin >> w;
    representationUsingAdjListOfDGWeighted(n, m, w);
    return 0;
}