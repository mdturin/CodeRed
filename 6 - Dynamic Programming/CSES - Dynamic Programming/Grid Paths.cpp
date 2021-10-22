#include<bits/stdc++.h>
using namespace std;
using ll = long long;
using ii = pair<int,int>;

#define ff first
#define se second

const int md = 1e9+7;
const int mx = 1e3+5;

int n;
string s[mx];
int dp[mx][mx];

int main(){

    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n;
    for(int i=1; i<=n; ++i)
        cin >> s[i], s[i] = "$" + s[i];

    dp[1][0] = 1;
    for(int i=1; i<=n; ++i)
    for(int j=1; j<=n; ++j)
        if(s[i][j] == '.')
            dp[i][j] = (dp[i-1][j] + dp[i][j-1]) % md;

    cout << dp[n][n] << "\n";

    return 0;
}
