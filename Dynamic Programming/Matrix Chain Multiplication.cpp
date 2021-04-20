#include<bits/stdc++.h>
using namespace std;

#define mem(a,v) memset(a,v,sizeof a) 
const int mod = 1e9 + 7;
const int mx  = 2005;

using ll = long long;

/**
    Matrix Chain Multiplication
    Given a sequence of matrices, find the most efficient
    way to multiply these matrices together. The problem is
    not actually to perform the multiplications, but merely
    to decide in which order to perform the multiplications.
*/

int n = 5;
int p[mx] = {40, 20, 30, 10, 30};
ll dp[mx][mx];

/**
    Recursive Method :
        Complexity : O(n * n)
        Space : O(n * n)
*/

ll MatrixChain(int i, int j){
    if(i == j) return 0;
    if(dp[i][j] != -1)
        return dp[i][j];
    ll ans = LLONG_MAX, tmp;
    for(int k=i; k<j; k++){
        tmp = (ll)p[i-1]*p[k]*p[j] + MatrixChain(i, k) + MatrixChain(k+1, j);
        if(tmp < ans){
            ans = tmp;
            dp[j][i] = k;
        }
    }

    return dp[i][j] = ans;
}

/// For Printing the multiplication way of the matrix

char ch = 'A';
void printUtil(int i, int j){
    if(i == j){cout << ch++; return;}

    cout << "(";
    printUtil(i, dp[j][i]);
    printUtil(dp[j][i]+1, j);
    cout << ")";
}
void printMatrixChain(){
    /// must call MatrixChain
    printUtil(1, n-1);
    cout << "\n";
    return;
}

/**
    Iterative Method :
        Complexity : O(n * n)
        Space : O(n * n)
*/

ll MatrixChain(){
    for(int i=1; i<n; i++) dp[i][i] = 0;
    for(int l=2; l<n; l++)
    for(int i=1; i<n-l+1; i++){
        int j = i + l - 1; dp[i][j] = LLONG_MAX;
        for(int k=i; k<j; k++)
            dp[i][j] = min(dp[i][j], (ll)p[i-1]*p[k]*p[j] +
                                      dp[i][k] + dp[k+1][j]);
    }
    return dp[1][n-1];
}

/// Memory Optimized Method
ll MatrixChainOpt(){
    for(int i=1; i<n; i++) dp[i][i] = 0;
    for(int l=1; l<n-1; l++)
    for(int i=1; i<n-l; i++)
        dp[i][i+l] = min(p[i-1]*p[i]*p[i+l] + dp[i+1][i+l],
                         p[i-1]*p[i+l-1]*p[i+l] + dp[i][i+l-1]);
    return dp[1][n-1];
}

int main(){mem(dp, -1);
    cout << MatrixChain(1, n-1) << "\n";
    cout << MatrixChain() << "\n";
    cout << MatrixChainOpt() << "\n";
    printMatrixChain();
    return 0;
}

