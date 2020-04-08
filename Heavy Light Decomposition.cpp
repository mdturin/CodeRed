// ACCEPTED
// Finding Max
// Example : QTREE

#include <cstdio>
#include <vector>
#include <utility>
#include <cstring>
#include <limits.h>
#include <algorithm>
using namespace std;

const int mx=10005;
using pii = pair<int,int>;
using iii = pair<int,pii>;

#define ff first 
#define se second
#define pb push_back 

int n, cp;
pii edges[mx];
vector<pii> adj[mx];
int height[mx], rpos[mx], heavy[mx], a[mx];
int par[mx], head[mx], pos[mx], st[3*mx+10];

void build(int p, int l, int r){
    if(l == r) st[p] = a[rpos[l]];
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

int query(int p, int l, int r, int i, int j){
    if(l>j || r<i) return INT_MIN;
    if(l>=i && r<=j) return st[p];
    int mid = (l + r) / 2;
    return max(
        query(p<<1, l, mid, i, j),
        query(p<<1|1, mid+1, r, i, j)
    );
}

// Heavy-Light Decompostion Query 
int query(int u, int v){
    if(u == v) return 0;
    int ans = INT_MIN;
    while(head[u] != head[v]){
        if(height[head[u]] > height[head[v]]) swap(u, v);
        ans = max(ans, query(1, 0, n, pos[head[v]], pos[v]));
        v = par[head[v]];
    }
    if(u == v) return ans;
    if(pos[u] > pos[v]) swap(u, v);
    ans = max(ans, query(1, 0, n, pos[u]+1, pos[v]));
    return ans;
}


// Heavy-Light Decompostion Part
int dfs(int u, int p, int h, int d){
    int sz=1, msz=0, vsz;
    height[u]=h; par[u]=p; a[u]=d;
    for(pii &v : adj[u]){
        if(v.ff == p) continue;
        sz += (vsz = dfs(v.ff, u, h+1, v.se));
        if(msz < vsz) msz = vsz, heavy[u] = v.ff;
    }
    return sz;
}

void decom(int u, int p){
    head[u] = p; pos[u] = cp; rpos[cp++] = u;
    if(~heavy[u]) decom(heavy[u], p);
    for(pii &v : adj[u])
        if(v.ff != par[u] && v.ff != heavy[u])
            decom(v.ff, v.ff);
}

int main(int argc, const char** argv) {

    char s[20];
    int u, v, w;
    
    int tc; scanf("%d", &tc);
    while(tc--){
        scanf("%d", &n);
        for(int i=1; i<n; i++){
            scanf("%d %d %d", &u, &v, &w);
            adj[u].pb({v, w});
            adj[v].pb({u, w});
            edges[i] = {u, v};
        }

        memset(heavy, -1, sizeof(heavy));
        cp = 0; dfs(1, 0, 0, 0); decom(1, 1);

        build(1, 0, n);

        while(scanf("%s", s), s[0] != 'D'){
            scanf("%d %d", &u, &v);
            if(s[0] == 'Q')
                printf("%d\n", query(u,v));
            else{
                int l = edges[u].ff;
                int r = edges[u].se;
                if(l == par[r])
                    update(1, 0, n, pos[r], v);
                else update(1, 0, n, pos[l], v);
            }
        }

        for(int i=0; i<=n; i++) adj[i].clear();
    }
    return 0;
}