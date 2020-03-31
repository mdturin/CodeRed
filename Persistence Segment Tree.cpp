#include<bits/stdc++.h>
using namespace std;

const int mod = 1e9 + 7;
const int mx  = 1000;

#define mid(l,r) (l+(r-l)/2) 
int n, q, a[mx];

struct node{
    int v; node *l, *r;
    node(int va=0, node *le=NULL, node *ri=NULL):
        v(va), l(le), r(ri){}
} *tree[mx];

void merge(node *p){p->v = p->l->v + p->r->v;}
void build(node *p, int l, int r){
    if(l == r) p->v = a[l];
    else{
        p->l = new node();
        p->r = new node();
        build(p->l, l, mid(l,r));
        build(p->r, mid(l,r)+1, r);
        merge(p);
    }
}

void update(node *pre, node *cur, int l, int r, int i, int v){
    if(l == r) {cur->v = v; return;}
    if(i <= mid(l,r)){
        cur->r = pre->r;
        cur->l = new node();
        update(pre->l, cur->l, l, mid(l,r), i, v);
    }
    else{
        cur->l = pre->l;
        cur->r = new node();
        update(pre->r, cur->r, mid(l,r)+1, r, i, v);
    }
    merge(cur);
}

int query(node *p, int l, int r, int i, int j){
    if(l>r || l>j || r<i) return 0;
    if(l>=i && r<=j) return p->v;
    return query(p->l, l, mid(l,r), i, j) +
        query(p->r, mid(l,r)+1, r, i, j);
}

int main(){
    n = 10; tree[0] = new node();
    build(tree[0], 0, n-1);
    for(int i=0; i<n; i++){
        tree[i+1] = new node();
        update(tree[i], tree[i+1], 0, n-1, i, i);
    }

    cout << query(tree[n], 0, n-1, 0, 9) << "\n";
    cout << query(tree[n], 0, n-1, 1, 5) << "\n";
    cout << query(tree[n], 0, n-1, 2, 7) << "\n";

    return 0;
}

