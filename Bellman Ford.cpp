#include "bits/stdc++.h"
using namespace std;

const int MX = 1e5+5;
const int INF = 1e9+9;

int n, m;
vector<int> cap[MX];
vector<int> adj[MX];
vector<int> dist(MX);

void bellManFord(int s){
    fill(begin(dist), end(dist), INF);
    dist[s] = 0;

    /// iterating (n-1) times, 
    /// Complexity O(VE)
    for(int step=1; step<n; step++)
    for(int u=0; u<n; u++)
    for(int j=0; j<adj[u].size(); j++){
        int v = adj[u][j], w = cap[u][j];
        if(dist[v] > dist[u] + w)
            dist[v] = dist[u] + w;
    }

    for(int u=0; u<n; u++)
    for(int j=0; j<adj[u].size(); j++){
        int v = adj[u][j], w = cap[u][j];
        if(dist[v] > dist[u] + w)
            /// negative cycle found, dfs(u)
            /// can found the whole cirle;
            /// return true;
    }
    /// return false;
}

int main(int argc, const char** argv) {
 
    int u, v, w;
    cin >> n >> m;
    while(m--){
        cin >> u >> v >> w; /// 0 index
        adj[u].push_back(v);
        cap[u].push_back(w);
    }

    int s; cin >> s;
    bellManFord(s);

    return 0;
}
