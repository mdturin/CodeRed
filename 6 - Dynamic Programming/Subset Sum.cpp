/**
    Subset Sum Problem
    Given a set of non-negative integers, and
    a value sum, determine if there is a subset
    of the given set with sum equal to given sum.
*/

#include<bits/stdc++.h>
using namespace std;
const int mx  = 2005;

int dp[mx];
int n, w, a[mx];

int main(){

    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n >> w;
    for(int i=1; i<=n; ++i) cin >> a[i];

    dp[0] = 1;
    for(int i=1; i<=n; ++i)
    for(int j=w; j>=a[i]; --j)
        dp[j] |= dp[j-a[i]];

    cout << (dp[w]?"Yes":"No") << "\n";

    return 0;
}

