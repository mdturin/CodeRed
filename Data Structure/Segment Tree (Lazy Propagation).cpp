#include<bits/stdc++.h>
using namespace std;

const int mod = 1e9 + 7;
const int mx  = 1e5+5;

#define left(p)  (p<<1)
#define right(p) (p<<1|1)
#define mid(l,r) (l+(r-l)/2)

int n, q, a[mx];
int tree[mx<<2];
int lazy[mx<<2];

void build(int p, int l, int r){
    lazy[p] = 0;
    if(l == r) tree[p] = a[l];
    else{
    	build(left(p), l, mid(l,r));
    	build(right(p), mid(l,r)+1, r);
    	tree[p] = tree[left(p)] + tree[right(p)];
    }
}

void updateLazy(int p, int l, int r){
	tree[p] += (r-l+1) * lazy[p];
	if(l != r){
		lazy[left(p)] += lazy[p];
		lazy[right(p)] += lazy[p];
	}lazy[p] = 0;
}

void update(int p, int l, int r, int i, int j, int v){
	if(lazy[p]) updateLazy(p, l, r);
	if(l>r || l>j || r<i) return;
	if(l>=i && r<=j){
		lazy[p] += v;
		updateLazy(p, l, r);
		return;
	}
	update(left(p), l, mid(l,r), i, j, v);
	update(right(p), mid(l,r)+1, r, i, j, v);
	tree[p] = tree[left(p)] + tree[right(p)];
}

int query(int p, int l, int r, int i, int j){
	if(lazy[p]) updateLazy(p, l, r);
	if(l>r || l>j || r<i) return 0;
	if(l>=i && r<=j) return tree[p];
	int u = query(left(p), l, mid(l,r), i, j);
	int v = query(right(p), mid(l,r)+1, r, i, j);
	tree[p] = tree[left(p)] + tree[right(p)];
	return u + v;
}

int main(){
	cin >> n;
    for(int i=0; i<n; i++)
        cin >> a[i];
    build(1, 0, n-1);
    cin >> q;
    while(q--){
        int u, v, w; 
		cin >> u >> v >> w; u--; v--;
        update(1, 0, n-1, u, v, w);
    }
    cin >> q;
    while(q--){
        int u, v; cin >> u >> v; u--; v--;
        cout << query(1, 0, n-1, u, v) << "\n";
    }
    return 0;
}

