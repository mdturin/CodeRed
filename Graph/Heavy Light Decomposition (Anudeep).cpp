
// Source : Anudeep's Blog
// Link : https://blog.anudeep2011.com/heavy-light-decomposition/

#include <cstdio>
#include <vector>
#include <cstring>
using namespace std;

const int mx=1e5+5;
const int lgn = 17;
const int INF = 1e9+9;

using pii = pair<int,int>;
using iii = pair<int,pii>;

#define ff first 
#define se second
#define pb push_back 

int n, cp, ptr;
int st[mx*3 + 10];
vector<pii> adj[mx];

int subsz[mx], ind[mx];
int height[mx], par[mx][lgn];
int wt[mx], head[mx], pos[mx];

void build(int p, int l, int r){
    if(l == r) st[p] = wt[l];
    else{
        int mid = (l + r) / 2;
        build(p<<1, l, mid);
        build(p<<1|1, mid+1, r);
        st[p] = max(st[p<<1], st[p<<1|1]);
    }
}

void update(int p, int l, int r, int idx, int v){
    if(l == r) {st[p] = v; return;}
    int mid = (l + r) / 2;
    if(idx <= mid)
        update(p<<1, l, mid, idx, v);
    else update(p<<1|1, mid+1, r, idx, v);
    st[p] = max(st[p<<1], st[p<<1|1]);
}

void update(int u, int val){
    update(1, 0, ptr-1, pos[u], val);}

int query(int p, int l, int r, int i, int j){
    if(l>j || r<i) return -INF;
    if(l>=i && r<=j) return st[p];
    int mid = (l + r) / 2;
    return max(
        query(p<<1, l, mid, i, j),
        query(p<<1|1, mid+1, r, i, j)
    );
}

int queryUp(int u, int v){ // v = lca;
    if(u == v) return 0;
    int vc = ind[v], ans=-1;
    while( 1 ){
        int uc = ind[u];
        if(uc == vc) break;
        ans = max(ans, query(1, 0, ptr-1, pos[head[uc]], pos[u]));
        u = par[head[uc]][0];
    }
    if(u == v) return ans;
    ans = max(ans, query(1, 0, ptr-1, pos[v]+1, pos[u]));
    return ans;
}

int queryLCA(int u, int v){
    if(height[u] < height[v]) swap(u, v);
    for(int i=lgn-1; i>=0; i--)
        if(height[u]-(1<<i) >= height[v])
            u = par[u][i];
    if(u == v) return u;
    for(int i=lgn-1; i>=0; i--)
        if(~par[u][i] && par[u][i]!=par[v][i])
            u=par[u][i], v=par[v][i];
    return par[u][0];
}

int query(int u, int v){
    int lca = queryLCA(u, v);
    int ans = queryUp(u, lca);
    ans = max(ans, queryUp(v, lca));
    return ans;
}

void dfs(int u, int p, int h){
    par[u][0] = p; height[u] = h; subsz[u] = 1;
    for(pii &v : adj[u]){
        if(v.ff == p) continue;
        dfs(v.ff, u, h+1);
        subsz[u] += subsz[v.ff];
    }
}

void hld(int u, int p, int w){
    if(~head[cp]) head[cp] = u;
    ind[u] = cp; pos[u] = ptr; wt[ptr++] = w;

    int sc = -1, cost;
    for(pii &v : adj[u])
        if(sc==-1 || subsz[sc]<subsz[v.ff])
            sc = v.ff, cost = v.se;
    if(sc != -1) hld(sc, u, cost);
    
    for(pii &v : adj[u])
        if(sc != v.ff && v.ff != p)
            cp++, hld(v.ff, u, v.se);
}

void init(int root = 0){
    // setting necessary defaults
    cp = 0; ptr = 0;
    memset(par, -1, sizeof par);
    memset(head, -1, sizeof head);

    dfs(root, -1, 0);       // gathering info
    hld(root, -1, -1);      // making hld
    build(1, 0, ptr-1);      // building segment tree

    // Binary Lifting
    for(int j=1; j<lgn; j++)
    for(int i=0; i<n; i++){
        int p = par[i][j-1];
        if( p != -1 )
            par[i][j] = par[p][j-1];
    }
}

int main(int argc, const char** argv) {init(); return 0;}