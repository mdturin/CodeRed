#include "bits/stdc++.h"
using namespace std;

const int mx = 1e6+5;
const int INF = 1e9+9;

using ll = long long;
using pii = pair<int,int>;

#define ff first
#define se second
#define pb push_back
#define sz(x) int(x.size())

/// Complexity O( sqrt(n) )
vector<ll> allDivisors(ll x){
    ll lim = sqrt(x);
    vector< ll > ans;
    for(ll i=1; i<=lim; i++){
        if(x%i == 0){
            ans.pb(i);
            if(i != x/i)
                ans.pb(x/i);
        }
    }
    sort(begin(ans), end(ans));
    return ans;
}


int main(int argc, const char** argv) {
    return 0;
}
