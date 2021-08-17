#include<bits/stdc++.h>
using namespace std;
const int mx = 1e5 + 5;
const int mod = 1e9 + 7;

#define pb push_back
#define sz(x) int(x.size())

int mark[mx];
vector<int> prime;
int one[mx], two[mx], thr[mx];

int is_prime(int x){return mark[x] == x;}

void LinearSieve(){
    mark[0] = mark[1] = -1;
    for(int i=2, j=0; i<mx; i++, j=0){
        if(!mark[i]){mark[i] = i; prime.pb(i);}
        while(j<(prime.size()) && prime[j]<=mark[i] && 1LL*i*prime[j]<mx)
            mark[i * prime[j]] = prime[j], j++;
    }

    one[2] = 1;
    for(int i=3; i<mx; ++i){
        one[i] = one[i-1];
        two[i] = two[i-1];
        thr[i] = thr[i-1];
        if(mark[i] != i) continue;

        one[i] += 1;
        two[i] += 2*is_prime(i-2);
        if(i <= 5) continue;
        thr[i] += is_prime(i-4) && is_prime(i-2);
    }
}

long long ncr(int n, int m){
    if(m <= 0) return 0;
    if(m == 1) return n;
    if(m == 2) return 1LL * n * (n-1) / 2;
    return 1LL * n * (n-1) * (n-2) / 6;
}

int main(){

    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    LinearSieve();

    int tc, n, m; cin >> tc;
    for(int cs=1; cs<=tc; ++cs){
        cin >> n >> m;
        long long ans = n;
        for(int i=1; i<=n; ++i){
            ans += 1LL * ncr(m-1, 1) * one[n-i]; ans %= mod;
            ans += 1LL * ncr(m-1, 2) * two[n-i]; ans %= mod;
            ans += 1LL * ncr(m-1, 3) * thr[n-i]; ans %= mod;
        }cout << "Case " << cs << ": " << ans << "\n";
    }

    return 0;
}
