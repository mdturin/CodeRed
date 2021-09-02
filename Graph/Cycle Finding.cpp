#include <bits/stdc++.h>
using namespace std;
const int mx = 1e6 + 5;

int n, m;
vector<int> g[mx];
int vis[mx], rec[mx];

/** undirected graph */
bool is_cycle(int u, int p){
    vis[u] = 1;
    bool cycle = false;
    for(int v : g[u]){
        if(!vis[v])
            cycle |= is_cycle(v, u);
        else if(v != p) return true;
    }return cycle;
}

/** directed graph */
bool cycle_util(int u){
    if(!vis[u]){
        vis[u] = 1; rec[u] = 1;
        for(int v : g[u])
            if(!vis[v] && isCycleUtil(v))
                return true;
            else if(rec[v]) return true;
    }rec[u] = 0; return false;
}

bool is_cycle(){
    memset(vis, 0, sizeof vis);
    memset(rec, 0, sizeof rec);
    for(int i=0; i<n; i++)
        if(cycle_util(i))
            return true;
    return false;
}

int main(int argc, const char** argv) {
    return 0;
}
