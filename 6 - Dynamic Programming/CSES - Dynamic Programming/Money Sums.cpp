#include<bits/stdc++.h>
using namespace std;
const int mx  = 1e5 + 1;

int dp[mx];
int n, w, a[101];

int main(){

    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n;
    for(int i=1; i<=n; ++i) cin >> a[i];

    dp[0] = 1;
    for(int i=1; i<=n; ++i)
    for(int j=mx-1; j>=a[i]; --j)
        dp[j] |= dp[j-a[i]];

    vector<int> ans;
    for(int i=1; i<mx; ++i)
        if(dp[i]) ans.push_back(i);

    cout << ans.size() << "\n";
    for(int i=0; i<ans.size(); ++i)
        cout << ans[i] << " \n"[i+1==ans.size()];

    return 0;
}
