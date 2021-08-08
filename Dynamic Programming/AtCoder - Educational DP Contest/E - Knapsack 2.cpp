#include<bits/stdc++.h>
using namespace std;

const int mx = 100+5;
const int W  = 1e5+5;

long long dp[W];
int n, wei, w[mx], v[mx];

int main(){

    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n >> wei;
    for(int i=1; i<=n; ++i)
        cin >> w[i] >> v[i];

    fill(dp, dp+W, (int)(1e9));
    int val = accumulate(v, v+n+1, 0);

    dp[0] = 0;
    for(int i=1; i<=n; ++i)
        for(int j=val; j>=v[i]; --j)
            dp[j] = min(dp[j], dp[j-v[i]]+w[i]);

    int ans = 0;
    for(int i=0; i<=val; ++i)
        if(dp[i] <= wei)
            ans = i;
    cout << ans << "\n";

    return 0;
}


