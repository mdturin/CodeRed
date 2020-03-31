#include<bits/stdc++.h>
using namespace std;

const int mx = 505;
const int K = 10;

using ll = long long;

ll n, m;
ll a[mx][mx];

ll st[mx][mx][K][K];
ll fun(ll u, ll v){return u+v;}
void build(){
    for(int ki=0; (1<<ki)<=n; ki++)
    for(int kj=0; (1<<kj)<=m; kj++)
    for(int i=0; i+(1<<ki)<=n; i++)
    for(int j=0; j+(1<<kj)<=m; j++){
        int jk = j+(1<<(kj-1)), ik = i+(1<<(ki-1));
        if(ki==0 && kj==0) st[i][j][0][0] = a[i][j];
        else if(ki == 0)
            st[i][j][ki][kj] = fun(st[i][j][ki][kj-1], st[i][jk][ki][kj-1]);
        else if(kj == 0)
            st[i][j][ki][kj] = fun(st[i][j][ki-1][kj], st[ik][j][ki-1][kj]);
        else{
            st[i][j][ki][kj] = fun(
                fun(st[i][j][ki-1][kj-1], st[ik][j][ki-1][kj-1]),
                fun(st[i][jk][ki-1][kj-1], st[ik][jk][ki-1][kj-1])
            );
        }
    }
}

ll queryY(int x, int k, int l, int r){
    ll sum = 0, dif = r-l+1;
    for(int i=K; i>=0; i--)
    if((1<<i) <= dif){
        sum += st[x][l][k][i];
        l += (1<<i);
    }
    return sum;
}

ll query(int l, int r, int xx, int yy){
    ll sum = 0, dif = r-l+1;
    for(int i=K; i>=0; i--){
        if((1<<i) <= dif){
            sum += queryY(l, i, xx, yy);
            l += (1<<i);
        }
    }
    return sum;
}

int minMaxQuery(int x1, int y1, int x2, int y2){
    int k1 = log2(x2 - x1 + 1);
    int k2 = log2(y2 - y1 + 1);
    return min(
        min(st[x1][y1][k1][k2], st[x2+1-(1<<k1)][y1][k1][k2]),
        min(st[x1][y2+1-(1<<(k2))][k1][k2], st[x2+1-(1<<k1)][y2+1-(1<<k2)][k1][k2])
    );
}

int main(){
    cin >> n >> m;
    for(int i=0; i<n; i++)
    for(int j=0; j<m; j++)
        cin >> a[i][j];

    build();

    int x1, x2, y1, y2;
    while(cin >> x1 >> y1 >> x2 >> y2)
        cout << query(x1, x2, y1, y2) << "\n";

    return 0;
}
