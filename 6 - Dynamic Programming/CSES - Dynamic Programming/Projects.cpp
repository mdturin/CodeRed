#include<bits/stdc++.h>
using namespace std;
using ll = long long;
using T = tuple<int,int,int>;

const int md = 1e9+7;
const int mx = 4e5+5;

ll tree[mx];

inline int lsb(int x){return x & (-x);}

inline void add(int idx, ll x){
    while(idx < mx){
        tree[idx] = max(tree[idx], x);
        idx += lsb(idx);
    }
}

inline ll query(int idx){
    ll ans = 0;
    while(idx > 0){
        ans = max(ans, tree[idx]);
        idx -= lsb(idx);
    }return ans;
}

vector<int> t(1, 0);
inline T read(){
    int x, y, z;
    cin >> x >> y >> z;
    t.push_back(x);
    t.push_back(y);
    return make_tuple(x, y, z);
}

int main(){

    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n; cin >> n;

    vector<T> v(n);
    for(int i=0; i<n; ++i)
        v[i] = read();

    int x, y, z;
    sort(t.begin(), t.end());
    t.resize(unique(t.begin(), t.end()) - t.begin());
    for(int i=0; i<n; ++i){
        tie(x, y, z) = v[i];
        x = lower_bound(t.begin(), t.end(), x) - t.begin();
        y = lower_bound(t.begin(), t.end(), y) - t.begin();
        v[i] = make_tuple(x, y, z);
    }

    sort(v.begin(), v.end());
    for(T it : v){
        tie(x, y, z) = it;
        ll cur = query(x-1);
        add(y, cur + z);
    }

    cout << *max_element(tree, tree+mx) << "\n";

    return 0;
}
