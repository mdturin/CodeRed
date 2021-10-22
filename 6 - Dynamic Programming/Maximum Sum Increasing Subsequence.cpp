#include<bits/stdc++.h>
using namespace std;
const int mx = 2005;

// Maximum Sum (Strictly) Increasing Subsequence

int n, a[mx], dp[mx];

int main(){

    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n;
    for(int i=1; i<=n; ++i) cin >> a[i];
    for(int i=1; i<=n; ++i){
        dp[i] = a[i];
        for(int j=1; j<i; ++j)
            if(a[i] > a[j])
                dp[i] = max(dp[i], a[i]+dp[j]);
    }

    cout << *max_element(dp, dp+n+1) << "\n";

    return 0;
}

