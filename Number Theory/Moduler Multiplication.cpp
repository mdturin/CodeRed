#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ull = unsigned long long;

const int mx = 1e6 + 5;
const int md = 1e9 + 7;

//ll mod_multiply(ll a, ll b, ll m=md){
//    ll res = 0; a %= m; b %= m;
//    while(b > 0){
//        if(b & 0x1) res = (res + a) % m;
//        (a < m-a) ? (a<<=1) : (a -= (m-a));
//        b >>= 1;
//    }return res;
//}

ull mod_multiply(ull a, ull b, ull m=md){
    ll ans = a * b - m * ull(1.L / m * a * b);
    return ans + m * (ans < 0) - m * (ans >= (ll)m);
}

int main(int argc, const char** argv) {

    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    ll a = 1e10, b = 1e11;
    cout << mod_multiply(a, b) << endl;

    return 0;
}
