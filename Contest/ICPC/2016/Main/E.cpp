#include<bits/stdc++.h>
using namespace std;
const int mx = 1e6 + 5;

int main(){

    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    string s;
    int tc, cs=1; cin >> tc;
    while(tc--){
        int n; cin >> n;

        bool ok = (n%2 == 0);
        vector<int> a(n+5, 0);
        for(int i=0; i<n; ++i){
            int x; cin >> x;
            if(x > n) ok = 0;
            else if(x < 0) ok = 0;
            else a[x]++;
        }

        cout << "Case " << cs++ << ": ";
        if(!ok) cout << "invalid\n";
        else{
            int cur = 0; string res = "";
            for(int i=0; i<n; ++i){
                if(a[cur+1]) res += "(", a[++cur]--;
                else if(cur>0 && a[cur-1]) res += ")", a[--cur]--;
                else {ok=0; break;}
            }

            int tot = accumulate(a.begin(), a.end(), 0);
            if(tot) ok = 0;

            if(!ok) cout << "invalid\n";
            else cout << res << "\n";
        }
    }

    return 0;
}

