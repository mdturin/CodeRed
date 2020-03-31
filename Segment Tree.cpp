#include<bits/stdc++.h>
using namespace std;

const int mod = 1e9 + 7;
const int mx  = 2e5+5;

#define left(p)  (p<<1)
#define right(p) (p<<1)+1
#define mid(l,r) (l + (r-l)/2)

int n, q, a[mx], tree[mx<<2];

void build(int p, int l, int r){
    if(l == r) tree[p] = a[l];
    else{
        build(left(p), l, mid(l,r));
        build(right(p), mid(l,r)+1, r);
        tree[p] = tree[left(p)] + tree[right(p)];
    }
}

void update(int p, int l, int r, int &i, int &j, int v){
    if(l>r || l>j || r<i) return;
    if(l>=i && r<=j){
        tree[p] += (r-l+1)*v;
        return;
    }
    update(left(p), l, mid(l,r), i, j, v);
    update(right(p), mid(l,r)+1, r, i, j, v);
    tree[p] = tree[left(p)] + tree[right(p)];
}

int query(int p, int l, int r, int &i, int &j){
    if(l>r || l>j || r<i) return 0;
    if(l>=i && r<=j) return tree[p];
    int u = query(left(p), l, mid(l,r), i, j);
    int v = query(right(p), mid(l,r)+1, r, i, j);
    return u + v;
}

int main(){
    cin >> n;
    for(int i=0; i<n; i++)
        cin >> a[i];
    build(1, 0, n-1);
    int u, v; cin >> q;
    while(q--){
        cin >> u >> v; u--; v--;
        cout << query(1, 0, n-1, u, v) << "\n";
    }

    return 0;
}
