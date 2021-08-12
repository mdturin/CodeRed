#include<bits/stdc++.h>
using namespace std;
using ll = long long;
const int mod = 1e9 + 7;

/**
Define Matrix
    [0 1 0] [f0]   [f1]
    |0 0 1| |f1| = |f2|
    [1 1 1] [f2]   [f3]
*/

struct matrix{
    int row, col;
    vector<vector<int>> mat;
    matrix(int x = 1) : matrix(x, x){}
    matrix(int x, int y) : row(x), col(y),
        mat(vector<vector<int>>(x, vector<int>(y,0))){}
    vector<int>& operator [](int r){return mat[r];}
    matrix operator * (matrix &ot){
        assert(col == ot.row);
        matrix res(row, ot.col);
        for(int i=0; i<row; ++i)
        for(int j=0; j<ot.col; ++j)
        for(int k=0; k<col; ++k){
            res[i][j] += (ll) mat[i][k] * ot[k][j] % mod;
            if(res[i][j] >= mod) res[i][j] -= mod;
        }return res;
    }
}mat_pw[64];

matrix init_root(int sz=1){
    matrix root(sz);
    for(int i=0; i<sz-1; ++i) root[i][i+1] = 1;
    for(int i=0; i<sz; ++i) root[sz-1][i] = 1;
    return root;
}

ostream& operator << (ostream &os, matrix &m){
    for(int i=0; i<m.row; ++i)
    for(int j=0; j<m.col; ++j)
        os << m[i][j] << " \n"[j+1==m.col];
    return os;
}

matrix init(int k, int val = 1){
    matrix res(k);
    for(int i=0; i<k; i++)
        res.mat[i][i] = val;
    return move(res);
}

int operator * (const vector<int> &m, int *a){
    int res = 0;
    for(int i=0; i<(int)m.size(); i++){
        res += (ll) m[i] * a[i] % mod;
        if(res >= mod) res -= mod;
    }return res;
}

matrix power(matrix m, ll p){
    assert(m.row == m.col);
    matrix r = init(m.row);
    while(p > 0){
        if(p & 1) r = r * m;
        m = m * m; p >>= 1;
    }return r;
}

void build(matrix &m){
    mat_pw[0] = m;
    for(int i=1; i<64; ++i)
        mat_pw[i] = mat_pw[i-1] * mat_pw[i-1];
}

matrix query(int sz, ll p){
    // MUST call build first
    matrix res = init(sz);
    for(int i=0; i<64; ++i)
        if((p >> i) & 1)
            res = res * mat_pw[i];
    return res;
}

void mul_ara(matrix &m, int ans[]){
    int tmp[m.row] = {};
    for(int i=0; i<m.row; i++)
        tmp[i] = m[i] * ans;
    memcpy(ans, tmp, sizeof(tmp));
}

void query(int a[], ll p){
    // MUST call build first
    for(int i=0; i<64; ++i)
        if((p >> i) & 1)
            mul_ara(mat_pw[i], a);
}

int main(){

    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    matrix m = init_root(2);
    build(m);

    int tc; cin >> tc;
    while(tc--){
        int n; cin >> n;
        if(n < 2) cout << n << "\n";
        else{
            int a[2] = {0, 1};
            query(a, n-1);
            cout << a[1] << "\n";
        }
    }

    return 0;
}
