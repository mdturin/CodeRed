#include<bits/stdc++.h>
using namespace std;
const int mx = 1e4 + 5;
const int M  = (1 << 7);
int n, q, a[M+5][mx];

/**
1
5
1 4 6 7 8
3
0 0
0 1
2 4
*/

int main(){

    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int tc, cs=1; cin >> tc;
    while(tc--){
        cin >> n;
        for(int i=0; i<n; ++i) cin >> a[0][i];
        for(int i=1; i*M<n; ++i)
        for(int j=0; j+i*M<n; ++j)
            a[i][j] = a[i-1][j] ^ a[i-1][j+M];

        cout << "Case " << cs++ << ":\n";
        cin >> q; while(q--){
            int l, r; cin >> l >> r;

            int len = r - l;
            int m = len / M;
            int o = len % M;

            int ans = a[m][l];
            for(int i=o; i; i=(i-1)&o)
                ans ^= a[m][l+i];
            cout << ans << "\n";
        }
    }

    return 0;
}

