#include<bits/stdc++.h>
using namespace std;
using ll = long long;
using ii = pair<int,int>;

#define ff first
#define se second

const int md = 1e9+7;
const int mx = 3e3+5;

string s;
int n, dp[mx][mx];

int main(){

    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n >> s;
    dp[1][1] = 1;
    for(int len=2; len<=n; ++len){
        for(int i=1; i<=len; ++i){
            dp[len-1][i] += dp[len-1][i-1];
            dp[len-1][i] %= md;
        }
        for(int i=1, l, r; i<=len; ++i){
            if(s[len-2] == '<')
                l = 1, r = i-1;
            else l = i, r = len-1;
            if(l <= r){
                int val = (dp[len-1][r] - dp[len-1][l-1] + md) % md;
                dp[len][i] += val;
                dp[len][i] %= md;
            }
        }
    }

    int ans = 0;
    for(int i=1; i<=n; ++i)
        ans += dp[n][i], ans %= md;
    cout << ans << "\n";

    return 0;
}

