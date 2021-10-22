#include<bits/stdc++.h>
using namespace std;
const int mx = 1e6 + 5;
const int mod = 1e9 + 7;

int power(int x, int p, int m=mod){
    int ans = 1; while(p > 0){
        if(p & 1)
            ans = 1LL * ans * x % m;
        x = 1LL * x * x % m; p >>= 1;
    }return ans;
}

int dp1[1024][15];
int dp2[1024][1024][15][2];
int n, a[15], f[15], nf[15];

int fun2(int mask, int cur, int p, int t, int st){
    if(p<0) return mask==cur && (!st);
    int ans = dp2[mask][cur][p][st];
    if(~ans && !t) return ans; ans = 0;

    int lim = t ? a[p] : 9;
    if(st) ans = fun2(mask, cur, p-1, 0, 1);
    for(int i=0; i<=lim; ++i){
        if(i==0 && st) continue;
        if(!((mask>>i) & 1)) continue;
        ans += fun2(mask, cur|(1<<i), p-1, t && (i==lim), 0);
        ans %= mod;
    }if(!t) dp2[mask][cur][p][st] = ans; return ans;
}

int fun(int mask, int taken){
    int &ans = dp1[mask][taken];
    if(~ans) return ans; ans = 0;
    if(taken) ans = nf[taken];

    int new_mask = 1023 ^ mask;
    for(int i=new_mask; i>0; i=(i-1)&new_mask)
        ans += 1LL * fun(mask|i, taken+1) * fun2(i, 0, n-1, 1, 1) % mod, ans %= mod;
    return ans;
}

int main(){

    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    f[0] = nf[0] = 1;
    for(int i=1; i<15; ++i){
        f[i] = 1LL * f[i-1] * i % mod;
        nf[i] = power(f[i], mod-2);
    }

    memset(dp2, -1, sizeof dp2);

    int tc, num; cin >> tc;
    for(int cs=1; cs<=tc; ++cs){
        cin >> num; n = 0;
        while(num > 0)
            a[n++] = num%10, num /= 10;
        memset(dp1, -1, sizeof dp1);
        cout << "Case " << cs << ": ";
        cout << fun(0, 0) << "\n";
    }

    return 0;
}
