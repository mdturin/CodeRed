#include<bits/stdc++.h>
using namespace std;
using ll = long long;
using ii = pair<int,int>;

const int md = 1e9 + 7;
const int mx = 1e6 + 5;

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


using mint = modint<md>;

int main(){

    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    return 0;
}

