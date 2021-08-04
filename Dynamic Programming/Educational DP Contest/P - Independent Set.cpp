#include<bits/stdc++.h>
using namespace std;
using ll = long long;
using ii = pair<int,int>;

#define ff first
#define se second

const int md = 1e9+7;
const int mx = 1e6+5;

int n, dp[mx][2];
vector<int> g[mx];

inline int dfs(int u, int p, int c){
    int &ans = dp[u][c];
    if(ans) return ans; ans=1;
    for(int v : g[u]){
        if(v == p) continue;
        int res = dfs(v, u, 0);
        if(c==0) res += dfs(v, u, 1);
        res %= md;
        ans = (1LL * ans * res) % md;
    }return ans;
}

int main(){

    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n;
    for(int i=1,u,v; i<n; ++i){
        cin >> u >> v;
        g[u].push_back(v);
        g[v].push_back(u);
    }

    int ans = dfs(1, 0, 0);
    ans += dfs(1, 0, 1);
    ans %= md;
    cout << ans << "\n";

    return 0;
}

