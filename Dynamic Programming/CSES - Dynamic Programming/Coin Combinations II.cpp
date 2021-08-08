#include<bits/stdc++.h>
using namespace std;
const int mx = 1e6 + 5;
const int md = 1e9 + 7;

int dp[mx];
int n, w, a[105];

int main(){

    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n >> w;
    for(int i=1; i<=n; ++i) cin >> a[i];

    dp[0] = 1;
    for(int i=1; i<=n; ++i)
    for(int j=a[i]; j<=w; ++j)
        dp[j] = (dp[j] + dp[j-a[i]]) % md;

    cout << dp[w] << "\n";

    return 0;
}
