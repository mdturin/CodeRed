/**
    Longest Palindromic Subsequence
    Finding a longest subsequence string that is palindromic.
    For better efficient way use
        i.  manacher's algorithm,
        ii. palindromic tree.
*/

#include<bits/stdc++.h>
using namespace std;
const int mx = 2005;

string s;
int n, dp[mx][mx];

int main(){

    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> s;
    n = s.size();
    s = "$" + s;

    int ans = 1;
    for(int i=1; i<=n; ++i) dp[i][i] = 1;
    for(int i=1, j=2; j<=n; ++i, ++j){
        dp[i][j] = (s[i] == s[j]);
        if(dp[i][j]) ans = 2;
    }

    for(int len=3; len<=n; ++len)
    for(int i=1, j=len; j<=n; ++i, ++j){
        dp[i][j] = (s[i]==s[j] && dp[i+1][j-1]);
        if(dp[i][j]) ans = len;
    }

    cout << ans << "\n";
    for(int i=1, j=ans; j<=n; ++i, ++j)
        if(dp[i][j])
            cout << s.substr(i, ans) << "\n";

    return 0;
}

