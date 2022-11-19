#include <bits/stdc++.h>
using namespace std;

const int mx = 1e6 + 5;
using ii = pair<int,int>;

#define ff first
#define se second

vector<int> g[mx];
vector<ii> bridges;
int n, m, counter, root, child;
int low[mx], vis[mx], par[mx], point[mx];

void dfs_apb(int u, int p){
  low[u] = vis[u] = counter++; par[u] = p;
  for(int &v : g[u]){
    if(!vis[v]){
      child += (u == root); dfs_apb(v, u);
      if(low[v] >= vis[u]) point[u] = 1;
      if(low[v] >  vis[u])
        bridges.emplace_back(u, v);
      low[u] = min(low[u], low[v]);
    }else if(v != par[u])
      low[u] = min(low[u], vis[v]);
  }
}

void Artucaltion_Points_Bridges(){
  counter = 1; bridges.clear();
  memset(low, 0, sizeof low);
  memset(vis, 0, sizeof vis);
  memset(point, 0, sizeof point);

  for(int i=0; i<n; i++){
    if(vis[i]) continue;
    root = i; child = 0;
    dfs_apb(i, -1);
    point[i] = (child > 1);
  }
}

int main(int argc, const char** argv) {
    return 0;
}
