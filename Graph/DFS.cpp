#include <bits/stdc++.h>
using namespace std;

const int mx = 1e6 + 5;
const int inf = 0x3f3f3f3f;

vector<int> g[mx];
int n, vis[mx], par[mx];

void dfs(int u){
    vis[u] = 1;
    for(int v : g[u]) if(!vis[v])
        par[v] = u, dfs(v);
}

int main(int argc, const char** argv) {

    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    return 0;
}
