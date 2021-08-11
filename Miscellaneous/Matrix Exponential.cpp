#include<bits/stdc++.h>
using namespace std;

const int mod = 1e9+7;
const int MS = 2;

#define mem(a) memset(a, 0, sizeof a)

struct matrix{
    int mat[MS][MS];
    matrix(){mem(mat);}
};/// {{1,1},{1,0}} for fib

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
        res.mat[i][j] += (a.mat[i][k] * 1LL * b.mat[k][j])%mod;
        if(res.mat[i][j] >= mod) res.mat[i][j] -= mod;
    }return move(res);
}

long long matrixMultiplyArray(const matrix &m, int *a, int r){
    long long res = 0;
    for(int i=0; i<MS; i++){
        res += m.mat[r][i] * 1LL * a[i] % mod;
        if(res >= mod) res -= mod;
    }return res;
}

matrix matrixPower(matrix m, long long p){
    matrix res = init();
    while(p > 0){
        if(p & 1)
            res = matrixMultiply(res, m);
        m = matrixMultiply(m, m); p >>= 1;
    }return res;
}

void add_val(matrix &m, int i, int j, int v){
    m.mat[i][j] = v;
}

matrix init_root(){
    matrix root;
    add_val(root, 0, 0, 1);
    add_val(root, 0, 1, 1);
    add_val(root, 1, 0, 1);
    return root;
}

int main(){

    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    matrix root = init_root();
    long long n; while(cin >> n){
        if(n < 2) cout << n << '\n';
        else{
            matrix res = matrixPower(root, n-1);
            int ans = ( res.mat[0][0] ) % mod;
            cout << ans << '\n';
        }
    }
    
    return 0;
}
