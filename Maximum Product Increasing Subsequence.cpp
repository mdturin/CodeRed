#include<bits/stdc++.h>
using namespace std;

using ll = long long;
const int mod = 1e9 + 7;
const int mx  = 2e5+5;

/**
    Maximum Product Increasing Subsequence
    Given an array of numbers, find the maximum
    product formed by multiplying numbers of an
    increasing subsequence of that array.
*/

ll a[] = {3, 100, 4, 5, 150, 6};
ll n = sizeof(a)/sizeof(ll);

/**
    Iterative Method :
        complexity : O(n*n)
        space : O(n)
*/

ll dp[mx];
ll maxProIncSubIte(){
    for(int i=0; i<n; i++) dp[i] = a[i];
    for(int i=1; i<n; i++)
    for(int j=0; j<i; j++)
        if(a[i] > a[j])
            dp[i] = max(dp[i], dp[j]*a[i]);
    return *max_element(dp, dp+n);
}

int main(){
    cout << maxProIncSubIte() << "\n";
    return 0;
}

