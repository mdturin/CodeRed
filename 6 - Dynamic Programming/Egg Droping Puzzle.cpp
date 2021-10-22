#include<bits/stdc++.h>
using namespace std;
const int mx  = 1005;

int dp[mx][mx];
int fun(int n, int e){
    if(n <= 1 || e == 1) return n;

    int &ans = dp[n][e];
    if(~ans) return ans;
    ans = INT_MAX;

    for(int x=1; x<=n; x++)
        ans = min(ans, 1+max(fun(n-x, e), fun(x-1, e-1)));
    return ans;
}

int sumOf_xCi(int x, int n){
    int sum = 0, prod = 1;
    for(int i=1; i<=n; i++){
        prod *= (x-i+1);
        prod /= i;
        sum += prod;
    }return sum;
}

int EggDropGreedy(int n, int e){
    int lw = 1, hh = n;
    while(lw < hh){
        int mid = (lw + hh) / 2;
        if(sumOf_xCi(mid, e) < n)
            lw = mid + 1;
        else hh = mid;
    }return lw;
}

int main(){

    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, e;
    cin >> n >> e;

    // Method DP:
    memset(dp, -1, sizeof dp);
    cout << fun(n, e) << "\n";

    // Method Greedy:
    cout << EggDropGreedy(n, e) << "\n";

    return 0;
}

