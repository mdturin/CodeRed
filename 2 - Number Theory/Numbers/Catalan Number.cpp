// https://oeis.org/A000108

// Formula  - C(n+1) = binomial(2*n, n) / (n+1)
//                   = (2*n)! / (n! * (n+1)!)
//          - C(n+1)​ = C0.​Cn ​+ C1.​C(n−1) ​+ ⋯ + Cn.​C0​
//                   = (k=0 to n) ∑ ​Ck.​C(n−k)​

// Sequence - 1, 1, 2, 5, 14, 42, 132, 429, 1430, 4862, 16796, 58786, 208012,
//          742900, 2674440, 9694845, 35357670, 129644790, 477638700, 1767263190,
//          6564120420, 24466267020, 91482563640, 343059613650, 1289904147324,
//          4861946401452, 18367353072152, 69533550916004, 263747951750360,
//          1002242216651368, 3814986502092304 .....

#include <bits/stdc++.h>
using namespace std;

const int mx = 1e5 + 5;
const int MOD = 1e9 + 7;

template <const int32_t MOD> struct modint{
    #define IM inline modint<MOD>
    #define TPT template<typename T>

    int32_t value; modint() = default;
    TPT modint(T value_) : value(value_%MOD) {}
    IM operator + (modint<MOD> other) const { int32_t c = this->value + other.value; return modint<MOD>(c >= MOD ? c - MOD : c); }
    IM operator - (modint<MOD> other) const { int32_t c = this->value - other.value; return modint<MOD>(c <    0 ? c + MOD : c); }
    IM operator * (modint<MOD> other) const { int32_t c = (int64_t)this->value * other.value % MOD; return modint<MOD>(c < 0 ? c + MOD : c); }
    IM &operator += (modint<MOD> other) {this->value += other.value; if (this->value >= MOD) this->value -= MOD; return *this; }
    IM &operator -= (modint<MOD> other) {this->value -= other.value; if (this->value <    0) this->value += MOD; return *this; }
    IM &operator *= (modint<MOD> other) {this->value = (int64_t)this->value * other.value % MOD; if (this->value < 0) this->value += MOD; return *this; }
    IM operator - () const { return modint<MOD>(this->value ? MOD - this->value : 0); }
    modint<MOD> pow(uint64_t k) const { modint<MOD> x = *this, y = 1; for (; k; k >>= 1) { if (k & 1) y *= x; x *= x; } return y; }
    modint<MOD> inv() const { return pow(MOD - 2); }  // MOD must be a prime
    IM operator /  (modint<MOD> other) const { return *this *  other.inv(); }
    IM operator /= (modint<MOD> other)       { return *this *= other.inv(); }
    inline bool operator == (modint<MOD> other) const {return value == other.value;}
    inline bool operator != (modint<MOD> other) const {return value != other.value;}
    inline bool operator < (modint<MOD> other)  const {return value < other.value;}
    inline bool operator > (modint<MOD> other)  const {return value > other.value;}

    TPT IM &operator += (T ot){return *this += modint<MOD>(ot);}
    TPT IM &operator -= (T ot){return *this -= modint<MOD>(ot);}
    TPT IM &operator *= (T ot){return *this *= modint<MOD>(ot);}
    TPT IM &operator /= (T ot){return *this *= modint<MOD>(ot).inv();}

    TPT IM operator + (T ot) const {return *this + modint<MOD>(ot);}
    TPT IM operator - (T ot) const {return *this - modint<MOD>(ot);}
    TPT IM operator * (T ot) const {return *this * modint<MOD>(ot);}
    TPT IM operator / (T ot) const {return *this / modint<MOD>(ot);}
};

template <const int32_t _M> struct Combo{
private:
    using MI = modint<_M>;
    vector<MI> f, nf, invs;
    void __build__(int N){
        f[0] = nf[0] = invs[1] = 1;
        for (int i = 2; i < N; i++)
            invs[i] = invs[_M%i] * (-_M/i);
        for(int i = 1; i < N; i++){
            f[i] = f[i - 1] * i;
            nf[i] = nf[i - 1] * invs[i];
        }
    }
public:
    Combo() = default;
    Combo(int N=2):f(N),nf(N),invs(N){__build__(N);}
    MI ncr(int n, int k){
        return (n<k || k<0) ? 0 : f[n] * nf[k] * nf[n-k];}
    inline MI fact(int n) {return f[n];}
    inline MI finv(int n) {return nf[n];}
    inline MI  inv(int n) {return invs[n];}
};

using C = Combo<MOD>;
using mint = modint<MOD>;

C sol(mx);
int get_catalan(int x){
    return (sol.ncr(2*x, x) /= (x+1)).value;
}

int main(int argc, const char** argv) {

    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n; cin >> n;
    cout << get_catalan(n) << "\n";

    return 0;
}


























































