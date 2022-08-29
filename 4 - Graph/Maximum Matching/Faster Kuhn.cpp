#include<bits/stdc++.h>
using namespace std;

int n, k;
vector<int> pairs;
vector<bool> used;
vector<vector<int>> g;

bool try_kuhn(int u) {
    if (used[u]) return false; used[u] = true;
    for (int v : g[u]) {
        if (pairs[v] == -1 || try_kuhn(pairs[v])) {
            pairs[v] = u; return true;
        }
    }return false;
}

int main(){

    cin >> n >> k;
    g.assign(n, vector<int>());

    int edges, u, v; cin >> edges;
    while(edges--){
        cin >> u >> v; --u; --v;
        g[u].push_back(v);
    }

    used.assign(n, 0);
    pairs.assign(k, -1);

    for(int run=1; run;){
        run = 0;
        fill(used.begin(), used.end(), 0);
        for(int i=0; i<min(n,k); ++i)
            if(pairs[i]==-1 && try_kuhn(i))
                run = 1;
    }

    vector<pair<int,int>> res;
    for(int i=0; i<k; ++i)
        if(pairs[i] != -1)
            res.emplace_back(pairs[i], i);

    for(auto p : res)
        cout << (p.first+1) << " " << (p.second+1) << "\n";

    return 0;
}