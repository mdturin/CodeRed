#include "bits/stdc++.h"
using namespace std;

const int mx = 1e5+5;
using pii = pair<int,int>;

int n, m, counter;
int root, child;

vector<pii> bridges;
vector<int> isPoint;
vector<int> adj[mx];
vector<int> low, vis, par;

void bfs(int u){
    low[u] = vis[u] = counter++;
    for(int &v:adj[u]){
        if(vis[v] && v!=par[u]) 
            low[u]=min(low[u],vis[v]);
        else if(!vis[v]){
            par[v] = u;
            if(u == root) 
                child++;
            
            bfs(v);
            if(low[v] >= vis[u]) isPoint[u]=1;
            if(low[v] >  vis[u]) 
                bridges.emplace_back(u,v);
            low[u] = min(low[u], low[v]);
        }
    }
}

void artucaltionPointsBridges(){
    counter = 1; bridges.clear();
    low = vector<int>(n, 0);
    vis = vector<int>(n, 0);
    par = vector<int>(n, -1);
    isPoint = vector<int>(n, 0);

    for(int i=0; i<n; i++){
        if(vis[i]) continue;
        root = i; child = 0; bfs(i);
        isPoint[i] = (child > 1);
    }

    for(int i=0; i<n; i++)
        if(isPoint[i])
            /// i is articulation point
    
    for(pii p:bridges){
        /// edge between p.first and p.second
        /// is articulation bridge
    }
}

int main(int argc, const char** argv) {

    return 0;
}