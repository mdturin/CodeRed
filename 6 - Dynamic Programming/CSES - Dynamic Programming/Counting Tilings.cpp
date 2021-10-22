#include<bits/stdc++.h>
using namespace std;
using ll = long long;

const int mx = 1e6+5;
const int md = 1e9+7;

int n, m;
int dp[1<<10][1000];

inline void gen(int &cur, int r, int nxt, vector<int> &msk){
    if(r == n){msk.push_back(nxt); return;}
    if((cur>>r) & 1) gen(cur, r+1, nxt, msk);
    if(r+1<n && !((cur>>r)&1) && !((cur>>(r+1))&1))
        gen(cur, r+2, nxt, msk);
    if(!((cur>>r)&1)) gen(cur, r+1, nxt|(1<<r), msk);
}

int fun(int mask, int c){
    if(c == m) return mask==0;

    int &ans = dp[mask][c];
    if(~ans) return ans; ans=0;

    vector<int> new_masks;
    gen(mask, 0, 0, new_masks);
    for(int msk : new_masks)
        ans = (ans + fun(msk, c+1)) % md;

    return ans;
}

int main(){

    ios_base::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);

    cin >> n >> m;
    memset(dp, -1, sizeof dp);
    cout << fun(0, 0) << "\n";

    return 0;
}

