#include "bits/stdc++.h"
using namespace std;

const int mx = 1e6+5;
const int INF = 1e9+9;

using ll = long long;
using pii = pair<int,int>;

#define ff first 
#define se second 
#define pb push_back 
#define sz(x) int(x.size())

vector<int> prime;
void sieve(){}

/// Complexity O( sqrt(n) )
vector<ll> allDivisors(ll x){
    ll lim = sqrt(x);
    vector< ll > ans;
    for(ll i=1; i<=lim; i++){
        if(x%i == 0){
            ans.pb(i);
            if(i != x/i)
                ans.pb(x/i);
        }
    }
    sort(begin(ans), end(ans));
    return ans;
}

/// complexity O( sqrt(n) )
/// required primes upto sqrt(n)
ll numberOfDivisors1(ll n){
    if(n == 0) return 0;
    ll ans = 1;
    for(int i=0; i<sz(prime); i++){
        if(prime[i]*prime[i] > n)
            break;
        int cnt = 1;
        while(n%prime[i] == 0)
            cnt++, n/=prime[i];
        ans *= cnt;
    }
    if(n > 1) 
        ans <<= 1;
    return ans;
}

template <typename T>
T power(T val, T p, T mod) {
    val %= mod;
    T result = 1;
    while (p > 0) {
        if (p & 0x1)
            result = (result*val)%mod;
        val = (val*val)%mod;
        p >>= 1;
    }
    return result;
}

ll multiply(ll a, ll b, ll mod){
    ll res = 0; a %= mod; b %= mod;
    while(b){
        if(b & 0x1)
            res = (res + a)%mod;
        b >>= 1;
        if(a < mod-a) a<<=1;
        else a -= (mod-a);
    }
    return res;
}

/// Miller-Rabin Prime Test
bool check_composite(ll n, ll a, ll d, ll s){
    ll x = power(a, d, n);
    if(x == 1 || x == n-1)
        return false;
    for(int r=1; r<s; r++){
        x = multiply(x, x, n);
        if(x == n-1)
            return false;
    }
    return true;
}

bool MillerRabin(ll n){
    if(n<2) return false;
    int r = 0; ll d = n-1;
    while((d&1) == 0)
        d >>= 1, r++;

    vector<int> p = {2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37};
    for(int a:p)
        if(n == a) return true;
        else if(check_composite(n, a, d, r))
            return false;
    return true;
}

/// you can compute prime for x<=1e9 by fast prime iteration
inline bool isPrime(ll x){return MillerRabin(x);}

/// complexity O(n^(1/3))
/// required primes upto n^(1/3)
/// required fermat or miller-robin theoram for isPrime function
ll numberOfDivisors2(ll x){
    ll ans = 1LL;
    for(auto p:prime){
        if(p*p*p>x) break;
        ll cnt = 1LL;
        while(x%p == 0)
            x /= p, cnt++;
        ans *= cnt;
    }
    ll y = sqrt(x);
    if(isPrime(x)) ans <<= 1;
    else if(isPrime(y) && (y*y)==x) ans *= 3;
    else if(x != 1) ans <<= 2;
    return ans;
}

int main(int argc, const char** argv) {
    return 0;
}