#include<bits/stdc++.h>
using namespace std;
using ll = long long;
using ii = pair<int,int>;

#define ff first
#define se second

const int md = 1e9+7;
const int mx = 1e6+5;

int n, m, vis[mx], dp[mx];
vector<int> g[mx], gr[mx], ord;

inline void dfs(int u){
    vis[u] = 1;
    for(int v : g[u])
        if(!vis[v])
            dfs(v);
    ord.push_back(u);
}

int main(){

    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n >> m;
    int u, v; while(m--){
        cin >> u >> v;
        g[u].push_back(v);
        gr[v].push_back(u);
    }

    ord.clear();
    for(int i=1; i<=n; ++i)
        if(!vis[i])
            dfs(i);
    reverse(ord.begin(), ord.end());

    for(int u : ord){
        dp[u] = 0;
        for(int v : gr[u])
            dp[u] = max(dp[u], 1+dp[v]);
    }cout << *max_element(dp+1, dp+n+1) << "\n";

    return 0;
}

