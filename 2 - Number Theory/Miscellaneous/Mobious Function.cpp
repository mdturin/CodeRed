#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const int mx = 1e6 + 5;
const int md = 1e9 + 7;

// Mobius Function Sieve
// The mobius function, for a positive integer n, is defined as

//     μ(n) = 0 if n has one or more repeated prime factors.
//     μ(n) = 1 if n = 1
//     μ(n) =  (-1)^k if n is a product of k distinct prime factors.

// mob[i] = Mobius function value of i
// mark[i] = Smallest prime factor of i

vector<int> prime;
int mark[mx], mob[mx];

inline bool is_prime(int x){return mark[x] == x;}

void LinearSieve(){
    mark[0] = mark[1] = -1;
    for(int i=2, j=0; i<mx; i++, j=0){
        if(!mark[i]){mark[i] = i; prime.push_back(i);}
        while(j<(prime.size()) && prime[j]<=mark[i] && (ll)i*prime[j]<mx)
            mark[i * prime[j]] = prime[j], j++;
    }
}

inline void mobius_fun(){
    mob[1] = 1;
    for(int i=2; i<mx; i++)
    if(mark[i / mark[i]] == mark[i])
        mob[i] = 0;
    else mob[i] = -mob[i / mark[i]];
}

int main(int argc, const char** argv) {

    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    LinearSieve();
    mobius_fun();

    return 0;
}

