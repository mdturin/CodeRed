 #include<bits/stdc++.h>
using namespace std;

#define mem(a,v) memset(a,v,sizeof a) 
#define pb push_back 

using vi = vector<int>;

const int mod = 1e9 + 7;
const int mx  = 1000;

vi adj[mx];
int dp[mx];
int LIS(int u){
    if(dp[u] != -1) return dp[u];

    int ans1 = 0, ans2 = 1;
    for(int i=0; i<adj[u].size(); i++){
        ans1 += LIS(adj[u][i]);
        int v = adj[u][i];
        for(int j=0; j<adj[v].size(); j++)
            ans2 += LIS(adj[v][j]);
    }
    return dp[u] = max(ans1, ans2);
}

int main(){
    mem(dp, -1);
    adj[20].pb(8);
    adj[8].pb(4);
    adj[8].pb(12);
    adj[12].pb(10);
    adj[12].pb(14);
    adj[20].pb(22);
    adj[22].pb(25);

    cout << LIS(20) << "\n";

    return 0;
}

