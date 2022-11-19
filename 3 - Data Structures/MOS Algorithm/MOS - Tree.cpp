#include<bits/stdc++.h>
using namespace std;

const int mx = 2e5+5;
const int lg = __lg(mx);

vector<int> g[mx]; int vis[mx];
int n, q, cur, a[mx], lvl[mx], par[mx][lg];
int blk[mx], id[mx], L[mx], R[mx], cnt[mx], ans[mx];

struct query{
	int l, r, lc, id;
	bool operator < (const query &ot){
		if(blk[l] != blk[ot.l])
			return blk[l] < blk[ot.l];
		return r < ot.r;
	}
}qq[mx];

void dfs(int u, int p, int h){
	L[u] = ++cur; id[cur] = u;
	lvl[u] = h; par[u][0] = p;
	for(int i=1; i<lg; i++)
		par[u][i] = par[par[u][i-1]][i-1];
	for(int v : g[u]) if(v != p)
		dfs(v, u, h+1);
	R[u] = ++cur; id[cur] = u;
}

inline int lca(int u, int v){
	if(lvl[u] > lvl[v]) swap(u, v);
	for(int i=lg-1; i>=0; i--)
		if(lvl[v] - (1<<i) >= lvl[u])
			v = par[v][i];
	if(u == v) return u;
	for(int i=lg-1; i>=0; i--)
		if(par[u][i] != par[v][i])
			u = par[u][i], v = par[v][i];
	return par[u][0];
}

int res = 0;
inline void check(int x){
	if(vis[x]){
		vis[x] = 0; --cnt[a[x]];
		if(cnt[a[x]] == 0) res--;
	}else{
		vis[x] = 1; ++cnt[a[x]];
		if(cnt[a[x]] == 1) res++;
	}
}

void compute(){
	int curl = qq[0].l, curr = qq[0].l-1;
	for(int i=0; i<q; i++){
		while(curl < qq[i].l) check(id[curl++]);
		while(curl > qq[i].l) check(id[--curl]);
		while(curr < qq[i].r) check(id[++curr]);
		while(curr > qq[i].r) check(id[curr--]);

		int u = id[curl], v = id[curr];
		if(qq[i].lc != u && qq[i].lc != v)
			check(qq[i].lc);
		ans[qq[i].id] = res;
		if(qq[i].lc != u && qq[i].lc != v)
			check(qq[i].lc);
	}
}

int main(){

	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	cin >> n >> q; cur = 0;
	for(int i=1; i<=n; i++) cin >> a[i];

	vector<int> tmp(a+1, a+n+1); sort(tmp.begin(), tmp.end());
	tmp.erase(unique(tmp.begin(), tmp.end()), tmp.end());
	for(int i=1; i<=n; i++)
		a[i] = lower_bound(tmp.begin(), tmp.end(), a[i]) - tmp.begin();

	for(int i=1,u,v; i<n; i++){
		cin >> u >> v;
		g[u].push_back(v);
		g[v].push_back(u);
	}dfs(1, 0, 0);

	int BLK = sqrt(cur);
	for(int i=1; i<=cur; i++)
		blk[i] = (i-1) / BLK + 1;

	for(int i=0,u,v; i<q; i++){
		cin >> u >> v;
		qq[i].lc = lca(u, v);
		if(L[u] > L[v]) swap(u, v);
		if(qq[i].lc == u)
			qq[i].l = L[u], qq[i].r = L[v];
		else qq[i].l = R[u], qq[i].r = L[v];
		qq[i].id = i;
	}sort(qq, qq + q);

	compute();

	for(int i=0; i<q; i++)
			cout << ans[i] << "\n";

	return 0;
}
