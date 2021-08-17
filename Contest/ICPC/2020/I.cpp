#include<bits/stdc++.h>
using namespace std;
using ll = long long;
using tpl = tuple<int,int,int>;

const int mx = 5e4 + 5;
const int lg = __lg(mx) + 2;

vector<tpl> vec; ll sum[mx];
int n, m, a[mx], st[mx][lg];

int fun(int x, int y){return min(x,y);}

void sparse_build(){
    for(int i=1; i<=n; i++) st[i][0] = a[i];
    for(int j=1; j<lg; j++)
    for(int i=1; i+(1<<j)<=n+1; i++)
        st[i][j] = fun(st[i][j-1], st[i+(1<<(j-1))][j-1]);
}

int query(int l, int r){
    int j = __lg((r-l+1));
    return fun(st[l][j], st[r-(1<<j)+1][j]);
}

ll query_sum(int i, int j){
    return sum[j] - sum[i-1];}

ll solve(int i, int k){
    if(i == k) return 0;

    int j = i, l, r, x, nl, nr, nx;
    tie(l, r, x) = vec[i]; r = -r;
    for(j=i+1; j<k; ++j){
        tie(nl, nr, nx) = vec[j]; nr = -nr;
        if(r < nl) break;
    }

    ll ans = 0;
    if(i+1 == j) ans = query_sum(i, j-1) - query(l, r);
    else
        ans = max(query_sum(i, j-1) - query(l, r), solve(i+1, j));
    ans += solve(j, k); return ans;
}

/**

2
3 3
10 1 1
5 2 2
8 3 3
1 1 1
2 3
41 2 3
78 3 3
45 81 27
*/

int main(){

    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int tc; cin >> tc;
    for(int cs=1; cs<=tc; cs++){
        cin >> m >> n;

        vec.clear();
        vec.emplace_back(0, 0, 0);

        int x, l, r;
        for(int i=0; i<m; ++i){
            cin >> x >> l >> r;
            vec.emplace_back(l, -r, x);
        }sort(vec.begin()+1, vec.end());

        for(int i=1; i<vec.size(); ++i)
            sum[i] = sum[i-1] + get<2>(vec[i]);

        for(int i=1; i<=n; ++i) cin >> a[i];
        sparse_build();

        cout << "Case " << cs << ": ";
        cout << solve(1, m+1) << "\n";
    }

    return 0;
}

