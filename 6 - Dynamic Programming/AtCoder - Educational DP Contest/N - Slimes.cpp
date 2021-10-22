#include<bits/stdc++.h>
using namespace std;
using ll = long long;
using ii = pair<int,int>;

#define ff first
#define se second

const int md = 1e9+7;
const int mx = 400+5;

ll dp[mx][mx];
int n; ll a[mx];

int main(){

    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n;
    for(int i=1; i<=n; ++i){
        cin >> a[i], a[i] += a[i-1];
        fill(dp[i]+1, dp[i]+n+1, LLONG_MAX);
    }

    for(int i=1; i<=n; ++i)
        dp[i][i] = a[i] - a[i-1];

    for(int len=2; len<=n; ++len)
    for(int i=1,j=len; j<=n; ++i, ++j){
        for(int k=i; k<j; ++k)
            dp[i][j] = min(dp[i][j], a[j]-a[i-1]+dp[i][k]+dp[k+1][j]);
    }cout << dp[1][n]-a[n] << "\n";

    return 0;
}
