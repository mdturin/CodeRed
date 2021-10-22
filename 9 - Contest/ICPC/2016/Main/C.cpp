#include<bits/stdc++.h>
using namespace std;
using ll = long long;
const int mx = 3e3 + 5;

ll n, q, a[mx], b[mx];
ll sq(ll x){return 1LL*x*x;}

ll get_dist(int i, int j){
    double ans = sq(a[i] - a[j]);
    ans += sq(b[i] - b[j]);
    return ceil(sqrt(ans));
}

/**
4 3
1 1
1 2
12 3
40 40
1
10
100
0 0
*/

int main(){

    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    cout << setprecision(2) << fixed;

    while(cin >> n >> q, n){
        for(int i=0; i<n; ++i)
            cin >> a[i] >> b[i];
        vector<int> cnt(40001, 0);
        for(int i=0; i<n; ++i)
        for(int j=0; j<n; ++j)
            cnt[get_dist(i, j)]++;
        for(int i=1; i<cnt.size(); ++i)
            cnt[i] += cnt[i-1];
        while(q--){
            int r; cin >> r;
            cout << cnt[r] * 1.0 / n << "\n";
        }cout << "\n";
    }

    return 0;
}

