#include <bits/stdc++.h>
using namespace std;
using ii = pair<int, int>;

#define ff first
#define se second

const int mx = 1e6 + 5;
const int inf = 0x3f3f3f3f;

vector<ii> g[mx];
int dist[mx], par[mx], vis[mx];

void spfa(int s){
    fill(dist, dist+mx, inf);
    memset(vis, 0, sizeof vis);
    memset(par, -1, sizeof par);

    dist[s] = 0; vis[s] = 1;
    queue<int> q; q.push(s);

    int u, v, w; while(q.size()){
        u = q.front(); q.pop(); vis[u] = 0;
        for(ii &p : g[u]){
            tie(v, w) = p;
            if(dist[v] > dist[u] + w){
                par[v] = u;
                dist[v] = dist[u] + w;
                if(!vis[v]){
                    vis[v] = 1; q.push(v);}
            }
        }
    }
}

int main(int argc, const char** argv) {
    return 0;
}
