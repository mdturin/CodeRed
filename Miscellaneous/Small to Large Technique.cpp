#include<bits/stdc++.h>
using namespace std;

#define pb push_back
const int mx = 1e5+5;

vector<int> g[mx];
int n, m, q, a[mx];

set<int> st[mx];
int ans[mx], par[mx];

void dfs(int u, int p){
    st[u].insert(a[u]); par[u] = u;
    for(int v : g[u]){
        if(v == p) continue; dfs(v, u);
        if(st[par[u]].size() < st[par[v]].size())
            swap(par[u], par[v]);
        for(int x : st[par[v]])
            st[par[u]].insert(x);
        st[par[v]].clear();
    }ans[u] = st[par[u]].size();
}

int main(){

    ios_base::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);

    cin >> n; m=n-1;
    for(int i=1; i<=n; i++) cin >> a[i];
    while(m--){
        int u, v; cin >> u >> v;
        g[u].pb(v); g[v].pb(u);
    }dfs(1, 0);

    cin >> q;
    for(int i=0; i<q; i++){
        int x; cin >> x;
        cout << ans[x] << "\n";
    }

    return 0;
}
