#include<bits/stdc++.h>
using namespace std;

const int mod = 1e9+7;
const int MS = 2;

#define mem(a) memset(a, 0, sizeof a)

struct matrix{
    int mat[MS][MS];
    matrix(){mem(mat);}
}root; /// {{1,1},{1,0}} for fib

matrix init(){
    matrix res;
    for(int i=0; i<MS; i++)
        res.mat[i][i] = 1;
    return move(res);
}

matrix matrixMultiply(matrix &a, matrix &b){
    matrix res;
    for(int i=0; i<MS; i++)
    for(int j=0; j<MS; j++)
    for(int k=0; k<MS; k++){
        res.mat[i][j] += a.mat[i][k] * b.mat[k][j];
        if(res.mat[i][j] > mod)
            res.mat[i][j] %= mod;
    }
    return move(res);
}

matrix matrixPower(matrix m, int p){
    matrix res = init();
    while(p > 0){
        if(p & 1)
            res = matrixMultiply(res, m);
        m = matrixMultiply(m, m); p >>= 1;
    }
    return res;
}

int main(){
    root.mat[0][0] = 1;
    root.mat[0][1] = 1;
    root.mat[1][0] = 1;

    while(1){
        int n; cin >> n;
        if(n < 2) cout << n << '\n';
        else{
            matrix res = matrixPower(root, n-1);
            int ans = ( res.mat[0][0] ) % mod;
            cout << ans << '\n';
        }
    }
    return 0;
}
