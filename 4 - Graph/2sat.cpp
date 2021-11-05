#include <bits/stdc++.h>
using namespace std;
using ii = pair<int, int>;

#define ff first
#define se second

const int mx = 1e6 + 5;
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

template<int SZ> struct TwoSat{
    SCC<2*SZ> S;
    bitset<SZ> ans;
    int tmp[2*SZ], N;
    
    void OR(int x, int y){
        S.add(x^1, y); S.add(y^1, x);}
    void IMPLIES(int x, int y) {OR(x^1,y);}
    
    bool solve(int _N) {
        N = _N; S.build(2*N);
        for (int i = 0; i<2*N; i+=2) 
            if(S.comp[i] == S.comp[i^1]) 
                return false;

        vector<int> comp = S.allComp;
        reverse(comp.begin(), comp.end());
        for(int &i : comp) if(tmp[i] == 0)
            tmp[i] = 1, tmp[S.comp[i^1]] = -1;

        for(int i=0; i<N; ++i)
            if(tmp[S.comp[2*i]] == 1) 
                ans[i] = 1;

        return true;
    }
};

TwoSat<100001> st;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);

    int n, m; 
    cin >> n >> m;

    char a, c; int b, d;
    for(int i=0; i<n; ++i){
        cin >> a >> b >> c >> d; --b; --d;
        st.OR(2 * b + (a == '-'), 2 * d + (c == '-'));
    }

    if(!st.solve(m))
        cout << "IMPOSSIBLE\n";
    else{
        for(int i=0; i<m; ++i)
            cout << (st.ans[i]?'+':'-') << ' ';
        cout << "\n";
    }

    return 0;
}
