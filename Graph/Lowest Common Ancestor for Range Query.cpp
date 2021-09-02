// Example of SPOJ : DISQUERY

#include <bits/stdc++.h>
using namespace std;
using vi = vector<int>;
using ii = pair<int, int>;

#define ff first
#define se second
#define pb push_back

const int mx = 1e6 + 5;
const int lgn = __lg(mx)+1;

vector<ii> g[mx];
int par[mx][lgn];
int Max[mx][lgn];
int Min[mx][lgn];
int n, m, height[mx];

int ansMax, ansMin;
void query(int u, int v){
    ansMax = INT_MIN; ansMin = INT_MAX;
    if(height[u] < height[v]) swap(u, v);

    for(int i=lgn-1; i>=0; i--)
    if(height[u] - (1<<i) >= height[v]){
        ansMax = max(ansMax, Max[u][i]);
        ansMin = min(ansMin, Min[u][i]);
        u = par[u][i];
    }if(u == v) return;

    for(int i=lgn-1; i>=0; i--)
    if(~par[u][i] && par[u][i]!=par[v][i]){
        ansMax = max({ansMax, Max[u][i], Max[v][i]});
        ansMin = min({ansMin, Min[u][i], Min[v][i]});
        u = par[u][i]; v = par[v][i];
    }

    ansMax = max({ansMax, Max[u][0], Max[v][0]});
    ansMin = min({ansMin, Min[u][0], Min[v][0]});
}

void dfs(int u, int p, int h, int d){
    Max[u][0] = Min[u][0] = d;
    par[u][0] = p; height[u] = h;
    for(ii &v : g[u]) if(v.ff != p)
        dfs(v.ff, u, h+1, v.se);
}

void init(){
    for(int i=0; i<n; ++i){
        fill(Max[i], Max[i]+lgn, INT_MIN);
        fill(Min[i], Min[i]+lgn, INT_MAX);
    }dfs(0, -1, 0, 0);

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

    while(cin >> n){
        for(int i=1; i<n; ++i){
            cin >> u >> v >> w; u--; v--;
            g[u].push_back(ii(v, w));
            g[v].push_back(ii(u, w));
        }

        init();

        int q; cin >> q;
        while(q--){
            cin >> u >> v;
            u--; v--; query(u, v);
            cout << ansMin << ' ' << ansMax << '\n';
        }

        for(int i=0; i<n; i++) g[i].clear();
    }

    return 0;
}
