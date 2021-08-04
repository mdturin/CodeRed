#include<bits/stdc++.h>
using namespace std;
using ll = long long;
using ii = pair<int,int>;

#define ff first
#define se second

const int md = 1e9+7;
const int mx = 3e3+5;
const double ONE = double(1);

int n;
double dp[mx][mx];
double h[mx], t[mx];

int main(){

    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n; dp[0][0] = 1;
    for(int i=1; i<=n; ++i){
        cin >> h[i]; t[i] = ONE - h[i];
        dp[i][0] = ONE * dp[i-1][0] * h[i];
        for(int j=1; j<=n/2; ++j){
            dp[i][j] += ONE * dp[i-1][j] * h[i];
            dp[i][j] += ONE * dp[i-1][j-1] * t[i];
        }
    }

    cout << setprecision(10) << fixed;
    cout << accumulate(dp[n], dp[n]+(n/2)+1, 0.0) << "\n";

    return 0;
}

