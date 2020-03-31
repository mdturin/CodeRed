#include<bits/stdc++.h>
using namespace std;

#define mem(a,v) memset(a, v, sizeof a) 
const int mod = 1e9 + 7;
const int mx  = 1005;

/**
    Total palindromic subsequence
    Finding the total number of palindromic substring can
    be found in a string
*/

string s = "abcba";
int n = s.size();

/**
    Recursive Method:
        Complexity : O(n*n)
        Space : O(n*n)
*/

int dp[mx][mx];
int countPS(int i, int j){
    if(i>j) return 0;
    if(dp[i][j] != -1)
        return dp[i][j];

    if(i==j) return 1;
    if(i+1==j)
        return s[i]==s[j]?3:2;

    int ans = 0;
    if(s[i]==s[j])
        ans = countPS(i+1, j)+countPS(i, j-1)+1;
    else ans = countPS(i+1, j)+countPS(i, j-1)-countPS(i+1,j-1);
    return dp[i][j] = ans;
}

/**
    Iterative Method:
        Complexity : O(n*n)
        Space : O(n*n)
*/

int countPSIte(){
    for(int i=0; i<n; i++) dp[i][i] = 1;
    for(int i=2; i<=n; i++)
    for(int j=0; j<n; j++){
        int k = i + j - 1;
        if(s[j] == s[k]) dp[j][k] = dp[j][k-1]+dp[j+1][k]+1;
        else dp[j][k] = dp[j][k-1]+dp[j+1][k]-dp[j+1][k-1];
    }
    return dp[0][n-1];
}

int main(){
    mem(dp, -1); cout << countPS(0,n-1) << "\n";
    mem(dp,  0); cout << countPSIte() << "\n";
    return 0;
}

