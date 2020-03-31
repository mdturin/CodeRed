#include<bits/stdc++.h>
using namespace std;

const int INF = 1e9 + 9;
const int mod = 1e9 + 7;
const int mx  = 1001;

#define mem(a,v) memset(a,v,sizeof a) 
#define min3(a,b,c) min(a,min(b,c)) 

int n, m;
string s, t;

int dp[mx][mx];
int editDistanceRecursive(int i, int j){
    if(i == n) return (m-j);
    if(j == m) return (n-i);

    if(dp[i][j] != -1)
        return dp[i][j];

    int ans = INF;
    if(s[i] == t[j])
        ans = min(ans, editDistanceRecursive(i+1, j+1));
    else ans = min(ans, 1+min3(editDistanceRecursive(i, j+1),
                               editDistanceRecursive(i+1, j),
                               editDistanceRecursive(i+1, j+1)));
    return dp[i][j] = ans;
}

int editDistanceIterative(){
    for(int i=0; i<=n; i++){
        for(int j=0; j<=m; j++){
            if(i == 0) dp[i][j] = j;
            else if(j == 0) dp[i][j] = i;
            else if(s[i-1] == t[j-1])
                dp[i][j] = dp[i-1][j-1];
            else dp[i][j] = 1 + min3(dp[i][j-1],
                                     dp[i-1][j],
                                     dp[i-1][j-1]);
        }
    }
    return dp[n][m];
}

int main(){
    s = "uttu"; t = "ttuttu";
    n = s.size(); m = t.size();

    cout << editDistanceIterative() << "\n";

    mem(dp, -1);
    cout << editDistanceRecursive(0, 0) << "\n";

    return 0;
}

