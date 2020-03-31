#include "bits/stdc++.h"
using namespace std;

const int mx = 1e3+5;
const int INF = 1e9+9;
using pii = pair<int,int>;

#define ff first 
#define se second 

int n, m;
vector<int> par;
vector<int> dist;
vector<pii> adj[mx];

int dijk(int s, int d){
    par = vector<int>(n, -1);
    dist = vector<int>(n, INF);

    priority_queue<pii> pq;
    pq.push({0, s}); dist[s] = 0;

    while(pq.size()){
        pii p = pq.top(); pq.pop();
        int u = p.se, uw = p.ff;
        if(uw > dist[u]) continue;
        for(int i=0; i<adj[u].size(); i++){
            int v = adj[u][i].ff, ww = adj[u][i].se;
            if(dist[v]>dist[u]+ww){
                par[v] = u;
                dist[v] = dist[u]+ww;
                pq.push({-dist[v], v});
            }
        }
    }

    return dist[d];
}

void printPath(int s, int d){
    if(s == d) cout << s;
    else{
        printPath(s, par[d]);
        cout << ' ' << d;
    }
}

int main(int argc, const char** argv) {
    return 0;
}