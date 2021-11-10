#include<bits/stdc++.h>
using namespace std;
using ll = long long;

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

const int mod1 = 1e9 + 7;
const int mod2 = 1e9 + 9;
using mint1 = modint<mod1>;
using mint2 = modint<mod2>; 

struct modpair{
private:
    #define F first
    #define S second
    #define M modpair
    #define IL inline
    #define IMP inline modpair
    #define TPT template<typename T>
    using PLL = pair<mint1, mint2>;
public:
    PLL V; 
    modpair() = default;
    modpair(PLL X) : V(X){}
    TPT modpair(T x, T y):V({x,y}){}

    IMP operator + (M O) const{M res; res.V = {V.F + O.V.F, V.S + O.V.S}; return res;}
    IMP operator - (M O) const{M res; res.V = {V.F - O.V.F, V.S - O.V.S}; return res;}
    IMP operator * (M O) const{M res; res.V = {V.F * O.V.F, V.S * O.V.S}; return res;}
    IMP &operator += (M O){this->V.F += O.V.F; this->V.S += O.V.S; return *this;}
    IMP &operator -= (M O){this->V.F -= O.V.F; this->V.S -= O.V.S; return *this;}
    IMP &operator *= (M O){this->V.F *= O.V.F; this->V.S *= O.V.S; return *this;}
    IMP pow(uint64_t k) const{
        M x = *this, y = {1, 1}; for (; k; x *= x, k >>= 1){if (k & 1) y *= x;} return y;}
    IMP inv() const{return pow(1LL*(mod1-1)*(mod2-1)-1);}
    IMP operator /  (M O) const{return *this *  O.inv();}
    IMP operator /= (M O)      {return *this *= O.inv();}
    IL bool operator == (M O) const{return V == O.V;}
    IL bool operator != (M O) const{return V != O.V;}
    IL bool operator  < (M O) const{return V  < O.V;}
    IL bool operator  > (M O) const{return V  > O.V;}
    IMP & operator += (PLL O){return *this += M(O);}
    IMP & operator -= (PLL O){return *this -= M(O);}
    IMP & operator *= (PLL O){return *this *= M(O);}
    IMP & operator /= (PLL O){return *this *= M(O).inv();}
    IMP operator + (PLL ot) const{return *this + M(ot);}
    IMP operator - (PLL ot) const{return *this - M(ot);}
    IMP operator * (PLL ot) const{return *this * M(ot);}
    IMP operator / (PLL ot) const{return *this * M(ot).inv();}
};

ostream & operator << (ostream &os, modpair m){
    return os << "(" << m.V.F.value << ", " << m.V.S.value << ")";}

int main(){

    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    modpair m = {11, 2}, p = {3, 5};
    // m *= p;
    m = m.pow(10);

    cout << m << "\n";
    cout << p << "\n";

    modpair r = m + p;
    cout << r << "\n";

    bool ok = m < p;
    cout << (ok ? 1 : 0) << "\n";

    return 0;
}

