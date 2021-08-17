#include<bits/stdc++.h>
using namespace std;
using ll = long long;
using ull = unsigned long long;

const int mx = 1e6 + 5;
const int md = 1e9 + 7;

int mark[mx];
vector<int> prime;

void LinearSieve(){
    for(int i=2, j=0; i<mx; i++, j=0){
        if(!mark[i]){mark[i] = i; prime.push_back(i);}
        while(j<(prime.size()) && prime[j]<=mark[i] && (ll)i*prime[j]<mx)
            mark[i * prime[j]] = prime[j], j++;
    }
}

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

ull number_of_divisors(ull x){
    ull ans = 1LL;
    for(int p : prime){
        if(1LL*p*p*p > x) break;
        ll cnt = 1LL;
        while(x%p == 0)
            x /= p, cnt++;
        ans *= cnt;
    }

    ll y = sqrtl(x);
    if(is_prime(x)) ans <<= 1;
    else if(is_prime(y) && (y*y)==x)
        ans *= 3LL;
    else if(x != 1) ans <<= 2;

    return ans;
}

int main(){

    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    LinearSieve(); // Store All Prime Upto MX

    int tc; cin >> tc;
    while(tc--){
        ull n; cin >> n;
        cout << number_of_divisors(n) << "\n";
    }

    return 0;
}

