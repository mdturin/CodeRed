#include<bits/stdc++.h>
using namespace std;
using ll = long long;
using ii = pair<int,int>;

#define ff first
#define se second

const int md = 1e9+7;
const int mx = 1e6+5;

int n, mod;
ll extra[mx], f[mx];
vector<int> g[mx], child[mx];

inline void dfs(int u, int p){
    for(int v : g[u]){
        if(v == p) continue;
        child[u].push_back(v);
        dfs(v, u);
    }

    ll pre = 1;
    for(int v : child[u]){
        extra[v] = pre;
        pre = 1LL * pre * (f[v]+1LL) % mod;
    }

    f[u] = pre; pre = 1;
    reverse(child[u].begin(), child[u].end());
    for(int v : child[u]){
        extra[v] = 1LL * extra[v] * pre % mod;
        pre = 1LL * pre * (f[v]+1) % mod;
    }
}

inline void solve(int u, int p, ll res){
    f[u] = 1LL * (res + 1) * f[u] % mod;
    for(int v : g[u]){
        if(v == p) continue;
        solve(v, u, 1LL * (res+1) * extra[v] % mod);
    }
}

int main(){

    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n >> mod;
    for(int i=1,u,v; i<n; ++i){
        cin >> u >> v;
        g[u].push_back(v);
        g[v].push_back(u);
    }

    dfs(1, 0); solve(1, 0, 0);
    for(int i=1; i<=n; ++i)
        cout << f[i] << "\n";

    return 0;
}

