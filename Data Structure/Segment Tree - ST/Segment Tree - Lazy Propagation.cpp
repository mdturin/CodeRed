// author - md turin
// created - 20.10.21

#include<bits/stdc++.h>
using namespace std;
using ll = long long;

const int mod = 1e9 + 7;
const int mx  = 1e6 + 5;

// Change push function
template<typename T, typename LT,
         const T null_val, const LT lazy_val,
         class F = function<T(const T, const T)>>
struct SegTreeLazy{
private:
    #define L (p<<1)
    #define R (p<<1|1)

    vector<T> t;
    vector<LT> lz;
    int N; F func;

    inline void push(int p, int l, int r){
        if (lz[p] == lazy_val) return;
        t[p] = t[p] + lz[p] * (r - l + 1);
        if (l != r) {
            lz[L] = lz[L] + lz[p];
            lz[R] = lz[R] + lz[p];
        }lz[p] = lazy_val;
    }

    void upd(int p, int l, int r, int i, int j, T v){
        push(p, l, r);
        if(l>r || l>j || r<i) return;
        if(l>=i && r<=j){
            lz[p]=v; push(p, l, r); return;}
        int m = (l + r) >> 1;
        upd(L, l, m, i, j, v);
        upd(R, m+1, r, i, j, v);
        t[p] = func(t[L], t[R]);
    }

    T qry(int p, int l, int r, int i, int j){
        push(p, l, r);
        if (l>r || l>j || r<i) return null_val;
        if (l>=i && r<=j) return t[p];
        int m = (l + r) >> 1;
        T u = qry(L, l, m, i, j);
        T v = qry(R, m+1, r, i, j);
        t[p] = func(t[L], t[R]);
        return func(u, v);
    }

public:
    SegTreeLazy(int sz, F f) : N(sz+1), func(f){
        t.resize(N<<2, null_val);
        lz.resize(N<<2, lazy_val);
    }
    T query(int i, int j){return qry(1, 0, N, i, j);}
    void update(int i, int j, T x){upd(1, 0, N, i, j, x);}
};

template<typename T> struct get_cmp{
    function<T(const T, const T)> fsum = [&](const T u, const T v){return u + v;};
    function<T(const T, const T)> fmax = [&](const T u, const T v){return max(u, v);};
    function<T(const T, const T)> fmin = [&](const T u, const T v){return min(u, v);};
    function<T(const T, const T)> fgcd = [&](const T u, const T v){return __gcd(u, v);};
};get_cmp<int> cmp;

int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    // SegTreeLazy<int, int, 0, 0> st(10, [&](int u, int v){
    //     return u + v;
    // });

    SegTreeLazy<int, int, 0, 0> st(10, cmp.fsum);

    st.update(0, 5, 2);
    st.update(3, 7, 3);
    st.update(7, 9, 1);

    for(int i=0; i<10; ++i)
        cout << i << " " << st.query(i, i) << "\n";

    return 0;
}

