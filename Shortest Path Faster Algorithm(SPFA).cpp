#include "bits/stdc++.h"
using namespace std;

const int mx = 1e5+5;
const int INF = 1e9+9;
using pii = pair<int,int>;

vector<pii> adj[mx];
vector<int> dist, par, vis;

// Complexity Avg O(E), Worst O(VE);
void spfa(int s){
    fill(begin(vis), end(vis), 0);
    fill(begin(par), end(par), -1);
    fill(begin(dist), end(dist), INF);

    dist[s] = 0; vis[s] = 1;
    queue<int> q; q.push(s);

    while(q.size()){
        int u = q.front(); q.pop(); vis[u] = 0;
        for(pii &vp : adj[u]){
            int v = vp.first;
            int w = vp.second;
            if(dist[v] > dist[u]+w){
                par[v] = u;
                dist[v] = dist[u] + w;
                if(!vis[v]){
                    vis[v] = 1;
                    q.push(v);
                }
            }
        }
    }
}

int main(int argc, const char** argv) {
    return 0;
}