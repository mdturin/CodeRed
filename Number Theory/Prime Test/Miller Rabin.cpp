#include<bits/stdc++.h>
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

ull helper[] = {2, 325, 9375, 28178, 450775, 9780504, 1795265022};
bool is_prime(ull n){
    if(n <= 3) return n >= 2;
    if(n % 2 == 0) return false;
    if(n % 6 % 4 != 1) return (n | 1) == 3;

    ull s = __builtin_ctzll(n-1), d = n >> s;
    for(ull a : helper){
        ull p = power_mul(a%n, d, n), i = s;
        while(p != 1 && p != n-1 && (a%n) && i--)
            p = mod_multiply(p, p, n);
        if(p != n-1 && i != s) return false;
    }return true;
}

int main(){

    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int tc; cin >> tc;
    while(tc--){
        ull n; cin >> n;
        if(is_prime(n))
            cout << "YES\n";
        else cout << "NO\n";
    }

    return 0;
}

