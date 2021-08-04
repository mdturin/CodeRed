#include<bits/stdc++.h>
using namespace std;
using ll = long long;
using ii = pair<int,int>;

#define ff first
#define se second

const int md = 1e9+7;
const int mx = 1e3+5;

int n, m;
int dp[mx][mx];
string grid[mx];

int main(){

    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n >> m;
    grid[0] = string(m+1, '.');
    for(int i=1; i<=n; ++i){
        cin >> grid[i];
        grid[i] = "." + grid[i];
    }

    dp[1][1] = 1;
    for(int i=1; i<=n; ++i)
    for(int j=1; j<=m; ++j){
        if(grid[i][j] == '#') continue;
        if(grid[i-1][j] == '.') dp[i][j] += dp[i-1][j];
        if(grid[i][j-1] == '.') dp[i][j] += dp[i][j-1];
        dp[i][j] %= md;
    }cout << dp[n][m] << "\n";

    return 0;
}
