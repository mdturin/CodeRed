#include "bits/stdc++.h"
using namespace std;

const int MX = 1e5+5;
const int INF = 1e9+9;

int n, m;
vector<int> vis(MX);
vector<int> adj[MX];
vector<int> par(MX);
vector<int> dist(MX);

void bfs(int s){
    fill(begin(vis), end(vis), 0);
    fill(begin(par), end(par), -1);
    fill(begin(dist), end(dist), INF);
    
    vis[s] = 1; dist[s] = 0;
    queue<int> q; q.push(s);
    while(q.size()){
        int u = q.front(); q.pop();
        for(int &v:adj[u])
        if(!vis[v]){
            vis[v] = 1;
            par[v] = u;
            dist[v] = dist[u]+1;
            q.push(v);
        }
    }
}

int main(int argc, const char** argv) {

    int u, v;
    cin >> n >> m;
    for(int i=0; i<m; i++){
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    bfs(0);

    return 0;
}