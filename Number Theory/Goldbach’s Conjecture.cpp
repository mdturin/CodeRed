#include "bits/stdc++.h"
using namespace std;

// Goldbach’s Conjecture
// 	Every even integer greater than 2 can be expressed as the sum of two primes

using ll = long long;
using pll = pair<ll,ll>;
const int mx = 1e7+5;

vector<int> prime;
vector<int> mark(mx, 0);

void sieve(){/** run sieve(); */}

pll goldBach(ll x){
	for(int i=0; i<prime.size(); i++){
		ll y = x - prime[i];
        
        // if(binary_search(all(prime), y))
        //     return pll(prime[i], y);

        // we can simply use mark array
        if(!mark[y]) return pll(prime[i], y);
	}
}

int main(int argc, const char** argv) {
    return 0;
}