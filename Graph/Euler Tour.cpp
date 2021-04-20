#include "bits/stdc++.h"
using namespace std;

#define pb push_back 
const int mx = 1e5+5;

int n;
vector<int> vis;
vector<int> euler;
vector<int> adj[mx];

void dfs(int u){
    vis[u] = 1;
    euler.pb(u);
    for(int &v:adj[u]){
        if(!vis[v]){
            dfs(v);
            euler.pb(u);
        }
    }
}

void print(){
    for(int &u:euler)
        cout << u << ' ';
    cout << "\n\n";
}

void buildEuler(int root = 0){
    euler.clear();
    vis = vector<int>(n+n+5, 0);
    dfs(root);
}

inline void addEdge(int u, int v){
    adj[u].pb(v);
    adj[v].pb(u);
}

int main(int argc, const char** argv) {
    n = 4; 
    
    addEdge(1,2);
    addEdge(2,3);
    addEdge(2,4);

    buildEuler(1);

    print();

    return 0;
}