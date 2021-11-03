#include<bits/stdc++.h>
using namespace std;
const int mx = 2e6 + 5;

int n, m;
vector<int> g[mx];

struct find_cycle{
    int cs, ce; bool cycle;
    vector<int> col, par, cyc;

    find_cycle(int n = 1):
        cycle(false), cs(-1), ce(-1), col(n), par(n,-1){

        for(int i=0; i<n; ++i)
            if(col[i]==0 && dfs(i))
                break;
        
        if(!cycle) return;

        cyc.push_back(cs);
        for(int c=ce; c!=cs; c=par[c])
            cyc.push_back(c);
        reverse(cyc.begin(), cyc.end());
    }

    bool dfs(int u, int p=-1){
        col[u] = 1; par[u] = p;
        for(int &v : g[u]){
            if(col[v] == 0 && dfs(v, u))
                return true;
            if(col[v] == 1){
                cycle = true;
                ce = u; cs = v;
                return true;
            }
        }col[u] = 0; return false;
    }

    bool has_cycle(){return cycle;}
    vector<int> cycle_path(){return move(cyc);}
};

int main(){
    
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);

    cin >> n >> m;
    int u, v; while(m--){
        cin >> u >> v; --u; --v;
        g[u].push_back(v);
        // g[v].push_back(u);
    }

    find_cycle sol(n);
    if(sol.has_cycle()){
        vector<int> path = sol.cycle_path();
        for(int u : path)
            cout << (u+1) << " ";
    }else cout << "no cycle\n";

    return 0;
}