#include<bits/stdc++.h>
using namespace std;
const int mx = 1e6 + 5;

int main(){

    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int tc, cs=1; cin >> tc;
    while(tc--){
        string s; cin >> s;
        vector<int> cnt(128, 0);
        for(int c : s) cnt[c]++;

        int ans = INT_MAX;
        for(int i='a'; i<='z'; ++i)
            ans = min(ans, cnt[i]);

        cout << "Case " << cs++ << ": ";
        cout << ans << "\n";
    }

    return 0;
}
