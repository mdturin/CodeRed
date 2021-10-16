#include<bits/stdc++.h>
using namespace std;

const int md = 1e9 + 7;
const int mx = 1e6 + 5;

template <const int MOD>
struct modint {
    int value;
    modint() = default;
    modint(int value_) : value(value_) {}
    inline modint<MOD> operator + (modint<MOD> other) const { int c = this->value + other.value; return modint<MOD>(c >= MOD ? c - MOD : c); }
    inline modint<MOD> operator - (modint<MOD> other) const { int c = this->value - other.value; return modint<MOD>(c <    0 ? c + MOD : c); }
    inline modint<MOD> operator * (modint<MOD> other) const { int c = (int64_t)this->value * other.value % MOD; return modint<MOD>(c < 0 ? c + MOD : c); }
    inline modint<MOD> & operator += (modint<MOD> other) { this->value += other.value; if (this->value >= MOD) this->value -= MOD; return *this; }
    inline modint<MOD> & operator -= (modint<MOD> other) { this->value -= other.value; if (this->value <    0) this->value += MOD; return *this; }
    inline modint<MOD> & operator *= (modint<MOD> other) { this->value = (int64_t)this->value * other.value % MOD; if (this->value < 0) this->value += MOD; return *this; }
    inline modint<MOD> operator - () const { return modint<MOD>(this->value ? MOD - this->value : 0); }
    modint<MOD> pow(uint64_t k) const { modint<MOD> x = *this, y = 1; for (; k; k >>= 1) { if (k & 1) y *= x; x *= x; } return y; }
    modint<MOD> inv() const { return pow(MOD - 2); }  // MOD must be a prime
    inline modint<MOD> operator /  (modint<MOD> other) const { return *this *  other.inv(); }
    inline modint<MOD> operator /= (modint<MOD> other)       { return *this *= other.inv(); }
    inline bool operator == (modint<MOD> other) const { return value == other.value; }
    inline bool operator != (modint<MOD> other) const { return value != other.value; }
    inline bool operator < (modint<MOD> other) const { return value < other.value; }
    inline bool operator > (modint<MOD> other) const { return value > other.value; }
};

template <int32_t MOD> modint<MOD> operator * (int32_t value, modint<MOD> n) { return modint<MOD>(value%MOD) * n;}
template <int32_t MOD> modint<MOD> operator * (int64_t value, modint<MOD> n) { return modint<MOD>(value%MOD) * n;}

using mint = modint<md>;

struct combi{
    int n; vector<mint> facts, finvs, invs;
    combi(int _n): n(_n), facts(_n), finvs(_n), invs(_n){
        facts[0] = finvs[0] = invs[1] = 1;
        for (int i = 2; i < n; i++) 
            invs[i] = invs[md%i] * (-md/i);
        for(int i = 1; i < n; i++){
            facts[i] = facts[i - 1] * i;
            finvs[i] = finvs[i - 1] * invs[i];
        }
    }
    inline mint  inv(int n) { return invs[n];}
    inline mint fact(int n) { return facts[n];}
    inline mint finv(int n) { return finvs[n];}
    inline mint ncr(int n, int k) {
        return n < k or k < 0 ? 0 : facts[n] * finvs[k] * finvs[n-k];}
}; combi C(N);

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cout << C.ncr(10, 2) << '\n';

    return 0;
}