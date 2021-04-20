#include "bits/stdc++.h"
using namespace std;

#define ff first 
#define se second 
using pii = pair<int,int>;

int n, m;
const int mx = 1e5+5;

vector<int> vis;
vector<pii> adj[mx];

bool biPartiteGraph(int s){
    queue<int> q; q.push(s);
    vis.assign(n, 0); vis[s] = 1;
    bool isBipart = true;
    while(q.size() && isBipart){
        int u = q.front(); q.pop();
        for(int i=0; i<adj[u].size(); i++){
            int v = adj[u][i].ff;
            if(!vis[v]){
                vis[v] = 3 - vis[u]; /// if 1 then assing 2, or vice versa
                q.push(v);
            }
            else if(vis[v] == vis[u]){
                isBipart = 0;
                break;
            }
        }
    }
    return isBipart;
}

int main(int argc, const char** argv) {
    return 0;
}
