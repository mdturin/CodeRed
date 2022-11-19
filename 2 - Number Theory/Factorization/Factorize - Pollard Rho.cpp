#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ull = unsigned long long;
const int mx = 1e6 + 5;

template<typename T = int>
T gcd(T a, T b){
  return b == 0 ? a : gcd(b, a%b);}

ull mod_multiply(ull a, ull b, ull m){
  ll ans = a * b - m * ull(1.L / m * a * b);
  return ans + m * (ans < 0) - m * (ans >= (ll)m);
}

ull power_mul(ull a, ull p, ull m){
  ull ans = 1;
  for(; p; a = mod_multiply(a, a, m), p>>=1)
    if(p & 1) ans = mod_multiply(ans, a, m);
  return ans;
}

int mark[mx];
vector<int> prime;

void LinearSieve(){
  mark[0] = mark[1] = -1;
  for(int i=2, j=0; i<mx; i++, j=0){
    if(!mark[i]){mark[i] = i; prime.push_back(i);}
    while(j<prime.size() && prime[j]<=mark[i] && (ll)i*prime[j]<mx)
      mark[i * prime[j]] = prime[j], j++;
  }
}

ull helper[] = {2, 325, 9375, 28178, 450775, 9780504, 1795265022};
bool is_prime(ull n){
  if(n < mx) return mark[n] == n;
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

ll f(ll x, ll c, ll mod){
  return (mod_multiply(x, x, mod) + c) % mod;}

ll pollard_rho(ll n){
  ll s=0, t=0, c=rand()%(n-1)+1, val=1;
  for(int goal = 1;; goal <<= 1, s = t){
    for(int step = 1; step<=goal; ++step){
      t = f(t, c, n);
      val = mod_multiply(val, abs(t-s), n);
      if(step % 127 == 0){
        ll d = gcd<ll>(val, n);
        if(d > 1) return d;
      }
    }ll d = gcd<ll>(val, n);
    if(d > 1) return d;
  }return 1;
}

vector<ll> get_factorize(ll n){
  vector<ll> f;
  while(n%2 == 0)
    f.push_back(2), n >>= 1;

  queue<ll> q; q.push(n);
  while(q.size()){
    ll x = q.front(); q.pop();
    if(x == 1) continue;
    if(is_prime(x)){
      f.push_back(x);
      continue;
    }
    ll d = x; while(d == x)
      d = pollard_rho(x);
    q.push(d); q.push(x/d);
  }sort(f.begin(), f.end());
  return move(f);
}

int main(int argc, const char** argv) {

  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  LinearSieve();
  ll n = 3245364745678567LL;

  vector<ll> v = get_factorize(n);
  for(ll &u : v) cout << u << " ";
  cout << endl << endl;
  // 879031 3691979857

  return 0;
}
