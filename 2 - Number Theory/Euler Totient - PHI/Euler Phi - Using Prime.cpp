#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const int mx = 1e6 + 5;
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

int get_phi(int n){
    int res = n;
    for(int p : prime){
        if(1LL * p * p > n) break;
        if(n % p) continue;
        res -= (res/p);
        while(n%p == 0) n /= p;
    }
    if(n>1) res -= (res/n);
    return res;
}

int main(int argc, const char** argv) {

    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    LinearSieve();
    cout << get_phi(1e8) << "\n";

    return 0;
}
