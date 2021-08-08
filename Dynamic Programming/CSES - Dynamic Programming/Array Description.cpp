#include<bits/stdc++.h>
using namespace std;
using ll = long long;
using ii = pair<int,int>;

#define ff first
#define se second

const int md = 1e9+7;
const int mx = 1e5+5;

int n, m, a[mx];
ll dp[101], cur[101];

int main(){

    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n >> m;
    for(int i=1; i<=n; ++i) cin >> a[i];

    if(a[1] == 0){
        fill(dp+1, dp+m+1, 1LL);
    }else dp[a[1]] = 1LL;

    for(int i=2; i<=n; ++i){
        int x = a[i];
        memset(cur, 0, sizeof cur);
        if(x == 0){
            for(int j=1; j<=m; ++j)
                cur[j] = (dp[j-1]+dp[j]+dp[j+1]) % md;
        }else cur[x] = (dp[x-1]+dp[x]+dp[x+1]) % md;
        memcpy(dp, cur, sizeof dp);
    }

    ll ans = 0;
    for(int i=1; i<=m; ++i)
        ans = (ans + dp[i]) % md;
    cout << ans << "\n";

    return 0;
}
