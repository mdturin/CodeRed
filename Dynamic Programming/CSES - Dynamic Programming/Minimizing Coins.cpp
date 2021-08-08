#include<bits/stdc++.h>
using namespace std;
const int mx  = 1e6 + 5;
const int INF = 1e9 + 9;

int dp[mx];
int n, w, a[105];

int main(){

    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n >> w;
    fill(dp, dp+w+1, INF);
    for(int i=1; i<=n; ++i) cin >> a[i];

    dp[0] = 0;
    for(int i=1; i<=n; ++i)
    for(int j=a[i]; j<=w; ++j)
        dp[j] = min(dp[j], 1+dp[j-a[i]]);

    int ans = dp[w];
    if(ans == INF) ans = -1;
    cout << ans << "\n";

    return 0;
}
