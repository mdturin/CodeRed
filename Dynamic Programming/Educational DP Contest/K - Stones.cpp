#include<bits/stdc++.h>
using namespace std;
using ll = long long;
using ii = pair<int,int>;

#define ff first
#define se second

const int md = 1e9+7;
const int mx = 1e6+5;

int n, k;
int a[101], dp[mx];

int main(){

    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n >> k;
    for(int i=0; i<n; ++i)
        cin >> a[i];

    for(int i=1; i<=k; ++i)
    for(int j=0; j<n; ++j)
    if(i >= a[j] && !dp[i-a[j]]){
        dp[i] = 1; break;
    }

    cout << (dp[k] ? "First" : "Second") << "\n";

    return 0;
}
