#include "bits/stdc++.h"
using namespace std;

#define pb push_back 
const int mx = 1e5+5;

int n, sz, BLK;
vector<int> blk;
vector<int> vis;
vector<int> first;
vector<int> euler;
vector<int> height;
vector<int> adj[mx];

// Pre-processing O(n)
// build O(n)
// Query O( sqrt(n) )

int query(int l, int r){
    int ans=euler[l], cl=l/BLK, cr=r/BLK;
    if(cl == cr){
        for(l++; l<=r; l++)
            if(height[euler[l]] < height[ans])
                ans = euler[l];
    }
    else{
        for(int i=l+1, j=(cl+1)*BLK; i<j; i++) 
            if(height[euler[i]] < height[ans])
                ans = euler[i];
        for(int i=cl+1; i<cr; i++)
            if(height[blk[i]] < height[ans])
                ans = blk[i];
        for(int i=cr*BLK; i<=r; i++)
            if(height[euler[i]] < height[ans])
                ans = euler[i];
    }
    return ans;
}

int lca(int u, int v){
    u = first[u]; v = first[v];
    if(u > v) swap(u, v);
    return query(u, v);
}

inline int solve(int l, int r){
    return height[l] < height[r] ? l : r;}

void build(){
    for(int i=0; i<sz; i++){
        if(i%BLK == 0) blk[i/BLK] = euler[i];
        else blk[i/BLK] = solve(blk[i/BLK], euler[i]);
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
    BLK = sqrt(sz)+1;
    blk = vector<int>(BLK,0);
    build();
}

void allClear(){
    blk.clear();
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