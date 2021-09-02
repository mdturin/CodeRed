#include <bits/stdc++.h>
using namespace std;
using ii = pair<int, int>;

#define ff first
#define se second

const int mx = 1e6 + 5;
const int inf = 0x3f3f3f3f;

vector<ii> g[mx];
int n, m, taken[mx];
priority_queue<ii, vector<ii>, greater<ii>> pq;

void process(int u){
    taken[u] = 1;
    for(auto v : g[u])
        if(!taken[v.ff])
            pq.push({v.se, v.ff});
}

void Prim(){
    cin >> n >> m;
    memset(taken, 0, sizeof taken);

    int u, v, w; while(m--){
        cin >> u >> v >> w;
        g[u].push_back({v, w});
        g[v].push_back({u, w});
    }

    process(0); int ans = 0;
    while(pq.size()){
        tie(w, u) = pq.top(); pq.pop();
        if(!taken[u]) ans += w, process(u);
    }cout << ans << endl;
}

int main(){

    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    Prim();

    return 0;
}

