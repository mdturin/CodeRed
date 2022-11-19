#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const int mx = 1e6 + 5;
const int md = 1e9 + 7;

template <typename T>
T power(T v, T p, T m=md) {
  v %= m; T r = 1;
  while (p > 0){
    if (p & 1)
      r = (1LL * r * v) % m;
    v = (1LL * v * v) % m; p >>= 1;
  }return r;
}

ll f[mx], nf[mx];
inline void get_factorials(){
	f[0] = nf[0] = 1;
	for(int i=1; i<mx; ++i){
		f[i] = 1LL * f[i-1] * i % md;
//		nf[i] = power<ll>(f[i], md-2);
	}
}

inline void get_factorials_inverse(){
	// get_factorials first
	nf[mx-1] = power<ll>(f[mx-1], md-2);
	for(int i=mx-2; i>=0; --i)
		nf[i] = (ll)(i+1) * nf[i+1] % md;
}

int main(int argc, const char** argv) {

	ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

	get_factorials();
	get_factorials_inverse();

    return 0;
}
