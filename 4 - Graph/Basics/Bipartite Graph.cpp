#include <bits/stdc++.h>
using namespace std;
using ii = pair<int,int>;

const int mx = 1e6 + 5;
const int inf = 0x3f3f3f3f;

#define ff first
#define se second

vector<int> g[mx];
int n, m, color[mx];

bool dfs(int u, int c){
    color[u] = c;
    bool bi_partite = true;
    for(int v : g[u]){
        if(!color[v])
            bi_partite &= dfs(v, 3-c);
        else if(color[v] == c)
            return false;
    }return bi_partite;
}

bool Bipartite_Graph(){
    bool ok = true;
    memset(color, 0, sizeof color);
    for(int i=0; i<n; ++i)
        if(vis[i] == 0)
            ok &= dfs(i, 1);
    return ok;
}

int main(int argc, const char** argv) {

    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    return 0;
}
