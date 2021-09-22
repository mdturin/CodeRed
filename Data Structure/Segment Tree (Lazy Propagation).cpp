#include<bits/stdc++.h>
using namespace std;
using ll = long long;

const int mod = 1e9 + 7;
const int mx  = 1e6 + 5;

template<class T, class LT> struct SegTree{

    // Set null_val, push & merge function

    #define left   ((p)<<1)
    #define right (((p)<<1)|1)

    vector<T> t;
    vector<LT> lazy;

    static const T null_val = 0;                    // change this

    inline void push(int p, int l, int r){          // change this
        if (lazy[p] == 0) return;
        t[p] = t[p] + lazy[p] * (r - l + 1);
        if (l != r) {
            lazy[left] = lazy[left] + lazy[p];
            lazy[right] = lazy[right] + lazy[p];
        }lazy[p] = 0;
    }

    inline T merge(T a, T b){return a + b;}         // change this

    SegTree(int sz = 0) {
        t.resize(sz<<2, 0);
        lazy.resize(sz<<2, 0);
    }

    void upd(int p, int l, int r, int i, int j, T v){
        push(p, l, r);
        if (l > r || l > j || r < i) return;
        if (l >= i && r <= j) {
            lazy[p] = v; //set lazy
            push(p, l, r);
            return;
        }int m = (l + r) >> 1;
        upd(left, l, m, i, j, v);
        upd(right, m+1, r, i, j, v);
        t[p] = merge(t[left], t[right]);
    }

    T query(int p, int l, int r, int i, int j) {
        push(p, l, r);
        if (l > r || l > j || r < i) return null_val;
        if (l >= i && r <= j) return t[p];
        int m = (l + r) >> 1;
        T u = query(left, l, m, i, j);
        T v = query(right, m+1, r, i, j);
        t[p] = merge(t[left], t[right]);
        return merge(u, v);
    }
};

int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    SegTree<ll, ll> st(10);

    return 0;
}

