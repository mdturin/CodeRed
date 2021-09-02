#include <bits/stdc++.h>
using namespace std;
using ii = pair<int, int>;

#define ff first
#define se second

const int mx = 405;
const int inf = 0x3f3f3f3f;

int n, m;
int g[mx][mx];
int par[mx][mx];

void all_clear(){
    for(int i=0; i<mx; i++){
        for(int j=0; j<mx; j++){
            g[i][j] = inf, par[i][j] = i;
        }graph[i][i] = 0;
    }
}

void floyd_warshall(){
    for(int k=0; k<n; k++)
    for(int i=0; i<n; i++)
    for(int j=0; j<n; j++){
        if(g[i][j] > g[i][k] + g[k][j]){
            par[i][j] = par[k][j];
            g[i][j] = g[i][k] + g[k][j];
        }
    }
}

void print_path(int u, int v){
    if(u == v) cout << u;
    else {
        print_path(u, par[u][v]);
        cout << " " << v;
    }
}

int main(){

    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    all_clear();

    cin >> n >> m; while(m--){
        cin >> u >> v >> w;
        graph[u][v] = min(graph[u][v], w);
        graph[v][u] = min(graph[v][u], w);
    }floyd_warshall();

    int q; cin >> q; while(q--){
        cin >> u >> v;
        cout << "Distance : " << graph[u][v] << '\n';
        cout << "Path :"; printPath(u, v);
        cout << "\n";
    }

    return 0;
}
