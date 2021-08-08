#include <bits/stdc++.h>
using namespace std;

const int INF = 1e9+9;
const int mx = 20;

int dp[mx][1<<mx];
int n, dist[mx][mx];

int tsp(int idx, int mask){
    if(mask == 0)
        return dist[idx][0];

    int &ans = dp[idx][mask];
    if(~ans) return ans; ans = INF;

    for(int i=0; i<n; i++) if((mask >> i) & 1)
        ans = min(ans, dist[idx][i]+tsp(i, mask^(1<<i)));
    return ans;
}

int main(){

    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n;
    for(int i=0; i<n; ++i)
    for(int j=0; j<n; ++j)
        cin >> dist[i][j];

    memset(dp, -1, sizeof dp);
    cout << tsp(0, (1<<n)-1) << '\n';

    return 0;
}
