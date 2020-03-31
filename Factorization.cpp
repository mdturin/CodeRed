#include "bits/stdc++.h"
#include "dbg.hpp"
using namespace std;

using ll = long long;
using vl = vector<ll>;

const ll mod = 1e9+7;
const int mx = 1e7+5;

#define pb push_back 
#define sz(x) int(x.size()) 

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

// O( sqrt (n) )
vl trial(ll n){
    vl fact;
    for(ll i=2; i*i<=n; i++)
        while(n%i == 0)
            fact.push_back(i),
            n = n / i;
    if(n>1) fact.push_back(n);
    return fact;
}

// O( sqrt(n) )
vl trial2(ll n){
    vl fact;
    while(n%2 == 0)
        fact.push_back(2), n >>= 1;
    for(ll i=3; i*i<=n; i+=2)
        while(n%i == 0)
            fact.push_back(i), n /= i;
    if(n>1) fact.push_back(n);
    return fact;
}

// O( sqrt(n) )
vl trial3(ll n){
    vl fact;
    for(int i:{2, 3, 5})
        while(n%i == 0)
            fact.push_back(i), n /= i;
    int i=0, ara[] = {4, 2, 4, 2, 4, 6, 2, 6};
    for(ll d=7; d*d<=n; d += ara[i++], i=(i==8)?0:i)
        while(n%d == 0)
            fact.push_back(d),
            n /= d;
    if(n>1) fact.push_back(n);
    return fact;
}

// O( sqrt(n) )
vl trial4(ll n){
    vl fact;
    for(ll d:prime){
        if(d*d > n) break;
        while(n%d == 0)
            fact.pb(d), n/=d;
    }
    if(n>1) fact.pb(n);
    return fact;
}

// O( log(n) )
vl trial5(ll n){
    vl fact;
    while(mark[n] > 1){
        ll p = mark[n];
        while(n%p == 0)
            fact.pb(p), n/=p;
    }
    return fact;
}

int main(int argc, const char** argv) {

    LinearSieve();
    auto v = trial5(1015478);
    cout << v << "\n";

    return 0;
}