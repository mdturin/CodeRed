#include <bits/stdc++.h>
using namespace std;
const int md = 1e9 + 7;
const int mx = 1e6 + 5;

int n, dp[mx];

int main(){

    ios_base::sync_with_stdio(0);
    cin.tie(nullptr);

    cin >> n;

    dp[0] = 1;
    for(int i=1; i<=n; ++i)
        for(int j=1; j<=6; ++j) if(i >= j)
            dp[i] = (dp[i] + dp[i-j]) % md;
    cout << dp[n] << "\n";

    return 0;
}
