#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ull = unsigned long long;

const int mx = 1e6 + 5;
const int md = 1e9 + 7;

ull mod_multiply(ull a, ull b, ull m=md){
    ll ans = a * b - m * ull(1.L / m * a * b);
    return ans + m * (ans < 0) - m * (ans >= (ll)m);
}

ull power_mul(ull a, ull p, ull m=md){
    ull ans = 1;
    for(; p; a = mod_multiply(a, a, m), p>>=1)
        if(p & 1) ans = mod_multiply(ans, a, m);
    return ans;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    return 0;
}
