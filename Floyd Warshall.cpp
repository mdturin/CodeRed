#include "bits/stdc++.h"
using namespace std;

const int mod = 1e9 + 7;
const int mx  = 400;
const int INF = 1e9+9;

int V, E;
int u, v, w;
int par[mx][mx];
int graph[mx][mx];

void allClear(){
    for(int i=0; i<mx; i++){
        for(int j=0; j<mx; j++){
            par[i][j] = i;
            graph[i][j] = INF;
        }
        graph[i][i] = 0;
    }
}

void floydWarshall(){
    for(int k=0; k<V; k++)
    for(int i=0; i<V; i++)
    for(int j=0; j<V; j++){
        if(graph[i][j] > graph[i][k]+graph[k][j]){
            par[i][j] = par[k][j];
            graph[i][j] = graph[i][k] + graph[k][j];
        }
    }
}

void printPath(int u, int v){
    if(u == v) cout << u;
    else {
        printPath(u, par[u][v]);
        cout << " " << v;
    }
}

int main(){

    allClear();

    cin >> V >> E;
    while(E--){
        cin >> u >> v >> w;
        graph[u][v] = min(graph[u][v], w);
        graph[v][u] = min(graph[v][u], w);
    }

    floydWarshall();

    int q; cin >> q;
    while(q--){
        cin >> u >> v;
        cout << "Distance : " << graph[u][v] << '\n';
        cout << "Path :"; printPath(u, v);
        cout << "\n";
    }

    return 0;
}