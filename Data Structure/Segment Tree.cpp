#include<bits/stdc++.h>
using namespace std;

const int mod = 1e9 + 7;
const int mx  = 2e5 + 5;

// segment tree (1 - index)
struct STree{
private:
    // change according to problem
    struct node{
        int x;
        node(int _x=0):x(_x){}
    };

    int n; vector<int> a; vector<node> t;

    // merge of left and right node change according to problem
    node merge(node l, node r){
        node ans;
        ans.x = l.x + r.x;
        return ans;
    }

    void _b(int p, int l, int r){
        if(l == r) t[p] = node(a[l]);
        else{
            int m = (l + r)/2, cl = p<<1, cr = cl|1;
            _b(cl, l, m); _b(cr, m+1, r);
            t[p] = merge(t[cl], t[cr]);
        }
    }

    void _u(int p, int l, int r, int idx){
        if(l == r){t[p] = node(a[l]); return;}
        int m=(l+r)/2, cl=p<<1, cr=cl|1;
        if(idx <= m) _u(cl, l, m, idx);
        else _u(cr, m+1, r, idx);
        t[p] = merge(t[cl], t[cr]);
    }

    node _q(int p, int l, int r, int i, int j){
        if(l>r || l>j || r<i) return node();
        if(l>=i && r<=j) return t[p];
        int m=(l+r)/2, cl=p<<1, cr=cl|1;
        return merge(_q(cl, l, m, i, j),
                     _q(cr, m+1, r, i, j));
    }

public:
    STree(int _n):n(_n){t.resize(n << 2);}

    void build(int _a[]){
        a = vector<int>(_a, _a+n+1);
        _b(1, 1, n);
    }

    void build(vector<int> &_a){
        a = _a; _b(1, 1, n);
    }

    void update(int idx, int val){
        a[idx] = val;
        _u(1, 1, n, idx);
    }

    int query(int i, int j){
        return _q(1, 1, n, i, j).x;
    }
};

int main(){

    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int a[15], n = 10;
    for(int i=1; i<=n; i++)
        a[i] = i;

    STree t(n); t.build(a);
    for(int i=1; i<=n; i++){
        for(int j=i; j<=n; j++){
            cout << i << " " << j << " - ";
            cout << t.query(i, j) << "\n";
        }
    }

    t.update(5, -5);
    for(int i=1; i<=n; i++){
        for(int j=i; j<=n; j++){
            cout << i << " " << j << " - ";
            cout << t.query(i, j) << "\n";
        }
    }

    return 0;
}
