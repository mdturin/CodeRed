#include<bits/stdc++.h>
using namespace std;

const int mod = 1e9+7;
const int MS = 2;

#define mem(a) memset(a, 0, sizeof a)

struct matrix{
    int mat[MS][MS];
    matrix(){mem(mat);}
}; /// {{1,1},{1,0}} for fibonacci

matrix init(){
    matrix res;
    for(int i=0; i<MS; i++)
        res.mat[i][i] = 1;
    return move(res);
}

int multiply(int a, int b){return (a*1LL*b)%mod;}

matrix matrixMultiply(matrix &a, matrix &b){
    matrix res;
    for(int i=0; i<MS; i++)
    for(int j=0; j<MS; j++)
    for(int k=0; k<MS; k++){
        res.mat[i][j] += multiply(a.mat[i][k], b.mat[k][j]);
        if(res.mat[i][j] > mod)
            res.mat[i][j] %= mod;
    }
    return move(res);
}

matrix a[32]; /// n < (1<<32)
int ans[MS], tmp[MS];

void getMultiply(int p){
    for(int i=0; i<MS; i++){
        tmp[i]  = multiply(a[p].mat[i][0], ans[0]);
        tmp[i] += multiply(a[p].mat[i][1], ans[1]);
    }
    for(int i=0; i<MS; i++) ans[i] = tmp[i] % mod;
}

void build(){
    a[0].mat[0][0] = 1; a[0].mat[0][1] = 1;
    a[0].mat[1][0] = 1; a[0].mat[1][1] = 0;
    for(int i=1; i<32; i++)
        a[i] = matrixMultiply(a[i-1], a[i-1]);
}

int query(int n){
    ans[0] = 1; ans[1] = 0; n--;
    for(int i=0; i<32; i++)
        if((n>>i) & 1)
            getMultiply(i);
    return ans[0];
}

int main(){
    build();
    while(1){
        int n; cin >> n;
        if(n < 2) cout << n << '\n';
        else cout << query(n) << "\n";
    }
    return 0;
}
