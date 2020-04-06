#include "bits/stdc++.h"
using namespace std;

const int mx = 1e5+5;
using vi = vector<int>;

int n, m, timer = 0;
vector<int> in, out;
vector<int> adj[mx];
vector< vector<int> > up;

// Pre-processing O(n log n)
// Query O( log n )

inline bool isAncestor(int u, int v){
    return in[u]<=in[v] && out[u]>=out[v];}

int lca(int u, int v){
    if(isAncestor(u,v)) return u;
    if(isAncestor(v,u)) return v;

    for(int i=m-1; i>=0; i--)
        if(!isAncestor(up[u][i], v))
            u = up[u][i];
    return up[u][0];
}

void dfs(int u, int p){
    in[u] = timer++; up[u][0] = p;
    for(int i=1; i<m; i++)
        up[u][i] = up[up[u][i-1]][i-1];
    for(int &v : adj[u])
        if(v != p)
            dfs(v, u);
    out[u] = timer++;
}

void init(int root = 0){
    timer = 1;
    m = log2(n) + 1;
    in = vector<int>(n);
    out = vector<int>(n);
    up = vector< vi >(n, vi(m));
    dfs(root, root);
}

void allClear(){
    for(int i=0; i<mx; i++)
        adj[i].clear();
}

int main(int argc, const char** argv) {

    n = 8;
    adj[1] = {2,3,4};
    adj[2] = {1,5,6};
    adj[3] = {1};
    adj[4] = {1,7};
    adj[5] = {2};
    adj[6] = {2};
    adj[7] = {4};

    init(1);

    for(int i=1; i<n; i++)
    for(int j=1; j<n; j++)
        cout << i << ' '
             << j << ' '
             << lca(i, j) << '\n';

    return 0;
}