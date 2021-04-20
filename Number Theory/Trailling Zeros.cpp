#include "bits/stdc++.h"
using namespace std;

using ll = long long;

ll traillingZeros(ll x){
    ll ans = 0;
    for(ll i=5; i<=x; i*=5)
        ans += (x/i);
    return ans;
}

int main(int argc, const char** argv) {
    return 0;
}