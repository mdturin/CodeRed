#include<bits/stdc++.h>
using namespace std;

const int MAXN   = 1e4+5;
const int MAXLOG = 15;

int n, h[MAXN];
int par[MAXN][MAXLOG];  /// initialize with -1

vector<int> g[MAXN];

void dfs(int v, int p){
    par[v][0] = p; h[v] = h[p] + 1;
	for(int i=1; i<MAXLOG; i++)
		if(par[v][i-1] != -1)
			par[v][i] = par[par[v][i-1]][i-1];
	for(int u : g[v]) if(u != p) dfs(u, v);
}

int LCA(int v, int u){
	if(h[v] < h[u]) swap(v, u);
	for(int i=MAXLOG-1; i>=0; i--)
		if(par[v][i]!=-1 && h[par[v][i]] >= h[u])
			v = par[v][i];
	if(v == u) return v;
	for(int i=MAXLOG-1; i>=0; i--)
		if(par[v][i] != par[u][i])
			v = par[v][i], u = par[u][i];
	return par[v][0];
}

int main(){
    /// input graph

	dfs(1, 0);           /// precalculation for lca
    int lca = LCA(1, 2); /// getting lca from 1 to 2

    return 0;
}


