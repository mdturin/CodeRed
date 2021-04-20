#include "bits/stdc++.h"
using namespace std;

using ll = long long;
const int mx = 1e5+5;
const int mod = 1e9+7;

/**
    Analytic formula    : (nCk) = (n!) / (k! * (n-k)!);
    Recurrence formula  : (nCk) = ((n-1) C k) + ((n-1) C (k-1));
    
    Properties:
        Symmetry rule : (nCk) = (n C (k-1));
        Factoring : (nCk) = (n/k) * (n-1) C (k-1);
        Sum over k : summation of (nCk) where k = 0 to n = power(2, n)
        Sum over n : summation of (mCk) where m = 0 to n = (n+1) C (k+1)
        Sum over n and k:
            (n+k) C (k) where k = 0 to m = (n+m+1) C (m)
        Weighted Sum :
            1(nC1) + 2(nC2) + ... + n(nCn) = n * power(2, n-1);
        Relation with Fibonacci:
            (nC0) + (n-1)C1 + ... + (n-k)Ck + .. + 0Cn = (n+1)th fibonacchi number           
*/

/**
    (a+b)^n = (nC0) * a^n + (nC1) * a^(n-1) * b + ... + (nCk) * a^(n-k) * b^k + ... + (nCn) b^n
*/

// Straightforward
ll ncr(ll n, ll k){
    ll res = 1LL;
    for(int i=n-k+1; i<=n; i++) res *= i;
    for(int i=2; i<=k; i++) res /= i;
    return res;
}

/**
    we can store precalculate ncr values
    by applying the formula :
        C(n, k) = C(n-1, k) + C(n-1, k-1) where k<=n
        C(n, 0) = C(n, n) = 1 
    Complexity : O(n * k)
    Space : O(n * k)
*/

ll c[mx][mx];
void ncr(){
    for(int i=0; i<mx; i++){
        c[i][0] = c[i][i] = 1;
        for(int j=1; j<i; j++)
            c[i][j] = c[i-1][j] + c[i-1][j-1];
    }
}

void ncrMod(){
    for(int i=0; i<mx; i++){
        c[i][0] = c[i][i] = (1)%mod;
        for(int j=1; j<i; j++)
            c[i][j] = (c[i-1][j] + c[i-1][j-1])%mod;
    }
}

/**
    if we want to work with last row only
    we can optimize our space by storing only
    the last row and applying the formula.
        Complexity : O(n * k)
        Space : O(n)
*/

ll dp[mx];
void ncrDp(int n){
    memset(dp, 0, sizeof dp); dp[0] = 1;
    for(int i=1; i<=n; i++)
        for(int j=min(i, n); j>0; j--)
            dp[j] = dp[j] + dp[j-1];
}

void ncrDpMod(int n){
    memset(dp, 0, sizeof dp); dp[0] = 1%mod;
    for(int i=1; i<=n; i++)
        for(int j=min(i, n); j>0; j--)
            dp[j] = (dp[j] + dp[j-1])%mod;
}

/**
    this is the probably fastest ncr
    interative method, stil it can overflow
*/
ll fastNCR(int n, int k){
    ll res = 1LL;
    if(k > n-k) k = n-k;
    for(int i=0; i<k; i++)
        res *= (n-i), res /= (i+1);
    return res;
}

/**
    Using Fermat's Theoram
    now ncr = (n!) / (r! * (n-r)!);
            = n! * inv(r!) * inv((n-r)!)
    now, we can pre compute all factorial values
         and find invers of a number in log (mod)
         // make sure that n is small, we can precalculate
            over 10^7, it'll cause tle.
*/

ll fact[mx];
void factorials(){
    fact[0] = fact[1] = 1;
    for(int i=2; i<mx; i++)
        fact[i] = (fact[i-1] * i) % mod;
}

template<typename T>
T multi(T a, T b, T mod){
    return ((a%mod) * (b%mod)) % mod;}

ll egcd(ll a, ll b, ll &x, ll &y){
    if(a == 0){x=0; y=1; return b;}
    ll x1, y1, g = egcd(b%a, a, x1, y1);
    x = y1 - (b/a) * x1; y = x1;
    return g;
}

ll inverse(ll a, ll mod){
    ll x, y, g = egcd(a, mod, x, y);
    if(g == 1) 
        return (x+mod)%mod; /// x can be neg.
    return -1; /// try naive inverse
}

ll ncr(ll n, ll r, ll mod){
    ll res = multi(fact[n], inverse(fact[r], mod), mod);
    res = multi(res, inverse(fact[n-r], mod), mod);
    return res;
}

/**
    we can find each number mod m in O(1)
    by pre calculating, here the approach
    /// make sure mod is small
*/

ll inv[mx];
void moduleMod(ll mod){
    inv[1] = 1%mod;
    for(int i=2; i<mod; i++)
        inv[i] = (mod - (mod/i) * inv[mod%i]%mod)%mod;
}

/** 
    nCr with large will cause tle above algo
    we can use lucas theoram if mod is small;    
    complexity : O(m * log n * log n). 
*/

ll nCrLucas(int n, int r, int mod){
    if(r == 0) return 1;
    int nn = n%mod, rr = r%mod;
    return (nCrLucas(n/mod, r/mod, mod) *
            ncr(nn, rr, mod));
}

ll LucasSolve(int n, int r, int mod){
    if(r == 0) return (1%mod);
    if(r == 1) return (n%mod);
    return nCrLucas(n, r, mod)%mod;
}

int main(int argc, const char** argv) {
    return 0;
}






















































