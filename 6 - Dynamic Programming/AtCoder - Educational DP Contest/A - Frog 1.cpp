#include<bits/stdc++.h>
using namespace std;
using ll = long long;
using ii = pair<int,int>;

#define ff first
#define se second

const int md = 1e9+7;
const int mx = 1e6+5;

int n, h[mx], dp[mx];

int main(){

    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n;
    for(int i=0; i<n; ++i) cin >> h[i];

    dp[0] = 0;
    dp[1] = abs(h[1] - h[0]);
    for(int i=2; i<n; ++i)
        dp[i] = min(dp[i-1] + abs(h[i] - h[i-1]),
                    dp[i-2] + abs(h[i] - h[i-2]));
    cout << dp[n-1] << "\n";

    return 0;
}
