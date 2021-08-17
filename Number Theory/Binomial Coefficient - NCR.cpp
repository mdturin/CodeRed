#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const int mx = 1e3 + 5;
const int md = 1e9 + 7;

/**
    Analytic formula    : (nCk) = (n!) / (k! * (n-k)!);
    Recurrence formula  : (nCk) = ((n-1) C k) + ((n-1) C (k-1));

    Properties:
        Symmetry rule : (nCk) = (n C (k-1));
        Factoring : (nCk) = (n/k) * (n-1) C (k-1);
        Sum over k : summation of (nCk) where k = 0 to n = power(2, n)
        Sum over n : summation of (mCk) where m = 0 to n = (n+1) C (k+1)
        Sum over n and k:
            (n+k) C (k) where k = 0 to m = (n+m+1) C (m)
        Weighted Sum :
            1(nC1) + 2(nC2) + ... + n(nCn) = n * power(2, n-1);
        Relation with Fibonacci:
            (nC0) + (n-1)C1 + ... + (n-k)Ck + .. + 0Cn = (n+1)th fibonacchi number
        (a+b)^n = (nC0) * a^n + (nC1) * a^(n-1) * b + ...
                + (nCk) * a^(n-k) * b^k + ... + (nCn) b^n

*/

template <typename T>
T power(T v, T p, T m=md) {
    v %= m; T r = 1;
    while (p > 0){
        if (p & 1)
            r = (1LL * r * v) % m;
        v = (1LL * v * v) % m; p >>= 1;
    }return r;
}

int inv[mx]; // inverse - [1, mx)
void get_inverse(){
    inv[0] = inv[1] = 1;
    for(int i=2; i<mx; i++)
        inv[i] = (md - (md/i) * inv[md%i]%md)%md;
}

ll get_ncr_naive(int n, int k){
    ll res = 1LL;
    if(k > n-k) k = n-k;
    for(int i=0; i<k; i++){
        res = res * (n-i) % md;
        res = res * inv[i + 1] % md;
    }return res;
}

ll ncr[mx][mx];
void calcuate_ncr_table(){
    for(int i=0; i<mx; i++){
        ncr[i][0] = ncr[i][i] = 1;
        for(int j=1; j<i; j++)
            ncr[i][j] = (ncr[i-1][j] + ncr[i-1][j-1]) % md;
    }
}

ll f[mx], nf[mx];
inline void get_factorials(){
	f[0] = nf[0] = 1;
	for(int i=1; i<mx; ++i){
		f[i] = f[i-1] * i % md;
//		nf[i] = power<ll>(f[i], md-2);
	}
}

inline void get_factorials_inverse(){
	// get_factorials first
	nf[mx-1] = power<ll>(f[mx-1], md-2);
	for(int i=mx-2; i>=0; --i)
		nf[i] = (ll)(i+1) * nf[i+1] % md;
}

inline int get_ncr_fact(int n, int m){
    int ans = f[n] * nf[n-m] % md;
    return (ll)ans * nf[m] % md;
}

int main(int argc, const char** argv) {

    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    get_inverse();
    get_factorials();
    get_factorials_inverse();

    return 0;
}






















































