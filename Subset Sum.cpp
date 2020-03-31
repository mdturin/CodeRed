#include<bits/stdc++.h>
using namespace std;

using ll = long long;
using vi = vector<int>;

#define pb push_back 
#define mem(a,v) memset(a, v, sizeof a) 

ostream& operator << (ostream &out, vector<int> &v){
    out << "[ ";
    for(auto &u:v) 
        out << u << ' ';
    out << ']';
    return out;
}

const int mod = 1e9 + 7;
const int mx  = 2000;

/**
    Subset Sum Problem
    Given a set of non-negative integers, and
    a value sum, determine if there is a subset
    of the given set with sum equal to given sum.
*/

int a[] = {1, 2, 3, 4, 5};
int n = sizeof(a) / sizeof(a[0]);

/**
    Recursive Method:
        Complexity : O(nS)
        Space : O(nS)
*/

int dp[mx][mx];
int subSetSum(int idx, int s){
    if(s <= 0) return s == 0;
    if(idx == n) return 0;
    if(dp[idx][s] != -1) return dp[idx][s];
    return dp[idx][s] = subSetSum(idx+1, s) ||
                        subSetSum(idx+1, s-a[idx]);
}

/**
    Iterative Method:
        Complexity : O(nS)
        Space : O(nS)
*/

int subSetSumIte(int s){
    mem(dp, 0);
    for(int i=0; i<=n; i++) dp[i][0] = 1;
    for(int i=1; i<=s; i++) dp[0][i] = 0;
    for(int i=1; i<=n; i++)
    for(int j=1; j<=s; j++)
        if(j<a[i-1]) dp[i][j] = dp[i-1][j];
        else dp[i][j] = dp[i-1][j] || dp[i-1][j-a[i-1]];
    return dp[n][s];
}

/// Printing all subsets with given sum
int subSetSumPrint(int s){
    for(int i=0; i<n; i++) dp[i][0] = 1;
    if(a[0] <= s) dp[0][a[0]] = 1;
    for(int i=1; i<n; i++)
    for(int j=0; j<=s; j++)
        if(a[i] <= j) dp[i][j] = dp[i-1][j] || dp[i-1][j-a[i]];
        else dp[i][j] = dp[i-1][j];
    return dp[n-1][s];
}

void PrintUtill(int i, int s, vi &p){
    if(!i && s && dp[0][s]){
        p.pb(a[i]); 
        cout << p << "\n";
        return;
    }
    if(!i && !s){cout << p << "\n"; return;}
    if(dp[i-1][s]){vi b = p; PrintUtill(i-1, s, b);}
    if(s>=a[i] && dp[i-1][s-a[i]]){
        p.pb(a[i]); 
        PrintUtill(i-1, s-a[i], p);
    }
}

void subSetPrint(int s){
    /// must call subSetSumPrint(s);
    subSetSumPrint(s); vi p;
    cout << "All subset sum for --> " << s << "\n";
    PrintUtill(n-1, s, p);
}

/// Memory Optimized Subset Sum
/// Complexity : O(nS)
/// Space : O(S)

int dpOp[2][mx], k=0;
int subSetSumOpt(int s){
    for(int i=0; i<=n; i++, k=!k)
    for(int j=0; j<=s; j++)
        if(j == 0) dpOp[k][j] = 1;
        else if(i==0) dpOp[k][j] = 0;
        else if(j < a[i-1]) dpOp[k][j] = dpOp[!k][j];
        else dpOp[k][j] = dpOp[!k][j] || dpOp[!k][j-a[i-1]];
    return dpOp[!k][s];
}

int main(){
    mem(dp, -1);
    cout << subSetSum(0, 9) << "\n";
    cout << subSetSum(0, 80) << "\n";

    cout << subSetSumIte(9) << "\n";
    cout << subSetSumIte(80) << "\n";

    cout << subSetSumOpt(9) << "\n";
    cout << subSetSumOpt(60) << "\n";
    cout << subSetSumOpt(80) << "\n";

    subSetPrint(10);
    return 0;
}

