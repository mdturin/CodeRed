#include "bits/stdc++.h"
using namespace std;

#define ff first
#define se second
#define pb push_back 

using vi = vector<int>;
using pii = pair<int,int>;
using iii = pair<int,pii>;
using vii = vector<pii>;

vector<iii> pairs;
const int mx  = 200000;

/* UnionFind DS */
class UnionFind{
private:
    vi p, r, setSize;
    int numSets;
public:
    UnionFind(int n){
        numSets = n;
        r.assign(n, 0);
        p.assign(n, -1);
        setSize.assign(n, 1);
    }
    int findSet(int i){return (p[i]==-1)?i:p[i] = findSet(p[i]);}
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

/* Kruskal MST */
void Kruskal(){
    int V, E, ans=0; 
    cin >> V >> E;
    while(E--){
        int u, v, w;
        cin >> u >> v >> w;
        pairs.pb(iii(w, pii(u,v)));
    }
    sort(pairs.begin(), pairs.end());

    UnionFind uf(V);
    for(auto p:pairs){
        int w = p.first;
        int u = p.second.first;
        int v = p.second.second;
        if(!uf.isSameSet(u, v))
            ans += w, uf.unionSet(u, v);
    }
    cout << ans << "\n";
}

/** Prim MST **/
int n, e;
vi taken;
vii adj[mx];
priority_queue< pii, vii, greater<pii> > pq;

void process(int u){
    taken[u] = 1;
    for(auto v:adj[u])
        if(!taken[v.ff])
            pq.push({v.se, v.ff});
    return;
}

void prim(){
    cin >> n >> e;
    taken.assign(n, 0);
    for(int i=0; i<n; i++)
        adj[i].clear();
    while(e--){
        int u, v, w;
        cin >> u >> v >> w;
        adj[u].push_back({v, w});
        adj[v].push_back({u, w});
    }

    process(0); int ans = 0;
    while(pq.size()){
        pii p = pq.top(); pq.pop();
        int w=p.ff, u=p.se;
        if(!taken[u])
            ans+=w, process(u);
    }
    cout << ans << endl;
}

int main(int argc, const char** argv) {
    return 0;
}
