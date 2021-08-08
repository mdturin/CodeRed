#include<bits/stdc++.h>
using namespace std;
using ll = long long;
using ii = pair<int,int>;

#define ff first
#define se second

const int md = 1e9+7;
const int mx = 1e6+5;

int n, a[mx][3], dp[mx][3];

int main(){

    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n;
    for(int i=1; i<=n; ++i)
        for(int j=0; j<3; ++j)
            cin >> a[i][j];

    for(int i=1; i<=n; ++i){
        dp[i][0] = a[i][0] + max(dp[i-1][1], dp[i-1][2]);
        dp[i][1] = a[i][1] + max(dp[i-1][0], dp[i-1][2]);
        dp[i][2] = a[i][2] + max(dp[i-1][1], dp[i-1][0]);
    }cout << *max_element(dp[n], dp[n]+3) << "\n";

    return 0;
}
