#include<bits/stdc++.h>
using namespace std;
using ll = long long;

const int mx = 1e6+5;
const int md = 1e9+7;

ll dp[mx][2], n;
void init(){
    dp[1][0] = dp[1][1] = 1;
    for(int i=2; i<mx; i++){
        dp[i][0] = (dp[i-1][0]*4 + dp[i-1][1]) % md;
        dp[i][1] = (dp[i-1][0] + 2*dp[i-1][1]) % md;
    }
}

int main(){

    ios_base::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);

    init();

    int tc; cin >> tc; while(tc--){
        cin >> n;
        cout << (dp[n][0]+dp[n][1])%md << "\n";
    }

    return 0;
}
