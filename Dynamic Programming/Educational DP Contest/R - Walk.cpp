#include<bits/stdc++.h>
using namespace std;
using ll = long long;
using ii = pair<int,int>;

#define ff first
#define se second

const int md = 1e9+7;
const int mx = 1e6+5;

#define MATRIX_MOD md
template<class T, int N>
struct Matrix{
    T m[N+1][N+1];
    Matrix(T v = 0){
        memset(m, 0, sizeof m);
        if(v != 0){
            for(int i=1; i<=N; ++i)
                m[i][i] = v;
        }
    }
    inline Matrix operator * (const Matrix &ot){
        Matrix<T, N> res;
        for(int k=1; k<=N; ++k)
        for(int i=1; i<=N; ++i){
            if(m[i][k] == 0) continue;
            for(int j=1; j<=N; ++j){
                res.m[i][j] += m[i][k] * ot.m[k][j];
                #ifdef MATRIX_MOD
                    res.m[i][j] %= MATRIX_MOD;
                #endif // MATRIX_MOD
            }
        }return res;
    }
    inline Matrix power(long long p){
        Matrix res(1), cur = *this;
        for(; p>0; p>>=1){
            if(p & 1)
                res = res * cur;
            cur = cur * cur;
        }return res;
    }
    inline void print(){
        cout << N << endl;
        for(int i=1; i<=N; ++i)
        for(int j=1; j<=N; ++j)
            cout << m[i][j] << " \n"[j==N];
        cout << endl;
    }
    inline void init(int *ara, int x, int y){
        int k = 0;
        for(int i=1; i<=x; ++i)
        for(int j=1; j<=y; ++j, ++k)
            m[i][j] = *(ara+k);
    }
};

int main(){

    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n; ll k;
    cin >> n >> k;

    int a[n * n];
    for(int i=0; i<n*n; ++i)
        cin >> a[i];

    Matrix<ll, 50> mat;
    mat.init(a, n, n);
    mat = mat.power(k);

    int ans = 0;
    for(int i=0; i<=n; ++i)
    for(int j=0; j<=n; ++j)
        ans += mat.m[i][j], ans %= md;
    cout << ans << "\n";

    return 0;
}

