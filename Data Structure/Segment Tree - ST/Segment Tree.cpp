// author - md turin
// created - 20.10.21

#include<bits/stdc++.h>
using namespace std;

const int mod = 1e9 + 7;
const int mx  = 2e5 + 5;

template <typename T, const T null_val, class F = function<T(const T, const T)>>
struct SegTree{
private:
    #define L (p<<1)
    #define R (p<<1|1)

    int N; F func; vector<T> t;

    void upd(int p, int l, int r, int i, T x){
        if(l>r || l>i || r<i) return;
        if(l == r){t[p] = x; return;}
        int m = (l + r) >> 1;
        upd(L, l, m, i, x);
        upd(R, m+1, r, i, x);
        t[p] = func(t[L], t[R]);
    }

    T qry(int p, int l, int r, int i, int j){
        if (l>r || l>j || r<i) return null_val;
        if (l>=i && r<=j) return t[p];
        int m = (l + r) >> 1;
        T u = qry(L, l, m, i, j);
        T v = qry(R, m+1, r, i, j);
        return func(u, v);
    }

public:
    SegTree(int sz, F f) : N(sz+1), func(f){
        t.resize(N<<2, null_val);}
    void update(int i, T x){upd(1, 0, N, i, x);}
    T query(int i, int j){return qry(1, 0, N, i, j);}
};

template<typename T> struct get_cmp{
    function<T(const T, const T)> fsum = [&](const T u, const T v){return u + v;};
    function<T(const T, const T)> fmax = [&](const T u, const T v){return max(u, v);};
    function<T(const T, const T)> fmin = [&](const T u, const T v){return min(u, v);};
    function<T(const T, const T)> fgcd = [&](const T u, const T v){return __gcd(u, v);};
};get_cmp<int> cmp;

int main(){

    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    // SegTree<int, 0> st(10, [&](int u, int v){
    //     return u + v;
    // });

    SegTree<int, 0> st(10, cmp.fsum);
    for(int i=0; i<10; ++i) st.update(i, i+10);
    for(int i=3; i<10; ++i)
        cout << st.query(i-3, i) << endl;

    return 0;
}
