#include<bits/stdc++.h>
using namespace std;
using ll = long long;

const int mx = 500+5;
const int INF = 1e9+7;

int n, m;
int dp[mx][mx];

int main(){

    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n >> m;
    for(int i=1; i<=n; ++i)
    for(int j=1; j<=m; ++j){
        dp[i][j] = INF;
        if(i == j) dp[i][j] = 0;
        for(int k=1; k<i; ++k)
            dp[i][j] = min(dp[i][j], 1+dp[k][j]+dp[i-k][j]);
        for(int k=1; k<j; ++k)
            dp[i][j] = min(dp[i][j], 1+dp[i][k]+dp[i][j-k]);
    }

    cout << dp[n][m] << "\n";

    return 0;
}
