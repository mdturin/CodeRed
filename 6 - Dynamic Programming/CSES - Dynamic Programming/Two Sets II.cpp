#include<bits/stdc++.h>
using namespace std;
using ll = long long;

const int md = 1e9+7;
const int mx = 500+5;

template <typename T>
T power(T v, T p, T m=md) {
    v %= m; T r = 1;
    while (p > 0) {
        if (p & 0x1)
            r = (1LL*r*v)%m;
        v = (1LL*v*v)%m; p >>= 1;
    }return r;
}

ll n, m, dp[mx*mx];
ll inv = power<ll>(2, md-2);

int main(){

    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n;
    m = n * (n + 1) / 2;

    if(m & 1) cout << 0 << "\n";
    else{
        m >>= 1; dp[0] = 1;
        for(int i=1; i<=n; ++i)
        for(int j=m; j>=i; --j)
            dp[j] = (dp[j] + dp[j-i]) % md;

        if(dp[m] & 1)
            dp[m] = 1LL * dp[m] * inv % md;
        else dp[m] >>= 1;
        cout << dp[m] << "\n";
    }

    return 0;
}
