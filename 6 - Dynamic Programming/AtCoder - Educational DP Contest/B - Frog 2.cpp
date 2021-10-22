#include<bits/stdc++.h>
using namespace std;
using ll = long long;
using ii = pair<int,int>;

#define ff first
#define se second

const int md = 1e9+7;
const int mx = 1e6+5;

int n, k, h[mx], dp[mx];

int main(){

    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n >> k;
    for(int i=0; i<n; ++i) cin >> h[i];

    dp[0] = 0;
    for(int i=1; i<n; ++i){
        dp[i] = INT_MAX;
        for(int j=1; j<=k && i>=j; ++j)
            dp[i] = min(dp[i], dp[i-j]+abs(h[i]-h[i-j]));
    }cout << dp[n-1] << "\n";

    return 0;
}

