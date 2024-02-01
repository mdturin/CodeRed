#include <bits/stdc++.h>
using namespace std;
using ii = pair<int,int>;

const int mx = 1e6 + 5;
const int inf = 0x3f3f3f3f;

#define ff first
#define se second

int n, m;
vector<int> g[mx];
int par[mx], dist[mx], vis[mx];

void bfs(int s){
    fill(dist, dist+mx, inf); dist[s] = 0;
    queue<int> q; q.push(s); par[s] = -1;
    while(q.size()){
        int u = q.front(); q.pop();
        for(int &v : g[u])
        if(dist[v] == inf){
            dist[v] = dist[u] + 1;
            vis[v] = 1; par[v] = u;
            q.push(v);
        }
    }
}

int main(int argc, const char** argv) {

    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    bfs(1);

    return 0;
}
