#include<bits/stdc++.h>
using namespace std;
using ll = long long;
using ii = pair<int,int>;

const int mx = 1e6 + 5;
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
mint lucas(ll n, ll r){
    if(r > n) return 0;
    if(n < md) 
        return sol.ncr(n, r);
    return lucas(n/md, r/md) * 
           lucas(n%md, r%md);
}

int main(){

    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    mint ans = lucas(100000000, 2322);
    cout << ans << "\n";
    
    return 0;
}

