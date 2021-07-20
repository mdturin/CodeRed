#include "bits/stdc++.h"
using namespace std;
using ll = long long;
const int mx = 2e6+5;

inline ll gilbertOrder(int x, int y, int pow, int rotate) {
	if (pow == 0) return 0;
	int hpow = 1 << (pow-1);
	int seg = (x < hpow) ? (
		(y < hpow) ? 0 : 3) : ((y < hpow) ? 1 : 2);
	seg = (seg + rotate) & 3;
	const int rotateDelta[4] = {3, 0, 0, 1};
	int nx = x & (x ^ hpow), ny = y & (y ^ hpow);
	int nrot = (rotate + rotateDelta[seg]) & 3;
	ll subSquareSize = ll(1) << (2*pow - 2);
	ll ans = seg * subSquareSize;
	ll add = gilbertOrder(nx, ny, pow-1, nrot);
	ans += (seg == 1 || seg == 2) ? add : (subSquareSize - add - 1);
	return ans;
}

int n, q, a[mx], blk;
int ans=0, cnt[mx], res[mx];

struct node{
    int l, r, p; ll ord; node(){}
    node(int _l, int _r, int _p):
        l(_l), r(_r), p(_p){
        ord = gilbertOrder(l, r, 21, 0);
    }
    bool operator < (const node &ot){
        return ord < ot.ord;
    }
}qq[mx];

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
        cin >> l >> r; --l; --r;
        qq[i] = node(l, r, i);
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
