#include "bits/stdc++.h"
using namespace std;

using ll = long long;
#define pb push_back 
const int mx = 1e6+5;

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
            result = (result*val)%mod;
        val = (val*val)%mod;
        p >>= 1;
    }
    return result;
}

// /// naive prime test
// bool isPrime(ll x){
//     for(ll i=2; i*i<=x; i++)
//         if(x%i == 0)
//             return false;
//     return true;
// }

/// fast iterate prime testing
bool isPrime(ll x){
    if(x < 2) return false;
    if(x < 4) return true;
    if(x%2==0 || x%3==0)
        return false;
    ll lim = sqrt(x);
    for(ll i=5; i<=lim; i+=6)
        if(x%i==0 || x%(i+2)==0)
            return false;
    return true;
}

// Fermat Probable Prime
bool probablyPrimeFermat(ll x, int iter=7){
    if(x < 4) return (x>1);

    srand(time(NULL));
    for(int i=0; i<iter; i++){
        ll a = 2 + rand() % (x-3);
        if(power(a, x-1, x) != 1)
            return false;
    }
    return true;
}

// Fermat theorem
// required sieve
// mark[x] = 1 if not prime
// prime[x] = xth prime
// __gcd(a,b) = built-in gcd in c++
// power(a, p, m) = (a^p)%m in log(p)

int mark[mx];
vector<int> prime;

void sieve(){
    mark[0] = mark[1] = 1;
    prime.pb(2);
    for(int i=4; i<mx; i+=2)
        mark[i] = 1;
    register ll i, j, k;
    for(i=3; i<mx; i+=2)
    if(!mark[i]){
        prime.pb(i);
        for(j=i*i,k=i+i; j<mx; j+=k)
            mark[j] = 1;
    }
}

bool isFermatPrime(ll n){
    if(n<mx) return !mark[n];
    if(n%2 == 0) return false;

    /// 12 iteration for upto 2^31
    /// 20 for 2^63
    for(int it=0;it<12;++it){
        ll i = prime[it];
        if(__gcd(i,n)!=1) return false;
        if(power(i,n-1,n)!=1) return false;
    }
    return true;
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

    /// try at least 15 primes for checking a number upto 2^63
    /// to much iteration can cause tle, make sure how many 
    /// primes you need for your program
    for(int a:{2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37})
        if(n == a) return true;
        else if(check_composite(n, a, d, r))
            return false;
    return true;
}

int main(int argc, const char** argv) {
    return 0;
}