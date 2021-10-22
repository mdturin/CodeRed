#include<bits/stdc++.h>
using namespace std;
using ll = long long;
using ii = pair<int,int>;

#define ff first
#define se second
int n, m, w, a[22];

int main(){

    ios_base::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);

    cin >> n >> w; m = (1<<n);
    vector<ii> dp(m, ii(n, 0));
    for(int i=0; i<n; i++) cin >> a[i];

    dp[0] = ii(1, 0);
    for(int i=1; i<m; i++)
    for(int j=0; j<n; j++){
        if(i>>j & 1){
            ii p = dp[i ^ (1<<j)];
            if(p.se + a[j] > w)
                p = ii(p.ff+1, a[j]);
            else p.se += a[j];
            dp[i] = min(dp[i], p);
        }
    }

    cout << dp.back().ff << "\n";

    return 0;
}

