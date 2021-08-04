#include<bits/stdc++.h>
using namespace std;
using ll = long long;
using ii = pair<int,int>;

#define ff first
#define se second

const int md = 1e9+7;
const int mx = 21;

int n, a[mx][mx];
int dp[mx][1<<mx];

int fun(int i, int mask){
    if(i == n) return 1;
    int &ans = dp[i][mask];
    if(~ans) return ans; ans=0;
    for(int j=0; j<n; j++)
        if(a[i][j] && (mask&(1<<j)))
            ans += fun(i+1, mask^(1<<j)), ans %= md;
    return ans;
}

int main(){

    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n;
    for(int i=0; i<n; ++i)
    for(int j=0; j<n; ++j)
        cin >> a[i][j];
    memset(dp, -1, sizeof dp);
    cout << fun(0, (1<<n)-1) << "\n";

    return 0;
}
