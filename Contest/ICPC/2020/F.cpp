#include<bits/stdc++.h>
using namespace std;
using ll = long long;
const int mx = 1e6 + 5;

#define ff first
#define se second

struct info{
    ll sq, sm, cnt, res;
    info(){res=sm=sq=cnt=0;}
    info(int x){
        sm = x;
        res = 0; cnt = 1;
        sq = 1LL * x * x;
    }
}t[mx<<2];

info merge(info l, info r){
    info ans;
    ans.sm = l.sm + r.sm;
    ans.sq = l.sq + r.sq;
    ans.cnt = l.cnt + r.cnt;
    ans.res = l.res + r.res +
        1LL * r.cnt * l.sq +
        1LL * l.cnt * r.sq -
        2LL * l.sm * r.sm;
    return ans;
}

info query(int p, int l, int r, int i, int j){
    if(l>r || l>j || r<i) return info();
    if(l>=i && r<=j) return t[p];
    int mid = (l + r) / 2;
    return merge(query(p<<1, l, mid, i, j),
                 query(p<<1|1, mid+1, r, i, j));
}

vector<int> a; int n, k;
void build(int p, int l, int r){
    if(l == r) t[p] = info(a[l]);
    else{
        int mid = (l + r) / 2;
        build(p<<1, l, mid);
        build(p<<1|1, mid+1, r);
        t[p] = merge(t[p<<1], t[p<<1|1]);
    }
}

ll get_val(int i, int j){
    if(i == j) return 0;
    return query(1, 0, n-1, i, j).res;
}

/**
2
5 3
3 1
5 1
6 1
1 1
9 1
4 2
234 2
1 1
5 1
3 1
*/

int main(){

    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int tc; cin >> tc;
    for(int cs=1; cs<=tc; cs++){
        cin >> n >> k; a.clear();
        for(int i=0; i<n; ++i){
            int x, f; cin >> x >> f;
            while(f--) a.push_back(x);
        }sort(a.begin(), a.end());

        n = a.size();
        build(1, 0, n-1);

        long long ans = LLONG_MAX, cnt = 0;
        for(int i=0, j=k-1; j<n; ++i, ++j){
            long long res = get_val(i, j);
            if(res < ans) ans = res, cnt = 1;
            else if(res == ans) cnt++;
        }

        cout << "Case " << cs << ": ";
        cout << ans << " " << cnt << "\n";
    }

    return 0;
}
