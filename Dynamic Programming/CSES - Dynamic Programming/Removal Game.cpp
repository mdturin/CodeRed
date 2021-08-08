#include<bits/stdc++.h>
using namespace std;
using ll = long long;

const int md = 1e9+7;
const int mx = 5e3+5;

ll dp[mx][mx];
int n; ll a[mx];

ll sum(int i, int j){
    return a[j] - a[i-1];}

int main(){

    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n;
    for(int i=1; i<=n; ++i)
        cin >> a[i], a[i] += a[i-1];

    for(int i=1; i<=n; ++i) dp[i][i] = sum(i, i);
    for(int i=1, j=2; j<=n; ++i, ++j)
        dp[i][j] = max(sum(i,i), sum(j,j));
    for(int len=3; len<=n; ++len)
    for(int i=1, j=len; j<=n; ++i, ++j)
        dp[i][j] = sum(i, j) - min(dp[i+1][j], dp[i][j-1]);

    cout << dp[1][n] << "\n";

    return 0;
}
