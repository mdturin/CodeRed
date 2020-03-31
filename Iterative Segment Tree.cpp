#include<bits/stdc++.h>
using namespace std;

const int mod = 1e9 + 7;
const int mx  = 2e5+5;

int n, t[mx<<1];
void build(){
    for(int i=n-1; i; i--)
        t[i] = t[i<<1] + t[i<<1|1];
}

void update(int i, int v){
    for(t[i+=n]=v; i>1; i>>=1)
        t[i>>1] = t[i] + t[i^1];
}

void update(int i, int j, int v){
    for(i+=n, j+=n; i<j; i>>=1, j>>=1){
        if(i&1) t[i++] += v;
        if(j&1) t[--j] += v;
    }
}

int query(int p){
    int res = 0;
    for(p+=n; p; p>>=1)
        res += t[p];
    return res;
}

int query(int l, int r){
    int res = 0;
    for(l+=n, r+=n; l<r; l>>=1, r>>=1){
        if(l&1) res += t[l++];
        if(r&1) res += t[--r];
    }
    return res;
}

int main(){
    cin >> n;
    for(int i=0; i<n; i++)
        cin >> t[i+n];
    build();

    cout << query(0, n) << "\n";
    update(0, 10); cout << query(0, n) << "\n";
    update(n-1, -8); cout << query(0, n) << "\n";

    return 0;
}

