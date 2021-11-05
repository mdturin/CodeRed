#include <bits/stdc++.h>
using namespace std;
using ii = pair<int, int>;

#define ff first
#define se second

const int mx = 1e5 + 5;
const int inf = 0x3f3f3f3f;

template<int SZ> struct SCC{
    int N, comp[SZ];
    bitset<SZ> visit;
    vector<vector<int>> scc;
    vector<int> ts, allComp;
    vector<int> g[SZ], gr[SZ];
    
    void add(int a, int b){
        g[a].push_back(b); 
        gr[b].push_back(a);
    }
    
    void topo_dfs(int u){
        visit[u] = 1;
        for(int &v : g[u])
            if(!visit[v])
                topo_dfs(v);
        ts.push_back(u);
    }
    
    void scc_dfs(int u, int val){
        comp[u] = val;
        for(int &v : gr[u])
            if(comp[v] == -1)
                scc_dfs(v, val);
        scc.back().push_back(u);
    }
    
    void build(int _N){
        N = _N; scc.clear();
        for(int i=0; i<N; ++i)
            comp[i] = -1, visit[i] = 0;
        for(int i=0; i<N; ++i)
            if(!visit[i]) topo_dfs(i);
        reverse(ts.begin(), ts.end());
        for(int &i : ts) if(comp[i] == -1){
            scc.emplace_back();
            scc_dfs(i, i);
            allComp.push_back(i);
        }
    }

    vector<vector<int>> get_scc(){return move(scc);}
    bool is_same(int u, int v){return comp[u]==comp[v];}
};

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);

    int n, m;
    cin >> n >> m;

    SCC<10000> sol;
    int u, v; while(m--){
        cin >> u >> v; 
        --u; --v; sol.add(u, v);
    }
    
    sol.build(n);

    auto scc = sol.get_scc();
    for(auto &vec : scc){
        for(auto &it : vec)
            cout << (it+1) << " ";
        cout << endl;
    }

    return 0;
}
