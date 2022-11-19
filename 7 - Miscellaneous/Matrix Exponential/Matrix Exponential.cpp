#include<bits/stdc++.h>
using namespace std;
const int mod = 1e9 + 7;

struct matrix{
	vector<vector<int>> mat; int MS;
	matrix(int k){
		MS = k;
		mat.resize(k, vector<int>(k, 0));
	}
	void print(){
		for(int i=0; i<MS; ++i)
		for(int j=0; j<MS; ++j)
			cout << mat[i][j] << " \n"[j+1==MS];
	}
};

matrix init(int k){
	matrix res(k);
	for(int i=0; i<k; i++)
		res.mat[i][i] = 1;
	return move(res);
}

matrix matrixMultiply(const matrix &a, const matrix &b){
	int MS = a.MS; 
	matrix res(MS);
	for(int i=0; i<MS; i++) 
	for(int j=0; j<MS; j++)
	for(int k=0; k<MS; k++){
		res.mat[i][j] += a.mat[i][k] * 1LL * b.mat[k][j] % mod;
		if(res.mat[i][j] >= mod) res.mat[i][j] -= mod;
	}return move(res);
}

long long matrixMultiplyArray(const matrix &m, int *a, int r){
	long long res = 0; int MS = m.MS;
	for(int i=0; i<MS; i++){
		res += m.mat[r][i] * 1LL * a[i] % mod;
		if(res >= mod) res -= mod;
	}return res;
}

matrix matrixPower(matrix m, long long p){
	matrix res = init(m.MS);
	while(p > 0){
		if(p & 1)
			res = matrixMultiply(res, m);
		m = matrixMultiply(m, m); p >>= 1;
	}return res;
}

void add_val(matrix &m, int i, int j, int v){
	m.mat[i][j] = v;
}

matrix init_root(int k){
	matrix root(k);
	add_val(root, 0, 0, 1);
	add_val(root, 0, 1, 1);
	add_val(root, 1, 0, 1);
	return root;
}

int main(){

	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	matrix root = init_root(2);
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
