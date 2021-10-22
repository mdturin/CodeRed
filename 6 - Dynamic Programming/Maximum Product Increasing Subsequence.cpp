/**
    Maximum Product Increasing Subsequence
    Given an array of numbers, find the maximum
    product formed by multiplying numbers of an
    increasing subsequence of that array.
*/

#include<bits/stdc++.h>
using namespace std;
using ll = long long;
const int mx  = 2e5+5;

ll dp[mx];
int n, a[mx];

int main(){

    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n;
    for(int i=1; i<=n; i++) cin >> a[i];
    for(int i=1; i<=n; i++){
        dp[i] = a[i];
        for(int j=1; j<i; j++)
            if(a[i] > a[j])
                dp[i] = max(dp[i], (ll)dp[j]*a[i]);
    }

    cout << *max_element(dp, dp+n+1) << "\n";

    return 0;
}

