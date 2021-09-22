#include <bits/stdc++.h>
using namespace std;
using ii = pair<int, int>;

#define ff first
#define se second

const int mx = 1e6 + 5;
const int inf = 0x3f3f3f3f;

/* UnionFind DS */
class UnionFind{
private:
    int numSets;
    vector<int> p, r;
    vector<int> setSize;

public:
    UnionFind(int n){
        numSets = n;
        r.assign(n, 0);
        p.assign(n, -1);
        setSize.assign(n, 1);
    }
    void init(int n){
        numSets = n;
        r.resize(n, 0);
        p.assign(n, -1);
        setSize.resize(n, 1);
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

inline void Kruskal(){
    int n, m, u, v, w, ans = 0;
    vector<pair<int, ii>> pairs;
    cin >> n >> m; while(m--){
        cin >> u >> v >> w;
        pairs.push_back({w, {u, v}});
    }sort(pairs.begin(), pairs.end());

    UnionFind uf(n); ii p2;
    for(auto p : pairs){
        tie(w, p2) = p; tie(u, v) = p2;
        if(!uf.isSameSet(u, v))
            ans += w, uf.unionSet(u, v);
    }cout << ans << "\n";
}

int main(){

    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    Kruskal();

    return 0;
}
