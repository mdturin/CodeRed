#include<bits/stdc++.h>
using namespace std;

const int mx = 1e6 + 5;
const int mxk = __lg(mx) + 1;

int n, h[mx];
int par[mx][mxk];  /// initialize with -1

vector<int> g[mx];

void dfs(int v, int p){
    par[v][0] = p; h[v] = h[p] + 1;
	for(int i=1; i<mxk; i++)
		if(par[v][i-1] != -1)
			par[v][i] = par[par[v][i-1]][i-1];
	for(int u : g[v]) if(u != p) dfs(u, v);
}

int get_lca(int u, int v){
	if(h[u] < h[v]) swap(u, v);
	for(int i=mxk-1; i>=0; i--)
		if(~par[u][i] && h[par[u][i]] >= h[v])
			u = par[u][i];
	if(u == v) return u;
	for(int i=mxk-1; i>=0; i--)
		if(~par[u][i] && par[u][i] != par[v][i])
			u = par[u][i], v = par[v][i];
	return par[u][0];
}

int main(){

	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

    /// input graph
    memset(par, -1, sizeof par);

	dfs(1, 0);           	 /// precalculation for lca
    int lca = get_lca(1, 2); /// getting lca from 1 to 2

    return 0;
}


