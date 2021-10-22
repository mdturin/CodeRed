#include<bits/stdc++.h>
using namespace std;
const int mx = 1e5 + 5;

int n, w, dp[mx];
int price[1001], pages[1001];

int main(){

    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n >> w;
    for(int i=1; i<=n; ++i) cin >> price[i];
    for(int i=1; i<=n; ++i) cin >> pages[i];

    for(int i=1; i<=n; ++i)
    for(int p=w; p>=price[i]; --p)
        dp[p] = max(dp[p], pages[i]+dp[p-price[i]]);

    cout << dp[w] << "\n";

    return 0;
}
