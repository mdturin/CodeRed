#include "bits/stdc++.h"
using namespace std;

const int mx = 1e6+5;
const int mod = 1e9+7;
using ll = long long;

#define pb push_back 
#define sz(x) int(x.size()) 

int mark[mx];
vector<int> prime;

// generating sieve upto mx
/// complexity(mx log (log (mx)))

// void sieve(){
//     mark[0] = mark[1] = 1;
//     prime.pb(2);
//     for(int i=4; i<mx; i+=2)
//         mark[i] = 1;
//     register ll i, j, k;
//     for(i=3; i<mx; i+=2)
//     if(!mark[i]){
//         prime.pb(i);
//         for(j=i*i,k=i+i; j<mx; j+=k)
//             mark[j] = 1;
//     }
// }

/// linear complexity O(mx)
void LinearSieve(){
    register long long i, j;
    for(i=2, j=0; i<mx; i++, j=0){
        if(!mark[i]){mark[i] = i;prime.pb(i);}
        while(j<(prime.size()) && prime[j]<=mark[i] && i*prime[j]<mx)
            mark[i * prime[j]] = prime[j], j++;
    }
}

/// required precalculated sqrt(m-n+1) primes
void segSieve(ll n, ll m){
    int mark2[m-n+1] = {0}; ll i, j;
    for(i=0; i<sz(prime); i++){
        if(prime[i]*prime[i] > m) break;
        j = (n/prime[i]);
        for(j*=prime[i]; j<=m; j+=prime[i]){
            if(j<n || j == prime[i])
                continue;
            mark2[j-n] = 1;
        }
    }
    for(i=0; i<m-n+1; i++){
        if(mark2[i] == 0){
            // do something
        }
    }
}

/// storing smallest prime for all numbers
/// upto mx, for fastest factorizing
void sieve(){
    for(int i=0; i<mx; i++)  mark[i] = i;
    for(int i=2; i<mx; i+=2) mark[i] = 2;

    int lim = sqrt(mx);
    register ll i, j, k;
    for(i=3; i<=lim; i+=2)
    if(mark[i] == i){
        for(j=i*i,k=i+i; j<mx; j+=k)
        if(mark[j] == j)
            mark[j] = i;
    }
}

// Mobius Function Sieve
// The mobius function, for a positive integer n, is defined as

//     μ(n) = 0 if n has one or more repeated prime factors.
//     μ(n) = 1 if n = 1
//     μ(n) =  (-1)^k if n is a product of k distinct prime factors.

// mob[i] = Mobius function value of i
// mark[i] = Smallest prime factor of i

int mob[mx];
void mobius_fun(){
    mob[1] = 1;
    for(int i=2; i<mx; i++)
    if(mark[i / mark[i]] == mark[i])
        mob[i] = 0;
    else mob[i] = -mob[i / mark[i]];
}

int main(int argc, const char** argv) {
    return 0;
}
