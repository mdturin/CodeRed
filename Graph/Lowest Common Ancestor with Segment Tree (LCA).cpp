#include "bits/stdc++.h"
using namespace std;

#define pb push_back 
const int mx = 1e5+5;

int n, sz;
vector<int> st;
vector<int> vis;
vector<int> first;
vector<int> euler;
vector<int> height;
vector<int> adj[mx];

// Pre-processing O(n)
// build O(n log n)
// Query O( log n )

int query(int p, int l, int r, int i, int j){
    if(l>j || r<i) return -1;
    if(l>=i && r<=j) return st[p];

    int mid = (l + (r-l)/2);
    int ansl = query(p<<1, l, mid, i, j);
    int ansr = query(p<<1|1, mid+1, r, i, j);
    if(ansl == -1) return ansr;
    if(ansr == -1) return ansl;
    return height[ansl] < height[ansr] ? ansl : ansr;
}

int lca(int u, int v){
    u = first[u]; v = first[v];
    if(u > v) swap(u, v);
    return query(1, 0, sz-1, u, v);
}

void merge(int p){
    int l = st[p<<1];
    int r = st[p<<1|1];
    st[p] = height[l] < height[r] ? l : r;
}

void build(int p, int l, int r){
    if(l == r) st[p] = euler[l];
    else{
        int mid = (l + (r-l)/2);
        build(p<<1, l, mid);
        build(p<<1|1, mid+1, r);
        merge(p);
    }
}

inline void add(int u, int h){
    vis[u] = 1;
    height[u] = h;
    first[u] = euler.size();
    euler.push_back(u);
}

void dfs(int u, int h=0){
    add(u, h);
    for(int &v : adj[u]){
        if(!vis[v]){
            dfs(v, h+1);
            euler.pb(u);
        }
    }
}

void init(int root = 0){
    euler.clear();
    first = vector<int>(n);
    vis = vector<int>(n, 0);
    height = vector<int>(n);

    dfs(root);
    sz = euler.size();
    st = vector<int>(sz<<2);
    build(1, 0, sz-1);
}

void allClear(){
    st.clear();
    vis.clear();
    first.clear();
    euler.clear();
    height.clear();
    for(int i=0; i<mx; i++)
        adj[i].clear();
}

int main(int argc, const char** argv) {

    allClear();

    n = 8;
    adj[1] = {2,3,4};
    adj[2] = {1,5,6};
    adj[3] = {1};
    adj[4] = {1,7};
    adj[5] = {2};
    adj[6] = {2};
    adj[7] = {4};

    init(1);

    for(int i=1; i<n; i++) cout << i << ' '; cout << "\n";
    for(int i=1; i<n; i++) cout << height[i] << ' '; cout << "\n";
    for(int i=1; i<n; i++) cout << first[i] << ' '; cout << "\n";
    for(int &u:euler) cout << u << ' '; cout << "\n";
    
    for(int i=1; i<n; i++)
    for(int j=1; j<n; j++)
        cout << i << ' '
             << j << ' '
             << lca(i, j) << '\n';

    return 0;
}