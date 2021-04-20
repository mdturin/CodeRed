#include "bits/stdc++.h"
using namespace std;

const int mx = 1e5+5;

int n;
vector<int> vis;
vector<int> adj[mx];

void dfs(int u){
    vis[u] = 1;
    for(auto v:adj[u])
        if(!vis[v.ff])
            par[v.ff] = u, dfs(v.ff);
}

int ConnectedComponent(){
    int ans = 0; vis.assign(n, 0);
    for(int i=0; i<n; i++)
        if(!vis[i])
            dfs(i), ans++;
    return ans;
}

int main(int argc, const char** argv) {
    return 0;
}