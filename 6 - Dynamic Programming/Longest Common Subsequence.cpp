#include<bits/stdc++.h>
using namespace std;
const int mx  = 3005;

string s, t;
int dp[mx][mx];

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> s >> t;

    for(int i=1; i<=s.size(); ++i)
    for(int j=1; j<=t.size(); ++j){
        if(s[i-1] == t[j-1])
            dp[i][j] = 1 + dp[i-1][j-1];
        else dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
    }

//    cout << dp[s.size()][t.size()] << "\n";

    string res = "";
    int i = s.size(), j = t.size();
    while(i>0 && j>0){
        if(s[i-1] == t[j-1]) {
            res += s[i-1];
            --i; --j;
        }else if(dp[i-1][j] >= dp[i][j-1]) --i;
        else --j;
    }

    reverse(res.begin(), res.end());
    cout << res << "\n";

    return 0;
}

