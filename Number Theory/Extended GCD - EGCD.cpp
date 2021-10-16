#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const int mx = 1e6 + 5;
const int md = 1e9 + 7;

/**
    ax + by = c
    solution exist if c % gcd(a,b) == 0:
        ax + by = c' * gcd(a, b)
        (ax/c') + (by/c') = gcd(a, b)

        where,
            c' = c / gcd(a, b)
            x = x * c'
            y = y * c'
*/

// extended GCD
ll egcd(ll a, ll b, ll &x, ll &y){
    if(b == 0){x=1; y=0; return a;}
    ll xx, yy, g = egcd(b, a%b, xx, yy);
    y = xx - (a / b) * yy; x = yy;
    return g;
}

ll inverse(ll a, ll m){
    ll x, y, g = egcd(a, m, x, y);
    if(g != 1) return -1;
    return (x%m + m) % m;
}

int main(int argc, const char** argv) {

    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    long long a, b, c, x, y;
    while(cin >> a >> b >> c){
        ll g = egcd(a, b, x, y);
        ll nc = c / g;
        x *= nc; y *= nc;
        cout << x << " " << y << "\n";
    }

    return 0;
}
