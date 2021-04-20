#include "bits/stdc++.h"
using namespace std;

using ll = long long;

// extended gcd
ll egcd(ll a, ll b, ll &x, ll &y){
    if(a == 0){x=0; y=1; return b;}
    ll x1, y1, g = egcd(b%a, a, x1, y1);
    x = y1 - (b/a)*x1; y = x1;
    return g;
}

int main(int argc, const char** argv) {
    return 0;
}