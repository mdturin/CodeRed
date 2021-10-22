#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const int mx = 1e6 + 5;
const int md = 1e9 + 7;

/**
    Chinese Reminder Theorem (CRT)
    finding the smallest x such that
        x = rem[i] (mod m[i])
*/

ll get_mod(ll x, ll m){
    return ((x%m)+m)%m;}

// extended GCD
ll egcd(ll a, ll b, ll &x, ll &y){
    if(b == 0){x=1; y=0; return a;}
    ll xx, yy, g = egcd(b, a%b, xx, yy);
    y = xx - (a / b) * yy; x = yy;
    return g;
}

using vl = vector<ll>;
pair<ll, ll> CRT(const vl &b, const vl &m){
    ll r = 0, M = 1, p, q;
    for(int i=0; i<b.size(); ++i){
        ll g = egcd(M, m[i], p, q);
        if((b[i]-r) % g != 0) return {0, -1};
        ll x = (b[i] - r) / g * p % (m[i] / g);
        r += M * x;
        M *= m[i] / g;
    }return {get_mod(r, M), M};
}

int main(int argc, const char** argv) {

    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    cout << CRT({1,3}, {5,7}).first << "\n";

    return 0;
}
