#include "bits/stdc++.h"
using namespace std;

const int cmx = 1e6+5;
const int qmx = 2e5+5;
const int mx = 3e4+5;

int n, q, a[mx], blk;
struct node{
    int l, r, p;
    node(){}
    node(int _l, int _r, int _p):
        l(_l), r(_r), p(_p){}
    bool operator < (const node &ot){
        if(l/blk != ot.l/blk)
            return l/blk < ot.l/blk;
        return r < ot.r;
    }
}qq[qmx];

int ans=0, cnt[cmx], res[qmx];
void add(int x){
    if(!cnt[ a[x] ]) ans++;
    cnt[ a[x] ]++;
}
void remove(int x){
    cnt[ a[x] ]--;
    if(!cnt[ a[x] ]) ans--;
}

int main(){
    cin >> n; blk = sqrt(n);
    for(int i=0; i<n; i++)
        cin >> a[i];

    cin >> q;
    for(int l,r,i=0; i<q; i++){
        cin >> l >> r;
        qq[i] = node(l-1, r-1, i);
    }
    sort(qq, qq+q);

    int cl=0, cr=0;
    for(int l,r,i=0; i<q; i++){
        l = qq[i].l, r = qq[i].r;
        while(cl < l) remove(cl++);
        while(cl > l)    add(--cl);
        while(cr<= r)    add(cr++);
        while(cr>r+1) remove(--cr);
        res[qq[i].p] = ans;
    }

    for(int i=0; i<q; i++)
        cout << res[i] << '\n';

    return 0;
}
