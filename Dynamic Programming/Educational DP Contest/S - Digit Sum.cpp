#include<bits/stdc++.h>
using namespace std;
using ll = long long;
using vi = vector<int>;
using ii = pair<int,int>;

#define ff first
#define se second

const int md = 1e9+7;
const int mx = 1e5+5;

string s;
vi k; int d, n;

inline void convert(){
    k.clear();
    for(char c : s)
        k.push_back(c - '0');
    n = s.size();
}

int dp[mx][2][2][101];
inline int fun(int i, int t, int st, int a){
    if(i == n) return st && a == 0;
    int &ans = dp[i][t][st][a];
    if(~ans) return ans; ans=0;

    int lim = t ? k[i] : 9;
    for(int j=0; j<=lim; ++j){
        int nt = (j==k[i]) ? t : 0;
        int nst = st || (j > 0);
        ans += fun(i+1, nt, nst, (a+j)%d);
        ans %= md;
    }return ans;
}

int main(){

    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> s >> d; convert();
    memset(dp, -1, sizeof dp);
    cout << fun(0, 1, 0, 0) << "\n";

    return 0;
}

