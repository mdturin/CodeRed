#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ull = unsigned long long;

const int mx = 1e6 + 5;
const int md = 1e9 + 7;

/// given numbers and reminders
/// finding the smallest x that
/// each number ai, x%ai == ri

ll num[] = {3, 4, 5}, rem[] = {2, 3, 1};
ll n = sizeof(num) / sizeof(num[0]);

ll egcd(ll a, ll b, ll &x, ll &y){
    if(b == 0){x=1; y=0; return a;}
    ll xx, yy, g = egcd(b, a%b, xx, yy);
    y = xx - (a / b) * yy; x = yy;
    return g;
}

/// naive approach
inline ll CRT(ll x){
    for(int i=0; i<n; i++)
        if(x % num[i] != rem[i])
            return CRT(x+1);
    return x;
}

/// faster method for finding CRT
ll inv(ll a, ll m){
    if(m == 1) return 0;
    ll x, y;
    ll g = egcd(a, m, x, y);
    return (y + m) % m;
}

inline ll CRT(){
    ll prod = 1LL, x = 0;
    for(ll i=0; i<n; i++) prod *= num[i];
    for(ll i=0; i<n; i++){
        ll pp = prod / num[i];
        x += (rem[i] * inv(pp, num[i]) * pp);
    }return (x%prod);
}

int main(int argc, const char** argv){

    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    cout << CRT() << "\n";

    return 0;
}
