#include <bits/stdc++.h>
using namespace std;
using ii = pair<int, int>;

#define ff first
#define se second

const int mx = 1e6 + 5;
const int inf = 0x3f3f3f3f;

int n, m;
vector<ii> ed;
vector<int> g[mx];

vector<int> topo_sort(){
    vector<int> ts, ind(n);
    for(int i=0; i<m; ++i)
        ind[ed[i].second]++;

    queue<int> q;
    for(int i=0; i<n; ++i)
        if(ind[i] == 0)
            q.push(i); 
 
    int u, v; while(q.size()){
        u = q.front(); q.pop();
        ts.push_back(u);
        for(int &v : g[u])
            if(--ind[v] == 0)
                q.push(v);
    }

    if(ts.size() != n)
        ts.clear();
    
    for(int i=0; i<n; ++i)
        if(ind[i] != 0)
            return move(ts);
    
    return move(ts);
}

int main(int argc, const char** argv){

    ios_base::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);

    cin >> n >> m;

    int u, v; 
    for(int i=0; i<m; ++i){
        cin >> u >> v; --u; --v;
        g[u].push_back(v);
        ed.emplace_back(u, v);
    }

    vector<int> ts = topo_sort();
    if(ts.empty())
        cout << "IMPOSSIBLE" << endl;
    else{
        for(auto &u : ts)
            cout << (u+1) << " ";
        cout << endl;
    }

    return 0;
}