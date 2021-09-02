#include <bits/stdc++.h>
using namespace std;
using ii = pair<int, int>;

#define ff first
#define se second

const int mx = 1e6 + 5;
const int inf = 0x3f3f3f3f;

int n, m, vis[mx];
vector<int> ts, cycle;
vector<vector<int>> g, gr, scc;

void topo_dfs(int u){
    vis[u] = 1;
    for(int &v : g[u])
        if(!vis[v]) topo_dfs(v);
    ts.push_back(u);
}

void topo_sort(){
    ts.clear();
    memset(vis, 0, sizeof vis);
    for(int i=0; i<n; i++)
        if(!vis[i]) topo_dfs(i);
    reverse(ts.begin(), ts.end());
}

void scc_dfs(int u) {
    vis[u] = 1;
    cycle.push_back(u);
    for (int v : gr[u])
        if (!vis[v]) scc_dfs(v);
}

void get_scc(){
    topo_sort();
    memset(vis, 0, sizeof vis);
    for(int u : ts) if(!vis[u]){
        cycle.clear();
        scc_dfs(u);
        scc.emplace_back(cycle);
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n >> m;
    int u, v; while(m--){
        cin >> u >> v;
        g[u].push_back(v);
        gr[v].push_back(u);
    }

    get_scc();
    for(auto cycle : scc){
        for(auto it : cycle)
            cout << it << " ";
        cout << endl;
    }

    return 0;
}
