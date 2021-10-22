#include<bits/stdc++.h>
using namespace std;

const int mx = 2e5 + 5;

int n, m;
vector<int> g[mx];

vector<int> Centroid(){

    vector<int> ans, sz(n+1);

    function<void(int,int)> dfs = [&](int u, int p){
        sz[u] = 1;
        bool is_centroid = true;
        for(auto &v : g[u]){
            if(v == p) continue;
            dfs(v, u);
            sz[u] += sz[v];
            if(sz[v] > n/2)
                is_centroid = false;
        }if(n - sz[u] > n/2) 
            is_centroid = false;
        if(is_centroid) ans.push_back(u);
    };

    dfs(1, 0);
    return ans;
}

int main(){
    
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);

    cin >> n;
    for(int i=1; i<n; ++i){
        int u, v;
        cin >> u >> v;
        g[u].push_back(v);
        g[v].push_back(u);
    }

    vector<int> ans = Centroid();
    for(int &u : ans)
        cout << u << " ";
    cout << "\n";

    return 0;
}