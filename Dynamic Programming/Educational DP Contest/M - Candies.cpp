#include<bits/stdc++.h>
using namespace std;
using ll = long long;
using ii = pair<int,int>;

#define ff first
#define se second

const int md = 1e9+7;
const int mx = 1e6+5;

template<typename T> class Bit{
private:
    size_t n; vector<T> b;

    inline int lsb(int x){
        return (x & -x);}

    T sum(int i){
        T res = 0;
        while(i > 0){
            res += b[i];
            res %= md;
            i -= lsb(i);
        }return res;
    }

public:
    Bit(size_t _n):n(_n+1){
        b.resize(n+5, 0);}

    T sum(int l, int r){
        if(l > r) return 0;
        return (md + sum(r+1) - sum(l))%md;
    }

    void add(int i, T v){
        v %= md;
        for(++i; i<=n; i+=lsb(i))
            b[i] += v, b[i] %= md;
    }
};

int n, k, a[mx];

int main(){

    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n >> k;
    vector<Bit<int>> bt(n+1, Bit<int>(k+1));
    for(int i=1; i<=n; ++i) cin >> a[i];

    bt[0].add(0, 1);
    for(int i=1; i<=n; ++i)
    for(int j=0; j<=k; ++j){
        int u = max(0,j-a[i]), v = j;
        bt[i].add(j, bt[i-1].sum(u,v));
    }cout << bt[n].sum(k, k) << "\n";

    return 0;
}

