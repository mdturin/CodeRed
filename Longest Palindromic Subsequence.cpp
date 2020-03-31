#include<bits/stdc++.h>
using namespace std;

#define all(a) a.begin(),a.end() 
#define mem(a,v) memset(a,v,sizeof a) 
const int mod = 1e9 + 7;
const int mx  = 2000;

/**
    Longest Palindromic Sub-sequence
    Finding a longest sub sequence string
    that is palindromic.
*/

string a, b, s = "GEEKSFORGEEKS";
int n = s.size();

/**
    Recursive Method:
        Complexity : O(n * n)
        Space : O(n * n)
*/

int dp[mx][mx];
int lpsRec(int i, int j){
    if(i == j) return 1;
    if(i+1 == j)
        return (s[i]==s[j]) ? 2 : 1;

    if(dp[i][j] != -1)
        return dp[i][j];

    int ans = 0;
    if(s[i] == s[j]) ans = 2+lpsRec(i+1, j-1);
    else ans = max(lpsRec(i+1, j), lpsRec(i, j-1));
    return dp[i][j] = ans;
}

/**
    Iterative Method:
        Complexity : O(n * n)
        Space : O(n * n)
*/

int lpsIte(){
    for(int i=0; i<n; i++)
        dp[i][i] = 1;
    for(int k=2; k<=n; k++)
    for(int i=0; i<n-k+1; i++){
        int j = i + k - 1;
        if(s[i] == s[j] && k==2)
            dp[i][j] = 2;
        else if(s[i] == s[j])
            dp[i][j] = 2+dp[i+1][j-1];
        else dp[i][j] = max(dp[i+1][j], dp[i][j-1]);
    }
    return dp[0][n-1];
}

/// For Printing, we can use two string of s
/// a = from starting, b = in reverse
/// and finding a common sub sequence method
/// for finding length and values

int lcsIte(){
    for(int i=0; i<=n; i++)
    for(int j=0; j<=n; j++)
        if(min(i,j)==0) dp[i][j] = 0;
        else if(a[i-1] == b[j-1])
            dp[i][j] = 1+dp[i-1][j-1];
        else dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
    return dp[n][n];
}

string lpsPrint(){
    string ans = "";
    a = s; b = s; reverse(all(b)); lcsIte();
    int i = n, j = n;
    while(min(i,j)>0){
        if(a[i-1] == b[j-1]){
            ans += a[i-1];
            i--; j--;
        }
        else if(dp[i-1][j] > dp[i][j-1]) i--;
        else j--;
    }
    reverse(all(ans));
    return ans;
}

/// Memory Optimized Method
int dpOp[mx];
int lpsOp(){
    for(int i=n-1; i>=0; i--){
        dpOp[i] = 1;
        int tmp = 0, tmp2;
        for(int j=i+1; j<n; j++)
            if(s[i] == s[j]){
                tmp2 = dpOp[j];
                dpOp[j] = tmp + 2;
                tmp = tmp2;
            }
            else{
                tmp = dpOp[j];
                dpOp[j] = max(dpOp[j-1], dpOp[j]);
            }
    }
    return dpOp[n-1];
}

int main(){
    mem(dp, -1);
    cout << lpsRec(0, n-1) << "\n";
    cout << lpsIte() << "\n";
    cout << lpsPrint() << "\n";
    cout << lpsOp() << "\n";
    return 0;
}

