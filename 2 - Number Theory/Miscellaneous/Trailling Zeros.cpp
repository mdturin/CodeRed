#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const int mx = 1e6 + 5;
const int md = 1e9 + 7;

// # tailling zeros in x!
ll number_of_tailling_zeros(ll x){
    ll ans = 0;
    for(ll i=5; i<=x; i*=5LL)
        ans += (x/i);
    return ans;
}

int main(int argc, const char** argv) {

    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    cout << number_of_tailling_zeros(5) << "\n";

    return 0;
}
