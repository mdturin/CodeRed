#include<bits/stdc++.h>
using namespace std;
const int mx  = 5001;

int min3(int a, int b, int c){
    return min(a, min(b, c));
}

int n, m;
string s, t;
int dp[mx][mx];

int main(){

    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> s >> t;
    n = s.size(); m = t.size();
    s = "$" + s; t = "$" + t;

    for(int i=0; i<=n; ++i)
    for(int j=0; j<=m; ++j){
        if(i == 0) dp[i][j] = j;
        else if(j == 0) dp[i][j] = i;
        else if(s[i] == t[j]) dp[i][j] = dp[i-1][j-1];
        else dp[i][j] = 1 + min3(dp[i][j-1], dp[i-1][j], dp[i-1][j-1]);
    }

    cout << dp[n][m] << "\n";

    return 0;
}
