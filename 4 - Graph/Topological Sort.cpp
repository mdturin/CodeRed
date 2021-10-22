#include <bits/stdc++.h>
using namespace std;
using ii = pair<int, int>;

#define ff first
#define se second

const int mx = 1e6 + 5;
const int inf = 0x3f3f3f3f;

vector<int> g[mx], ts;
int n, vis[mx], par[mx];

/** if there is no cycle topo is possilbe */

void dfs(int u){
    vis[u] = 1;
    for(int &v : g[u])
        if(!vis[v])
            par[v] = u, dfs(v);
    ts.push_back(u);
}

void topo_sort(){
    ts.clear();
    memset(vis, 0, sizeof vis);
    for(int i=0; i<n; i++)
        if(!vis[i]) dfs(i);
    reverse(ts.begin(), ts.end());
}

int main(int argc, const char** argv) {
    return 0;
}
