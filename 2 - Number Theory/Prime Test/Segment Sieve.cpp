#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const int mx = 1e5 + 5;
const int md = 1e9 + 7;

int mark[mx];
vector<int> prime;

inline bool is_prime(int x){
    return mark[x] == x;}

void LinearSieve(){
    mark[0] = mark[1] = -1;
    for(int i=2, j=0; i<mx; i++, j=0){
        if(!mark[i]){mark[i] = i; prime.push_back(i);}
        while(j<prime.size() && prime[j]<=mark[i] && (ll)i*prime[j]<mx)
            mark[i * prime[j]] = prime[j], j++;
    }
}

// required precalculated sqrt(m-n+1) primes
inline void segSieve(ll n, ll m){
  assert(n>1 && n <= m);
  int len = m - n + 1;

  char cur_mark[len] = {};
  for(int p : prime){
    if((ll)p * p > m) break;
    for(ll j=(ll)(n/p)*p; j<=m; j+=p){
        if(j<n || j == p) continue;
        cur_mark[j-n] = 1;
    }
  }
  for(ll i=0; i<len; i++)
    if(cur_mark[i] == 0)
        // do something, (n+i) is prime
}

int main(int argc, const char** argv) {

    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    LinearSieve();
    segSieve(2, 100);

    return 0;
}

