/**
    Matrix Chain Multiplication
    Given a sequence of matrices, find the most efficient
    way to multiply these matrices together. The problem is
    not actually to perform the multiplications, but merely
    to decide in which order to perform the multiplications.
*/

#include<bits/stdc++.h>
using namespace std;
using ll = long long;
const int mx  = 405;

int n, a[mx];
ll dp[mx][mx];

int sum(int i, int j){
    return a[j] - a[i-1];
}

int main(){

    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n;
    for(int i=1; i<=n; ++i) cin >> a[i];
    for(int i=1; i<=n; ++i) a[i] += a[i-1];

    for(int i=1; i<=n; ++i) dp[i][i] = 0;
    for(int i=1, j=2; j<=n; ++i, ++j)
        dp[i][j] = 1LL * sum(i, i) * sum(j, j);

    for(int len=3; len<=n; ++len)
    for(int i=1, j=len; j<=len; ++i, ++j){
        dp[i][j] = LLONG_MAX;
        for(int k=i; k<j; ++k)
            dp[i][j] = min(dp[i][j],
                           sum(i, k) * sum(k+1, j) + dp[i][k] + dp[k+1][j]);
    }

    cout << dp[1][n] << "\n";

    return 0;
}

