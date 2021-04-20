#include "bits/stdc++.h"
// #include "dbg.hpp"
using namespace std;

using ll = long long;
using vl = vector<ll>;

const ll mod = 1e9+7;
const int mx = 1e7+5;

#define pb push_back 
#define sz(x) int(x.size()) 

ll ABS(ll x){return x<0 ? -x : x;}
ll gcd(ll a, ll b){return b==0?a:gcd(b, a%b);}

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

template <typename T>
T power(T val, T p, T mod) {
    val %= mod;
    T result = 1;
    while (p > 0) {
        if (p & 0x1)
            result = multiply(result, val, mod);
        val = multiply(val, val, mod); p >>= 1;
    }
    return result;
}

int mark[mx];
vector<int> prime;
void LinearSieve(){
    register long long i, j;
    for(i=2, j=0; i<mx; i++, j=0){
        if(!mark[i]){
            mark[i] = i;
            prime.pb(i);
        }
        while(j<sz(prime) && prime[j]<=mark[i] && i*prime[j]<mx)
            mark[i * prime[j]] = prime[j], j++;
    }
}

/// Miller-Rabin Prime Test
bool check_composite(ll n, ll a, ll d, ll s){
    ll x = power<ll>(a, d, n);
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
    ll r = 0; ll d = n-1;
    while((d&1) == 0)
        d >>= 1, r++;

    /// try at most 15 primes for checking a number upto 2^63
    /// to much iteration can cause tle, make sure how many 
    /// primes you need for your program
    vector<ll> prime = {2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37};
    for(ll a:prime)
        if(n == a) return true;
        else if(check_composite(n, a, d, r))
            return false;
    return true;
}

inline bool isPrime(ll x){
    if(x < 2) return false;
    if(x < mx) return mark[x] == x; 
    return MillerRabin(x);
}

ll f(ll x, ll c, ll mod){
    return (multiply(x, x, mod) + c) % mod;}

ll pollard_rho(ll n, ll x0=3, ll c=1){
    ll x = x0, y = x0, g = 1;
    while(g == 1){
        x = f(x, c, n);
        y = f(y, c, n);
        y = f(y, c, n);
        g = gcd(ABS(x-y), n);
    }
    return g;
}

vl factorize(ll n){
    vl fact;
    while(n%2 == 0)
        fact.pb(2), n>>=1;
    queue<ll> q; q.push(n);
    while(q.size()){
        ll x = q.front(); q.pop();
        if(x == 1) continue;
        ll d = pollard_rho(x);
        if(isPrime(d)) {
            fact.pb(d);
            q.push(x/d);
        }
        else q.push(d), q.push(x/d);
    }
    sort(fact.begin(), fact.end());
    return fact;
}

int main(int argc, const char** argv) {
    LinearSieve();
    auto v = factorize(3245364745678567LL);
    for(auto &u:v) cout << u << " ";
    cout << endl << endl;
    return 0;
}