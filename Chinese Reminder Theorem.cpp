#include "bits/stdc++.h"
using namespace std;

/// given numbers and reminders
/// finding the smallest x that
/// each number ai, x%ai == ri

using ll = long long;

ll num[] = {3, 4, 5};
ll rem[] = {2, 3, 1};
ll n = sizeof(num) / sizeof(ll);

ll egcd(ll a, ll b, ll &x, ll &y){
    if(a == 0){x=0; y=1; return b;}
    ll x1, y1, g = egcd(b%a, a, x1, y1);
    x = y1 - (b/a)*x1; y = x1;
    return g;
}

/// naive approach
ll CRT(ll x){
    for(int i=0; i<n; i++)
        if(x % num[i] != rem[i])
            return CRT(x+1);
    return x;
}

/// faster method for finding CRT
ll inv(ll a, ll m){
    if(m == 1) return 0;
    ll x, y, g = egcd(a, m, x, y);
    return (x+m)%m;
}

ll CRT(){
    ll prod = 1LL, x = 0, pp;
    for(ll i=0; i<n; i++) prod *= num[i];
    for(ll i=0; i<n; i++){
        pp = prod / num[i];
        x += (rem[i] * inv(pp, num[i]) * pp);
    }
    return (x%prod);
}   

int main(int argc, const char** argv) {
    cout << CRT() << "\n";
    return 0;
}