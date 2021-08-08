#include<bits/stdc++.h>
using namespace std;
using ll = long long;
using vi = vector<int>;

const int md = 1e9+7;
const int mx = 1e5+5;

ll dp[20][2][2][11];
vi k; int n; string s;

inline void convert(){
    k.clear();
    for(char c : s)
        k.push_back(c - '0');
    n = s.size();
}

inline ll fun(int i, int t, int st, int a){
    if(i == n) return st;
    ll &ans = dp[i][t][st][a];
    if(~ans) return ans; ans=0;

    int lim = t ? k[i] : 9;
    for(int j=0; j<=lim; ++j){
        if(j == a) continue;
        int nt = (j==k[i]) ? t : 0;
        int nst = st || (j > 0);
        ans += fun(i+1, nt, nst, (!nst)?10:j);
    }return ans;
}

inline ll solve(ll x){
    if(x < 0) return 0;
    s = to_string(x); convert();
    memset(dp, -1, sizeof dp);
    return fun(0, 1, 0, 10) + 1;
}

int main(){

    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    ll x, y; cin >> x >> y;
    cout << solve(y)-solve(x-1) << "\n";

    return 0;
}
