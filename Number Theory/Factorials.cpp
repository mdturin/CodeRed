#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const int mx = 1e5+5;
const int mod = 1e9+7;

// straigt forward, complexity : O(n)
ll factorial1(int n, int m){
	ll res = 1;
	for(int i=2; i<=n; i++)
		res = (res * (i%m))%m;
	return res%m;
}

// pre calculate, complexity O(mx)
ll fact[mx];
void dp(){
	fact[0] = fact[1] = (1%mod);
	for(int i=2; i<mx; i++)
		fact[i] = (fact[i-1] * (i%mod))%mod;
}

// if n is larger, but mod m is small
// we can compute in ( m * log n );
ll factorial2(ll n, int m){
	ll res = 1LL;
	while(n>1){
		res = (res * ((n/m)&1 ? m-1 : 1))%m;
		for(int i=2; i<=(n%m); i++)
			res = (res * i) % m;
	}
	return res;
}

int main(int argc, const char** argv) {

	ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    return 0;
}
