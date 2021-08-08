#include<bits/stdc++.h>
using namespace std;
using ll = long long;
using ii = pair<int,int>;
using tpl = tuple<int,int,int>;

#define ff first
#define se second

const int md = 1e9+7;
const int mx = 2e4+1;

struct node{
    int w, s, v;
    bool operator < (const node &ot){
        if(w + s != ot.w + ot.s)
            return w + s < ot.w + ot.s;
        if(w != ot.w) return w < ot.w;
        if(s != ot.s) return s < ot.s;
        return v < ot.v;
    }
}a[mx];

ll dp[mx];

int main(){

    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n; cin >> n;
    for(int i=0; i<n; ++i)
        cin >> a[i].w >> a[i].s >> a[i].v;
    sort(a, a + n);

    for(int i=0; i<n; ++i)
    for(int j=min(a[i].s, mx-a[i].w); j>=0; --j)
        dp[a[i].w+j] = max(dp[a[i].w+j], dp[j]+a[i].v);
    cout << *max_element(dp, dp+mx) << "\n";

    return 0;
}

