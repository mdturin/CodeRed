#include "bits/stdc++.h"
using namespace std;

const int mx = 1e5+5;

int n, m;
vector<int> adj[mx];
vector<int> vis, rec;

/** for undirected graph */
bool isCycle(int u, int p){
    vis[u] = 1;
    for(auto v:adj[u])
        if(!vis[v]) return isCycle(v, u);
        else if(v != p) return true;
    return false;
}

/** for directed graph */
bool isCycleUtil(int u){
    if(!vis[u]){
        vis[u] = 1; rec[u] = 1;
        for(auto v:adj[u])
            if(!vis[v] && isCycleUtil(v))
                return true;
            else if(rec[v]) return true;
    }
    rec[u] = 0; return false;
}

bool isCycle(){
    vis.assign(n, 0);
    rec.assign(n, 0);
    for(int i=0; i<n; i++)
        if(isCycleUtil(i))
            return true;
    return false;
}

int main(int argc, const char** argv) {
    return 0;
}