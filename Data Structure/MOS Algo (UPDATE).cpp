#include<bits/stdc++.h>
using namespace std;
using ll = long long;
const int mx = 2e5+5;

int blk[mx]; struct node{
    int l, r, pos, id;
    bool operator < (const node &ot){
        if(blk[l] != blk[ot.l]) return l < ot.l;
        if(blk[r] != blk[ot.r])
            return (blk[l]&1) ? r < ot.r : r > ot.r;
        return (blk[r]&1) ? pos > ot.pos : pos < ot.pos;
    }
}A[mx], B[mx]; int ca, cb;
int n, q, a[mx], ans[mx], cnt[mx], res;

inline void add(int x){
    if(!cnt[ a[x] ]) res++;
    cnt[ a[x] ]++;
}

inline void del(int x){
    cnt[ a[x] ]--;
    if(!cnt[ a[x] ]) res--;
}

int main(){

    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    ca = cb = 0;
    cin >> n >> q; int op, l, r, p;

    int BLK = pow(n, 2/3.0);
    for(int i=1; i<mx; i++)
        blk[i] = (i-1)/BLK + 1;

    for(int i=0; i<n; i++) cin >> a[i];
    for(int i=0; i<q; i++){
        cin >> op >> l >> r;
        if(op == 2) ++ca, A[ca] = {l, r, cb, ca};
        else B[++cb] = {l, a[l], r, -1}, a[l] = r;
    }sort(A+1, A+ca+1);

    l = 0; r = -1; p = cb;
    for(int i=1; i<=ca; i++){
        while(r < A[i].r) add(++r);
        while(l > A[i].l) add(--l);
        while(r > A[i].r) del(r--);
        while(l < A[i].l) del(l++);
        while(p > A[i].pos){
            if(l <= B[p].l && B[p].l <= r)
                del(B[p].l);
            a[B[p].l] = B[p].r;
            if(l <= B[p].l && B[p].l <= r)
                add(B[p].l);
            --p;
        }while(p < A[i].pos){
            ++p;
            if(l <= B[p].l && B[p].l <= r)
                del(B[p].l);
            a[B[p].l] = B[p].pos;
            if(l <= B[p].l && B[p].l <= r)
                add(B[p].l);
        }ans[A[i].id] = res;
    }

    for(int i=1; i<=ca; i++)
        cout << ans[i] << "\n";

    return 0;
}
