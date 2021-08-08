#include<bits/stdc++.h>
using namespace std;
const int mx = 1e6 + 5;
const int INF = 1e9 + 5;

int n, dp[mx];

inline vector<int> get_digits(int x){
    vector<int> res(10, 0);
    while(x > 0)
        res[x % 10] = 1, x /= 10;
    return move(res);
}

int main(){

    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n;
    fill(dp+1, dp+n+1, INF);
    for(int i=1; i<=n; ++i){
        vector<int> v = get_digits(i);
        for(int j=1; j<10; ++j)
            if(v[j] > 0)
                dp[i] = min(dp[i], 1 + dp[i-j]);
    }

    cout << dp[n] << "\n";

    return 0;
}
