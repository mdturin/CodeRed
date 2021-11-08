#include<bits/stdc++.h>
using namespace std;

const int md = 1e9 + 7;
const int mx = 1e5 + 7;

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
};using mint = modint<md>; 

// change type 
mint invb, pw[mx];
void pre_hash_cal(long long B, int N=2){
    pw[0] = 1; // {1, 1};
    for(int i=1; i<N; ++i)
        pw[i] = (pw[i-1] * B);
    invb = pw[1].inv();
} 

template<long long B, class T> struct MyHash{
    int N; vector<T> HS; 
    inline T build(string &s){
        N = s.size(); 
        HS.resize(N+1); HS[0] = T();
        for(int i=1; i<=N; ++i)
            HS[i] = (HS[i-1] * B + s[i-1]);
        return HS[N];
    }
    inline T get_hash(){return HS[N];}
    inline vector<T> get_hash_list(){return HS;}
    inline T append(T cur, char c){return cur*B + c;}
    inline T prepend(T cur, int len, char c){return pw[c] * len + cur;}
    inline T replace(T cur, int idx, char a, char b){return cur + pw[idx] * (b - a);}
    inline T pop_back(T cur, char c){return (cur-c) * invb;}
    inline T pop_front(T cur, int len, char c){return cur - pw[len-1]*c;}
    inline T concat(T L, T R, int rLen){return L * pw[rLen] + R;}
    // inline T repeat(T cur, int len, ll cnt){
    //     T ans = (pw[len*cnt]-1) * (pw[len]-1).inv() * cur;
    //     if(pw[len].F == 1) ans.F = cur.F * cnt;
    //     if(pw[len].S == 1) ans.S = cur.S * cnt;
    //     return ans;
    // }
};using shash = MyHash<271, mint>;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);

    pre_hash_cal(mx);

    shash hs;
    string s; cin >> s;
    cout << hs.build(s).value << "\n";

    return 0;
}