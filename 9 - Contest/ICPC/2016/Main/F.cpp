#include<bits/stdc++.h>
using namespace std;
const int mx = 1e6 + 5;

int mark[mx];
vector<int> prime, pos;

void LinearSieve(){
    for(int i=2, j=0; i<mx; i++, j=0){
        if(!mark[i]){mark[i] = i; prime.push_back(i);}
        while(j<(prime.size()) && prime[j]<=mark[i] && 1LL*i*prime[j]<mx)
            mark[i * prime[j]] = prime[j], j++;
    }

    pos.resize(mx, -1);
    for(int i=0; i<prime.size(); ++i)
        pos[prime[i]] = i;
}

int par[mx], depth[mx];
void init(int n){
    for(int i=0; i<n; ++i)
        par[i] = i, depth[i] = 1;
}

int find(int x){
    if(x == par[x]) return x;
    return par[x] = find(par[x]);
}

int unite(int x, int y){
    x = find(x); y = find(y);
    if(x == y) return 0;
    if(depth[x] >= depth[y])
        par[y] = x, depth[x] += depth[y];
    else par[x] = y, depth[y] += depth[x];
    return 1;
}

/**
2
3
2 3 4
6
2 3 4 5 6 6
*/

int main(){

    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    LinearSieve();
    int tc; cin >> tc;
    for(int cs=1; cs<=tc; cs++){
        int n; cin >> n;
        int u = prime.size();

        init(u + 2*n);
        int sz = 0, ed = 0;
        vector<int> cnt(u, 0);
        for(int i=0; i<n; ++i){
            int x; cin >> x; sz++;
            while(x > 1){
                int p = mark[x];
                int v = pos[p];
                if(cnt[v] == 0)
                    cnt[v] = 1, sz++;
                ed += unite(u, v);
                while(x % p == 0) x /= p;
            }u++;
        }

        cout << "Case " << cs << ": " << (sz-ed) << "\n";
    }

    return 0;
}

