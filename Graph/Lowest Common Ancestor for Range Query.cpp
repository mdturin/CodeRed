/*
    Example of SPOJ : DISQUERY
*/

#include <bits/stdc++.h>
using namespace std;

#define pb push_back
const int mx = 1e5+5;
using vi = vector<int>;
using pii = pair<int,int>;

int n, m, lgn;
vector< int > height;
vector< pii > adj[mx];
vector< vi > par, Max, Min;

int ansMax, ansMin;
void query(int u, int v){
    ansMax = INT_MIN; ansMin = INT_MAX;
    if(height[u] < height[v]) swap(u, v);

    for(int i=lgn-1; i>=0; i--)
    if(height[u] - (1<<i) >= height[v]){
        ansMax = max(ansMax, Max[u][i]);
        ansMin = min(ansMin, Min[u][i]);
        u = par[u][i];
    }

    if(u == v) return;
    for(int i=lgn-1; i>=0; i--)
    if(par[u][i] != -1 && par[u][i]!=par[v][i]){
        ansMax = max({ansMax, Max[u][i], Max[v][i]});
        ansMin = min({ansMin, Min[u][i], Min[v][i]});
        u = par[u][i]; v = par[v][i];
    }

    ansMax = max({ansMax, Max[u][0], Max[v][0]});
    ansMin = min({ansMin, Min[u][0], Min[v][0]});
}

void dfs(int u, int p, int h, int d){
    par[u][0] = p; height[u] = h;
    Max[u][0] = Min[u][0] = d;
    for(pii &v : adj[u])
        if(v.first != p)
            dfs(v.first, u, h+1, v.second);
}

void init(){
    lgn = log2(n) + 1; 
    height = vector<int>(n);
    par = vector< vi >(n, vi(lgn, -1));
    Max = vector< vi >(n, vi(lgn, INT_MIN));
    Min = vector< vi >(n, vi(lgn, INT_MAX));

    dfs(0, -1, 0, 0);

    for(int j=1; j<lgn; j++)
    for(int i=0; i<n; i++)
    if(par[i][j-1] != -1){
        int p = par[i][j-1];
        par[i][j] = par[p][j-1];
        Max[i][j] = max(Max[i][j-1], Max[p][j-1]);
        Min[i][j] = min(Min[i][j-1], Min[p][j-1]);
    }
}

int main(int argc, const char** argv) {

    ios_base::sync_with_stdio(0);
    cin.tie(nullptr);

    int u, v, w;

    while(cin >> n){ m = n-1;
        while(m--){
            cin >> u >> v >> w; u--; v--;
            adj[u].push_back(pii(v, w));
            adj[v].push_back(pii(u, w));
        }

        init();

        int q; cin >> q;
        while(q--){
            cin >> u >> v;
            u--; v--; query(u, v);
            cout << ansMin << ' ' << ansMax << '\n';
        }

        for(int i=0; i<n; i++) adj[i].clear();
    }

    return 0;
}