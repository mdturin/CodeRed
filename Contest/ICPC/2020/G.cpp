#include<bits/stdc++.h>
using namespace std;
const int mx = 1e6 + 5;

/**
3
1.0000 1.0000
2.0000 4.0000
5.0000 8.0000
7
1.0000 0.5000
2.0000 2.5000
3.0000 2.0000
4.0000 4.0000
5.0000 3.5000
6.0000 6.0000
7.0000 5.5000
0
*/

int main(){

    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout << setprecision(3) << fixed;

    int tc, n, cs = 1;
    while(cin >> n, n){
        double x=0, y=0, xs=0, xy=0, a, b;
        for(int i=0; i<n; ++i){
            cin >> a >> b;
            x += a; xs += a * a;
            y += b; xy += a * b;
        }

        double a1 = n * xy  - x * y;
        a1 /= (n * xs) - (x * x);
        double a0 = y - a1 * x;

        double ans = a1 * x / n;
        ans = ans * (n + 1) - y;

        cout << "Case " << cs++ << ": ";
        cout << (x/n) << " " << ans << "\n";
    }

    return 0;
}

