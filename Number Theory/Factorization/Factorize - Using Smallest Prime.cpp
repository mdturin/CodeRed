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

vector<int> get_factorize(int n){
    assert(n < mx);
    vector<int> f; while(n > 1){
        int p = mark[n];
        while(n%p == 0)
            f.push_back(p), n /= p;
    }return move(f);
}

int main(int argc, const char** argv) {

    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    LinearSieve();

    vector<int> f = get_factorize(1e6);
    for(int u : f)
        cout << u << " ";

    return 0;
}

