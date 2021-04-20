#include "bits/stdc++.h"
using namespace std;

#define ff first 
#define se second 
#define pb push_back 

using vi = vector<int>;
using pii = pair<int,int>;

int n, m, counter;
const int mx = 1e5+5;

/// Method 1 : using one dfs
/// Strongly Connected Commponent with directed graph
Method 1:
{
    vector<int> par, ts;
    vector<int> vis,low;
    vector<pii> adj[mx];
    vector<int> radj[mx];

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

    in main(){
           int n;
            ... reading n ...
            for (;;) {
                int a, b;
                ... reading next edge (a,b) ...
                adj[a].push_back (b);
            }
    }
}

/// Source : https://cp-algorithms.com/graph/strongly-connected-components.html
Method 2 :
{
    vector < vector<int> > g, gr;
    vector<bool> used;
    vector<int> order, component;

    void dfs1 (int v) {
        used[v] = true;
        for (size_t i=0; i<g[v].size(); ++i)
            if (!used[ g[v][i] ])
                dfs1 (g[v][i]);
        order.push_back (v);
    }

    void dfs2 (int v) {
        used[v] = true;
        component.push_back (v);
        for (size_t i=0; i<gr[v].size(); ++i)
            if (!used[ gr[v][i] ])
                dfs2 (gr[v][i]);
    }

    in main {
        int n;
        ... reading n ...
        for (;;) {
            int a, b;
            ... reading next edge (a,b) ...
            g[a].push_back (b);
            gr[b].push_back (a);
        }

        used.assign (n, false);
        for (int i=0; i<n; ++i)
            if (!used[i])
                dfs1 (i);
        used.assign (n, false);
        for (int i=0; i<n; ++i) {
            int v = order[n-1-i];
            if (!used[v]) {
                dfs2 (v);
                ... printing next component ...
                component.clear();
            }
        }
    }
}
