#include "bits/stdc++.h"
using namespace std;

#define ff first 
#define se second 
#define pb push_back 

using vi = vector<int>;
using pii = pair<int,int>;

int n, m, counter;
const int mx = 1e5+5;

vector<int> par, ts;
vector<int> vis,low;
vector<pii> adj[mx];
vector<int> radj[mx];

/// Method 1 : using one dfs
/// Strongly Connected Commponent with directed graph
vi store; int numSCC;
void tarjan(int u){
    low[u] = vis[u] = ++counter;
    store.push_back(u);
    for(int j=0; j<adj[u].size(); j++){
        int v = adj[u][j].ff;
        if(!vis[v]) tarjan(v);
        if(vis[v])
            low[u] = min(low[u], low[v]);
    }
    if(low[u] == vis[u]){ /// u is the root of scc
        numSCC++; int v;
        do{
            v = store.back(); store.pop_back();
            /// do something with this cycle
        } while(u != v);
    }
}

void SCC(){
    vis.assign(n, 0);
    low.assign(n, 0);
    counter = numSCC = 0;
    for(int i=0; i<n; i++)
        if(!vis[i])
            tarjan(i);
}

/// method 2 : using topo sort and dfs
void dfs(int u){
    vis[u] = 1;
    for(auto &v:adj[u])
        if(!vis[v.ff])
            par[v.ff] = u, dfs(v.ff);
    ts.push_back(u);
}

void topologicalSort(){
    ts.clear();
    vis.assign(n, 0);
    par.assign(n, -1);

    for(int i=0; i<n; i++)
        if(!vis[i])
            dfs(i);

    reverse(begin(ts),end(ts));
}

vector<int> cycle;
void dfs2(int u){
    vis[u] = 1;
    cycle.pb(u);
    for(int &v:radj[u])
        if(!vis[v])
            dfs2(v);
}

void SCC2(){
    vis.assign(n, 0);
    for(int i=0; i<n; i++){
        if(!vis[i]){
            cycle.clear();
            dfs2(i);
            for(int &u:cycle);
                // do something with this cyle;
        }
    }
}

int main(int argc, const char** argv) {
    return 0;
}