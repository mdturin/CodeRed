#include<bits/stdc++.h>
using namespace std;

const int mod = 1e9 + 7;
const int mx  = 2e5 + 5;

template<class T> struct SegTree{

    // Set null_val and merge function

    #define left   ((p)<<1)
    #define right (((p)<<1)|1)

    vector<T> t;
    static const T null_val = -1e9;         // change this
    T merge(T u, T v){return max(u, v);}    // change this

    SegTree(int sz=0){t.resize(sz<<2, 0);}

    void upd(int p, int l, int r, int i, T x){
        if (l > i || r < i) return;
        if (l == r && l == i){t[p] = x; return;}
        int m = (l + r) >> 1;
        upd(left, l, m, i, x);
        upd(right, m+1, r, i, x);
        t[p] = merge(t[left], t[right]);
    }

    T query(int p, int l, int r, int i, int j){
        if (l>r || l>j || r<i) return null_val;
        if (l>=i && r<=j) return t[p];
        int m = (l + r) >> 1;
        T u = query(left, l, m, i, j);
        T v = query(right, m+1, r, i, j);
        return merge(u, v);
    }
};

int main(){

    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    SegTree<int> st(10);

    return 0;
}
