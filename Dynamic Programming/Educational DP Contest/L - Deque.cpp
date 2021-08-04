#include<bits/stdc++.h>
using namespace std;
using ll = long long;
using ii = pair<int,int>;

#define ff first
#define se second

const int md = 1e9+7;
const int mx = 3e3+5;

int n, a[mx];
ll dp[mx][mx][2];

ll fun(int i, int j, int t){
    if(i == j) return t?-a[i]:a[i];

    ll &ans = dp[i][j][t];
    if(~ans) return ans;

    ans = (t?-a[i]:a[i]) + fun(i+1, j, !t);
    if(t == 0)
        ans = max(ans, (t?-a[j]:a[j]) + fun(i, j-1, !t));
    else ans = min(ans, (t?-a[j]:a[j]) + fun(i, j-1, !t));
    return ans;
}

int main(){

    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n;
    for(int i=1; i<=n; ++i)
        cin >> a[i];
    memset(dp, -1, sizeof dp);
    cout << fun(1, n, 0) << "\n";

    return 0;
}

