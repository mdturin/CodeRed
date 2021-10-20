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

template <typename T, typename LT,
          const T null_val, const LT lazy_val,
          class F = function<T(const T, const T)>>
struct HLD{
private:
    #define L (p<<1)
    #define R (p<<1|1)

    int N, cp; F func;
    vector<int> heavy;
    vector<int> hei, head;
    vector<int> pos, rpos;
    SegTreeLazy<T, LT, null_val, lazy_val> st;

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
        for(int i=root; i<N; ++i)
            st.update(pos[i], pos[i], a[i]);
    }

    void update(int u, int v, T val){
        while(head[u] != head[v]){
            if(hei[head[u]] > hei[head[v]]) swap(u, v);
            st.update(pos[head[v]], pos[v], val);
            v = par[head[v]][0];
        }if(pos[u] > pos[v]) swap(u, v);
        st.update(pos[u], pos[v], val);
    }

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
    HLD<ll, ll, 0, 0> hld(n, cmp.fsum);
    hld.build(1);

    int ty, u, v, val;
    while(q--){
        cin >> ty;
        if(ty == 1){
            cin >> u >> v >> val;
            hld.update(u, v, val);
        }else{
            cin >> u >> v;
            cout << hld.query(u, v) << "\n";
        }
    }

    return 0;
}
