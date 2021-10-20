#include<bits/stdc++.h>
using namespace std;
using ll = long long;
using ii = pair<int, int>;

const int mx = 2e5 + 5;
const int lgmx = __lg(mx) + 1;

#define ff first
#define se second
#define pb push_back

int n, a[mx];
int par[mx][lgmx];
vector<int> g[mx];

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
        if(i <= m)
            upd(L, l, m, i, x);
        else upd(R, m+1, r, i, x);
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

template <typename T, const T null_val, class F = function<T(const T, const T)>>
struct HLD{
private:
    #define L (p<<1)
    #define R (p<<1|1)

    int N, cp; F func;
    vector<int> heavy;
    vector<int> hei, head;
    vector<int> pos, rpos;
    SegTree<T, null_val> st;

    int dfs(int u, int p, int h){
        int sz = 1, msz = 0, vsz;
        hei[u] = h; par[u][0] = p;
        for(auto &v : g[u]){
            if(v == p) continue;
            sz += (vsz = dfs(v, u, h+1));
            if(msz<vsz) msz=vsz, heavy[u]=v;
        }return sz;
    }

    void decom(int u, int p){
        head[u] = p; pos[u] = cp; rpos[cp++] = u;
        if(~heavy[u]) decom(heavy[u], p);
        for(auto &v : g[u])
            if(v != par[u][0] && v != heavy[u])
                decom(v, v);
    }

public:
    HLD(int sz, F f) :
        N(sz+1), func(f), cp(0), st(N,f){
        heavy.resize(N, -1);
        pos.resize(N); rpos.resize(N);
        hei.resize(N); head.resize(N);
        for(int i=0; i<N; ++i)
            memset(par[i], -1, sizeof par[i]);
    }

    void build(int root=1){
        dfs(root, -1, 0);
        decom(root, root);
        for(int i=1; i<N; ++i)
            st.update(pos[i], a[i]);
    }

    void update(int u, T val){
        return st.update(pos[u], val);}

    T query(int u, int v){
        T ans = null_val;
        while(head[u] != head[v]){
            if(hei[head[u]] > hei[head[v]]) swap(u, v);
            ans = func(ans, st.query(pos[head[v]], pos[v]));
            v = par[head[v]][0];
        }if(pos[u] > pos[v]) swap(u, v);
        return func(ans, st.query(pos[u], pos[v]));
    }
};

template<typename T> struct get_cmp{
    function<T(const T, const T)> fsum = [&](const T u, const T v){return u + v;};
    function<T(const T, const T)> fmax = [&](const T u, const T v){return max(u, v);};
    function<T(const T, const T)> fmin = [&](const T u, const T v){return min(u, v);};
    function<T(const T, const T)> fgcd = [&](const T u, const T v){return __gcd(u, v);};
};

int main(int argc, const char** argv) {

    ios_base::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);

    int n, q; cin >> n >> q;
    for(int i=1; i<=n; ++i) cin >> a[i];
    for(int i=1; i<n; ++i){
        int u, v;
        cin >> u >> v;
        g[u].push_back(v);
        g[v].push_back(u);
    }

    get_cmp<ll> cmp;
    HLD<ll, 0> hld(n, cmp.fsum);
    hld.build(1);

    int ty, u, v, val;
    while(q--){
        cin >> ty;
        if(ty == 1){
            cin >> u >> val;
            hld.update(u, val);
        }else{
            cin >> u >> v;
            cout << hld.query(u, v) << "\n";
        }
    }

    return 0;
}
