#include<bits/stdc++.h>
using namespace std;
using ll = long long;
using ii = pair<int,int>;

#define ff first
#define se second

const int md = 1e9+7;
const int mx = 1e6+5;

ll dp[1 << 16];
int n, a[16][16];

int main(){

    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n;
    for(int i=0; i<n; ++i)
    for(int j=0; j<n; ++j)
        cin >> a[i][j];

    int len = (1<<n);
    for(int i=1; i<len; ++i){
        ll sum = 0;
        vector<int> v;
        for(int j=0; j<n; ++j)
        if((i>>j) & 1){
            for(int u : v)
                sum += a[j][u];
            v.push_back(j);
        }dp[i] = sum;
    }

    for(int i=1; i<len; ++i)
        for(int j=i; j; j=(j-1)&i)
            dp[i] = max(dp[i], dp[j] + dp[i^j]);
    cout << dp[len-1] << "\n";

    return 0;
}

