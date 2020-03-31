#include<bits/stdc++.h>
using namespace std;

const int mod = 1e9 + 7;
const int mx  = 205;

#define max3(a,b,c) max(a,max(b,c)) 

int n = 5, W = 236;
int wt[] = {10, 20, 30, 40, 50};
int val[] = {25, 59, 48, 36, 78};

/// 1. Complexity : O(nW)
///    Space : O(nW)
int dp[mx][mx];
int ksr(int idx, int w){
    if(idx == n) return 0;
    if(w == 0) return 0;

    if(dp[idx][w] != -1)
        return dp[idx][w];

    int ans = 0;
    if(w<wt[idx]) ans = ksr(idx+1, w);
    else ans = max3(ans, 
                    val[idx]+ksr(idx+1, w-wt[idx]),
                    ksr(idx+1, w));
    return dp[idx][w] = ans;
}

/// 2. Complexity : O(nW)
///    Space : O(nW)
int knapsackIte(int n, int w){
    for(int i=0; i<=n; i++)
    for(int j=0; j<=w; j++)
        if(i==0 || j==0) dp[i][j] = 0;
        else if(wt[i-1] > j)
            dp[i][j] = dp[i-1][j];
        else dp[i][j] = max(val[i-1] + dp[i-1][j-wt[i-1]],
                                       dp[i-1][j]);
    return dp[n][w];
}

/// 3. Complexity : O(nW)
///    Space : O(2W)

int dpOpt[2][mx], k=0;
int knapsackIteOptimized(int n, int w){
    for(int i=0; i<=n; i++, k=!k)
    for(int j=0; j<=w; j++)
        if(i==0 || j==0) dp[k][j] = 0;
        else if(wt[i-1] > j)
            dpOpt[k][j] = dpOpt[!k][j];
        else dpOpt[k][j] = max(val[i-1] + dpOpt[!k][j-wt[i-1]],
                                       dpOpt[!k][j]);
    return dpOpt[!k][w];
}

/// 4. Complexity : O(nW)
///    Space : O(W)

int dpOpt2[mx];
int knapsackIteOptimized2(int n, int w){
    memset(dpOpt2, 0, sizeof dpOpt2);
    for(int i=0; i<n; i++)
    for(int j=w; j>=wt[i]; j--)
        dpOpt2[j] = max(dpOpt2[j], val[i]+dpOpt2[j - wt[i]]);
    return dpOpt2[w];
}

/// required knapsackIte()
void printKS(){
    int res = knapsackIte(n, W), w = W;
    for(int i=n; i>0 && res>0; i--)
        if(res == dp[i-1][w]) continue;
        else{
            /// do something, cout << wt[i-1] << " ";
            res -= val[i-1]; w -= wt[i-1];
        }
    cout << "\n";
}

int dbDp[mx][mx][mx];
int doubleKS(int idx, int w1, int w2){
    if(idx == n) return 0;
    if(dbDp[idx][w1][w2] != -1)
        return dbDp[idx][w1][w2];

    int ans=0, ans1=0, ans2=0;
    if(w1 >= wt[idx])
        ans1 = val[idx] + doubleKS(idx+1, w1-wt[idx], w2);
    if(w2 >= wt[idx])
        ans2 = val[idx] + doubleKS(idx+1, w1, w2-wt[idx]);
    ans = doubleKS(idx+1, w1, w2);
    ans = max3(ans, ans1, ans2);
    return dbDp[idx][w1][w2] = ans;
}

/// if multiple instances allowed
int unboundedKSR(int idx, int w){
    if(idx == n) return 0;

    if(dp[idx][w] != -1)
        return dp[idx][w];

    int ans = 0;
    if(w >= wt[idx])
        ans = max(ans, val[idx]+unboundedKSR(idx, w-wt[idx]));
    ans = max(ans, unboundedKSR(idx+1, w));
    return dp[idx][w] = ans;
}

int unboundDp[mx];
int unboundedKSI(int n, int w){
    for(int i=0; i<=w; i++)
    for(int j=0; j<n; j++)
        if(wt[j] <= i)
            unboundDp[i] = max(unboundDp[i], unboundDp[i - wt[j]]+val[j]);
    return unboundDp[w];
}

int main(){
    memset(dp, -1, sizeof dp);
    cout << unboundedKSI(n, W) << "\n";
    return 0;
}

