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

/**
long long t, a[mx], n[mx], ans, lc;
inline long long normalize(long long x, long long mod) { x %= mod; if (x < 0) x += mod; return x; }

struct GCD_type { long long x, y, d; };
GCD_type ex_GCD(long long a, long long b){
    if (b == 0) return {1, 0, a};
    GCD_type pom = ex_GCD(b, a % b);
    return {pom.y, pom.x - a / b * pom.y, pom.d};
}

void CRT(){
    ans = a[1]; lc = n[1];
    for(int i = 2; i <= t; i++){
        auto pom = ex_GCD(lc, n[i]);
        int x1 = pom.x;
        int d = pom.d;
        if((a[i] - ans) % d != 0) {
            write("Infinity Stones are just a myth\n");
            exit(0);
        }
        ans = normalize(ans + x1 * (a[i] - ans) / d % (n[i] / d) * lc, lc * n[i] / d);
        lc = lcm(lc, n[i]); // you can save time by replacing above lcm * n[i] /d by lcm = lcm * n[i] / d
    }
    write(ans, nl);
}

void MAIN(int &cs){
//    write("Case ", cs, ": ");
    read(t); in(a+1,t); in(n+1,t);
    CRT();
}
*/

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
