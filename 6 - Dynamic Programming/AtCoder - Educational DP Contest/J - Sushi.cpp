#include<bits/stdc++.h>
using namespace std;
using ll = long long;
using ii = pair<int,int>;

#define ff first
#define se second

const int md = 1e9+7;
const int mx = 305;

int n;
bool vis[mx][mx][mx];
double dp[mx][mx][mx];

double fun(int a, int b, int c){
    int tot = a + b + c;
    if(tot == 0) return 0;

    double &ans = dp[a][b][c];
    if(vis[a][b][c]) return ans;
    vis[a][b][c] = true; ans = 0;

    double res = double(n) / tot;
    if(a) ans += (fun(a-1, b, c)+res) * a / tot;
    if(b) ans += (fun(a+1, b-1, c)+res) * b / tot;
    if(c) ans += (fun(a, b+1, c-1)+res) * c / tot;
    return ans;
}

int main(){

    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n;
    int a = 0, b = 0, c = 0;
    for(int i=0; i<n; ++i){
        int x; cin >> x;
        a += (x == 1);
        b += (x == 2);
        c += (x == 3);
    }

    cout << setprecision(20) << fixed;
    cout << fun(a, b, c) << "\n";

    return 0;
}

