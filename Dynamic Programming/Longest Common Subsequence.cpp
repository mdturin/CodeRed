#include<bits/stdc++.h>
using namespace std;

#define all(a) a.begin(),a.end() 
#define mem(a,v) memset(a,v,sizeof a) 
const int mod = 1e9 + 7;
const int mx  = 1005;

/// Longest Common Subsequence

string a = "helloworld";
string b = "missworld";
int n = a.size(), m = b.size();

/// Recursive Method
/// Complexity : O(nm)
/// Space : O(mn)

int dp[mx][mx];
int lcsRec(int i, int j){
    if(i==n || j==m) return 0;

    if(dp[i][j] != -1)
        return dp[i][j];

    int ans = 0;
    if(a[i] == b[j])
        ans = 1+lcsRec(i+1, j+1);
    else ans = max(lcsRec(i+1, j), lcsRec(i, j+1));
    return dp[i][j] = ans;
}

/// Recursive Method
/// Complexity : O(nm)
/// Space : O(mn)

int lcsIte(){
    for(int i=0; i<=n; i++)
    for(int j=0; j<=m; j++)
        if(min(i,j)==0) dp[i][j] = 0;
        else if(a[i-1] == b[j-1])
            dp[i][j] = 1+dp[i-1][j-1];
        else dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
    return dp[n][m];
}

/// LCS Print Function
/// Required lcsIte function
/// Complexity : Linear

string ans = "";
void lcsPrint(){
    int i = n, j = m;
    while(min(i,j)>0){
        if(a[i-1] == b[j-1]){
            ans += a[i-1];
            i--; j--;
        }
        else if(dp[i-1][j] > dp[i][j-1]) i--;
        else j--;
    }
    reverse(all(ans));
    cout << ans << "\n";
}

/// Memory Optimized LCS
/// Space : O(m)

int lcs[2][mx], k=0;
int lcsIteOp(){
    for(int i=0; i<=n; i++, k=!k)
    for(int j=0; j<=m; j++)
        if(min(i,j)==0) dp[k][j] = 0;
        else if(a[i-1] == b[j-1])
            dp[k][j] = 1+dp[!k][j-1];
        else dp[k][j] = max(dp[!k][j], dp[k][j-1]);
    return dp[!k][m];
}

int main(){
    mem(dp, -1);
    cout << lcsRec(0, 0) << "\n";
    cout << lcsIte() << "\n"; lcsPrint();
    cout << lcsIteOp() << "\n";

    return 0;
}

