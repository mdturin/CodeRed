#include <bits/stdc++.h>
using namespace std;
using ii = pair<int, int>;

#define ff first
#define se second

const int mx = 1e6 + 5;
const int inf = 0x3f3f3f3f;

vector<ii> g[mx];
int n, m, par[mx], dist[mx];

int dijkstra_algo(int s, int d){
    fill(dist, dist+mx, inf);
    memset(par, -1, sizeof par);

    priority_queue<ii> pq;
    pq.push({0, s}); dist[s] = 0;

    int u, v, uw, vw; while(pq.size()){
        tie(u, uw) = pq.top(); pq.pop(); uw = -uw;
        if(uw > dist[u]) continue;
        for(auto &p : g[u]){
            tie(v, vw) = p;
            if(dist[v] > dist[u] + vw){
                par[v] = u;
                dist[v] = dist[u] + vw;
                pq.push({-dist[v], v});
            }
        }
    }return dist[d];
}

void print_path(int s, int d){
    if(s == d) cout << s;
    else{
        print_path(s, par[d]);
        cout << ' ' << d;
    }
}

int main(int argc, const char** argv) {

    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    return 0;
}
