#include<bits/stdc++.h>
using namespace std;
const int mx = 1e6 + 5;

int n, m;
int vis[mx];
vector<int> g[mx];

bool has_cyle(int u){
    vis[u] = 1;
    bool cycle = false;
    for(int &v : g[u]){
        if(vis[v] == 1) return true;
        if(vis[v] == 0)
            cycle |= has_cyle(v);
    }vis[u] = 2; return cycle;
}

bool has_cycle(){
    memset(vis, 0, n<<2);
    for(int i=0; i<n; ++i){
        if(vis[i]) continue;
        if(has_cyle(i))
            return true;
    }return false;
}

int main(){

    cin >> n >> m;
    while(m--){
        int u, v; 
        cin >> u >> v;
        --u; --v;
        g[u].push_back(v);
    }

    if(has_cycle())
        cout << "Has Cycle" << endl;
    else cout << "acyclic" << endl;

    return 0;
}