 #include<bits/stdc++.h>
using namespace std;
const int mx  = 1005;

int dp[mx];
vector<int> g[mx];

int solve(int u){
    int &ans = dp[u];
    if(~ans) return ans; ans=0;

    int ans1 = 0, ans2 = 1;
    for(int v : g[u]){
        ans1 += solve(v);
        for(int w : g[v])
            ans2 += solve(w);
    }return ans = max(ans1, ans2);
}

int main(){

    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n >> m;
    while(m--){
        int u, v; cin >> u >> v;
        g[u].push_back(v);
        g[v].push_back(u);
    }

    memset(dp, -1, sizeof dp);
    cout << solve(1) << "\n";

    return 0;
}

