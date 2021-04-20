#include "bits/stdc++.h"
using namespace std;

#define pb push_back 
using pii = pair<int,int>;
const int mx = 1e5 + 5;

class UnionFind{
private:
    int numSets;
    vector<int> p, r;
    vector<int> setSize;
    
public:
    UnionFind(int n=0){
        numSets = n;
        r.assign(n, 0);
        p.assign(n, -1);
        setSize.assign(n, 1);
    }
    int findSet(int i){return p[i]==-1?i:p[i] = findSet(p[i]);}
    bool isSameSet(int i, int j){return findSet(i) == findSet(j);}
    void unionSet(int i, int j){
        if(!isSameSet(i, j)){
            int x = findSet(i);
            int y = findSet(j);
            if(r[x] > r[y]){
                setSize[x] += setSize[y];
                p[y] = x;
            }
            else{
                setSize[y] += setSize[x];
                p[x] = y;
                if(r[x] == r[y])
                    r[y]++;
            }
            numSets--;
        }
    }
    int numDisJointSets(){return numSets;}
    int setSizeOf(int x){return setSize[findSet(x)];}
};

int n;
UnionFind uf;
map< pii, int > ans;
vector< int > adj[mx];
vector< int > vis, par;
vector< int > queries[mx];

pii fun(pii p){
    if(p.first > p.second) 
        swap(p.first, p.second); 
    return p;
}

void dfs(int u){
    vis[u] = 1; par[u] = u;
    for(int &v : adj[u]){
        if(!vis[v]){
            dfs(v);
            uf.unionSet(u, v);
            par[uf.findSet(u)] = u;
        }
    }

    for(int &v:queries[u])
        if(vis[v])
            ans[fun(pii(u,v))] = par[uf.findSet(v)];
}

int main(int argc, const char** argv) {

    n = 8;

    adj[1] = {2,3,4};
    adj[2] = {1,5,6};
    adj[3] = {1};
    adj[4] = {1,7};
    adj[5] = {2};
    adj[6] = {2};
    adj[7] = {4};

    int q = 0;
    vector<pii> pairs;
    for(int i=1; i<n; i++)
    for(int j=1; j<n; j++, q++){
        queries[i].pb(j);
        queries[j].pb(i);
        pairs.pb(pii(i, j));
    }

    ans.clear();
    uf = UnionFind(n);
    par = vector<int>(n);
    vis = vector<int>(n, 0);

    dfs(1);

    for(int i=0; i<q; i++)
        cout << pairs[i].first << ' '
             << pairs[i].second << ' '
             << ans[fun(pairs[i])] << '\n';

    return 0;
}