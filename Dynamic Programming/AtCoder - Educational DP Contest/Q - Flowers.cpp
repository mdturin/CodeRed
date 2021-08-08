#include<bits/stdc++.h>
using namespace std;
using ll = long long;
using ii = pair<int,int>;

#define ff first
#define se second

const int md = 1e9+7;
const int mx = 1e6+5;

struct STree{
private:
    struct node{
        ll x;
        node(ll _x=0):x(_x){}
    };

    int n; vector<node> t;

    node merge(node l, node r){
        node ans;
        ans.x = max(l.x, r.x);
        return ans;
    }

    void _u(int p, int l, int r, int idx, ll val){
        if(l == r){t[p] = node(val); return;}
        int m=(l+r)/2, cl=p<<1, cr=cl|1;
        if(idx <= m) _u(cl, l, m, idx, val);
        else _u(cr, m+1, r, idx, val);
        t[p] = merge(t[cl], t[cr]);
    }

    node _q(int p, int l, int r, int i, int j){
        if(l>r || l>j || r<i) return node(0);
        if(l>=i && r<=j) return t[p];
        int m=(l+r)/2, cl=p<<1, cr=cl|1;
        return merge(_q(cl, l, m, i, j),
                     _q(cr, m+1, r, i, j));
    }

public:
    STree(int _n):n(_n){t.resize(n<<2, 0);}

    void update(int idx, ll val){
        _u(1, 1, n, idx, val);
    }

    ll query(int i, int j){
        return _q(1, 1, n, i, j).x;
    }
};

int n, a[mx], b[mx];

int main(){

    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n;
    for(int i=1; i<=n; i++) cin >> a[i];
    for(int i=1; i<=n; i++) cin >> b[i];

    ll ans = 0; STree st(n+1);
    for(int i=1; i<=n; i++){
        ll res = st.query(1, a[i]) + b[i];
        ans = max(ans, res);
        st.update(a[i], res);
    }cout << ans << "\n";

    return 0;
}

