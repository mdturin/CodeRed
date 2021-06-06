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
            result = multiply(result,val,mod);
        val = multiply(val, val, mod);
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

// // Miller Rabin
// ll prime[7]={2, 325, 9375, 28178, 450775, 9780504, 1795265022};

// // or use power with multiply if __int128
// // isn't available 
// ll bigmod(__int128 a, __int128 p, ll m) {
//     __int128 x = a % mod, r = 1;
//     while (p > 0){
//         if (p & 0x1) r=(r*x)%m;
//         x=(x*x)%m; p>>=1;
//     }return res;
// }

// bool check( ll a, ll d, ll s, ll n ) {
//     __int128 r = bigmod(a, d, n);
//     if (r==1 || r== n-1) return 0;
//     for (int i = 0; i < s - 1; i++ ) {
//         r = r * r % n;
//         if (r == 1) return 1;
//         if (r == n-1) return 0;
//     }return 1;
// }

// bool is_prime(ll n){
//     if (n<=1) return 0;
//     ll p = n - 1, s = 0;
//     while (!(p & 1)){p/=2; s++;}
//     ll d = p; p = n - 1, i;
//     for (i=0; i<7 && prime[i]<n; i++)
//         if(check(prime[i], d, s, n)) 
//             return 0;
//     return 1;
// }


int main(int argc, const char** argv) {
    return 0;
}
