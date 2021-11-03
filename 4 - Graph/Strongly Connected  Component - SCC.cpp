#include <bits/stdc++.h>
using namespace std;
using ii = pair<int, int>;

#define ff first
#define se second

const int mx = 1e6 + 5;
const int inf = 0x3f3f3f3f;

int n, m;
vector<vector<int>> g, gr;

struct SCC{
    vector<vector<int>> scc;
    vector<int> col, vis, ts;

    void add(int u, int v){
        g[u].push_back(v);
        gr[v].push_back(u);
    }

    void topo_dfs(int u){
        vis[u] = 1;
        for(int &v : g[u])
            if(!vis[v]) 
                topo_dfs(v);
        ts.push_back(u);
    }

    void scc_dfs(int u){
        col[u] = scc.size();
        for(int &v : gr[u])
            if(col[v] == 0)
                scc_dfs(v);
        scc.back().push_back(u);
    }

    void build(int N){
        vis.assign(N, 0);
        col.assign(N, 0);

        ts.clear();
        for(int i=0; i<N; ++i)
            if(!vis[i]) topo_dfs(i);
        reverse(ts.begin(), ts.end());

        for(int &u : ts) {
            if(col[u]) continue;  
            scc.emplace_back();
            scc_dfs(u);
        }
    }

    vector<vector<int>> get_scc(){return move(scc);}
    bool is_same(int u, int v){return col[u]==col[v];}
};

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);

    cin >> n >> m;
    
    g.resize(n);
    gr.resize(n);

    SCC sol;
    int u, v; while(m--){
        cin >> u >> v; --u; --v;
        sol.add(u, v);
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
