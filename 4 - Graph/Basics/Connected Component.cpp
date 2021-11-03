#include<bits/stdc++.h>
using namespace std;
const int mx = 1e6 + 5;

vector<int> g[mx];
int n, vis[mx], par[mx];

void dfs(int u, int p = -1){
    vis[u] = 1; par[u] = p;
    for(int v : g[u])
        if(!vis[v])
            dfs(v, u);
}

int Connected_Component(){
    memset(vis, 0, sizeof vis);
    int ans = 0;
    for(int i=0; i<n; i++)
        if(!vis[i])
            dfs(i), ans++;
    return ans;
}

int main(int argc, const char** argv) {
    return 0;
}
