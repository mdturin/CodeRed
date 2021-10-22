#include <bits/stdc++.h>
using namespace std;
using ii = pair<int,int>;

#define ff first
#define se second

const int mx = 1e6 + 5;
const int inf = 0x3f3f3f3f;

vector<ii> g[mx];
int n, m, dist[mx];

void Bellman_Ford(int s){
    fill(dist, dist+mx, inf); dist[s] = 0;
    for(int step=1; step<n; step++)
    for(int u=0; u<n; u++) for(ii p : g[u]){
        int v, w; tie(v, w) = p;
        if(dist[v] > dist[u] + w)
            dist[v] = dist[u] + w;
    }

    for(int u=0; u<n; u++) for(ii p : g[u]){
        int v, w; tie(v, w) = p;
        if(dist[v] > dist[u] + w){}
            /// negative cycle found
            /// return true;
    }/// return false;
}

int main(int argc, const char** argv) {

    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int u, v, w; cin >> n >> m;
    while(m--){
        cin >> u >> v >> w;
        g[u].emplace_back(v, w);
    }

    int s; cin >> s;
    Bellman_Ford(s);

    return 0;
}
