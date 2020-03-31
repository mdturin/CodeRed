#include<bits/stdc++.h>
using namespace std;

#define mem(a,v) memset(a,v,sizeof a) 

const int INF = 1e9+9;
const int mod = 1e9+7;
const int mx  = 1005;

///1. Complexity : O(n * e)
int dp[mx][mx];
int EggDropRec(int n, int e){
    if(n <= 1) return n;
    if(e == 1) return n;

    if(dp[n][e] != -1)
        return dp[n][e];

    int ans = INF;
    for(int x=1; x<=n; x++)
        ans = min(ans, 1+max(EggDropRec(n-x, e),
                             EggDropRec(x-1, e-1)));
    return dp[n][e] = ans;
}

///2. Complexity : O(n * e)
int EggDropIte(int n, int e){
    for(int i=0; i<=e; i++)
        dp[0][e] = 0, dp[1][e] = 1;
    for(int i=0; i<=n; i++)
        dp[i][1] = i;
    for(int i=2; i<=n; i++)
    for(int j=2; j<=e; j++){
        dp[i][j] = INF;
        for(int x=1; x<=i; x++)
            dp[i][j] = min(dp[i][j], 1+max(dp[i-x][j], dp[x-1][j-1]));
    }
    return dp[n][e];
}

///3. Complexity : O(e * log n)
int sumOf_xCi(int x, int n){
    int sum = 0, prod = 1;
    for(int i=1; i<=n; i++){
        prod *= (x-i+1);
        prod /= i;
        sum += prod;
    }
    return sum;
}

int EggDropBinary(int n, int e){
    int lw = 1, hh = n;
    while(lw < hh){
        int mid = (lw + hh) / 2;
        if(sumOf_xCi(mid, e) < n)
            lw = mid + 1;
        else hh = mid;
    }
    return lw;
}

int main(){
    mem(dp, -1);
    cout << EggDropRec(10, 2) << "\n";
    cout << EggDropIte(10, 2) << "\n";
    cout << EggDropBinary(10, 2) << "\n";
    return 0;
}

