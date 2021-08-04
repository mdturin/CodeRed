#include<bits/stdc++.h>
using namespace std;

const int mx = 105;
const int W  = 1e5+5;

long long dp[W];
int n, wei, w[mx], v[mx];

int main(){

    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n >> wei;
    for(int i=1; i<=n; ++i)
        cin >> w[i] >> v[i];

    for(int i=1; i<=n; ++i)
        for(int j=wei; j>=w[i]; --j)
            dp[j] = max(dp[j], dp[j-w[i]]+v[i]);
    cout << *max_element(dp, dp+wei+1) << "\n";

    return 0;
}

