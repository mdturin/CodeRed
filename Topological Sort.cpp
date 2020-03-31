#include "bits/stdc++.h"
using namespace std;

const int mx = 1e3+5;

int n;
vector<int> ts;
vector<int> adj[mx];
vector<int> vis,par;

void dfs(int u){
    vis[u] = 1;
    for(auto &v:adj[u])
        if(!vis[v])
            par[v] = u, dfs(v);
    ts.push_back(u);
}

void topologicalSort(){
    ts.clear();
    vis.assign(n, 0);

    for(int i=0; i<n; i++)
        if(!vis[i])
            dfs(i);

    reverse(begin(ts),end(ts));
}

int main(int argc, const char** argv) {
    return 0;
}