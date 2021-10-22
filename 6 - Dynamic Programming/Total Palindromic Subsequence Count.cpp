#include<bits/stdc++.h>
using namespace std;
const int mx  = 1005;

/** Total Palindromic Subsequence :
    Finding the total # palindromic substring can be found in a string */

int dp[mx][mx];
string s; int n;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> s;
    n = s.size();
    s = "$" + s;

    for(int i=1; i<=n; ++i) dp[i][i] = 1;
    for(int i=1, j=2; j<=n; ++i, ++j)
        dp[i][j] = (s[i]==s[j]) ? 3 : 2;

    for(int len=3; len<=n; ++len)
    for(int i=1,j=len; j<=n; ++i, ++j){
        if(s[i] == s[j])
            dp[i][j] = 1 + dp[i+1][j] + dp[i][j-1];
        else dp[i][j] = dp[i+1][j] + dp[i][j-1] - dp[i+1][j-1];
    }

    cout << dp[1][n] << "\n";

    return 0;
}

