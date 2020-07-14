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

/** directed path finding */
vector<int> ans;
bool cycle = false;

void dfs(int u, int p) {
    if(cycle) return;
    vis[u] = 1; par[u] = p;
    for(int v : g[u]){
        if(!vis[v]) dfs(v,u);
        else if(vis[v] == 1){
            if(cycle) return;
            ans.push_back(v);
            while(v != u){
                ans.push_back(u);
                u = par[u];
            }ans.push_back(v);
            reverse(ans.begin(),ans.end());
            cycle=true; return;
        }
    }vis[u] = 2;
}

void path_finding_directed(){
    for(int i=1; i<=n; i++)
        if(!vis[i] && !cycle)
            dfs(i, 0);

    if(!cycle)
        cout << "IMPOSSIBLE\n";
    else {
        cout << ans.size() << "\n";
        for(int u : ans)
            cout << u << " ";
    }
}

int main(int argc, const char** argv) {
    return 0;
}
