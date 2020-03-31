#include "bits/stdc++.h"
using namespace std;

using ll = long long;
const ll mod = 1e9+7;
const int mx = 1e5+5;

#define sz(x) int(x.size()) 

vector<int> prime;
void sieve(){}

/// Euler Totient Function
/// computing phi value in sqrt(n)
int singlePhi(int n){
    int res = n;
    for(int p=2; p*p<=n; p++){
        if(n%p == 0){
            while(n%p == 0)
                n /= p;
            res -= (res/p);
        }
    }
    if(n>1) res -= (res/n);
    return res;
}

/// required precalculated sqrt(n) primes
int phiPrime(int n){
    int res = n, lim = sqrt(n);
    for(int i=0; i<sz(prime); i++){
        int p = prime[i];
        if(p>n) break;
        if(n%p == 0){
            res -= (res/p);
            while(n%p == 0)
                n /= p;
        }
    }
    if(n>1) res -= (res/n);
    return res;
}

/// computing phi value upto mx
ll phi[mx];
void computePhi(){
    for(int i=1; i<mx; i++) phi[i] = i;
    for(int i=2; i<mx; i++)
    if(phi[i] == i){
        phi[i] = i-1;
        for(int j=i<<1; j<mx; j+=i)
            phi[j] = (phi[j]/i) * (i-1);
    }
}

int main(int argc, const char** argv) {
    return 0;
}