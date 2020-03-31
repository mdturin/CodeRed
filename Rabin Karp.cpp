#include<bits/stdc++.h>
using namespace std;

#define pb push_back 
using ll = long long;
using vi = vector<int>;

const ll mod = (ll)1e9 + 7LL;
const int mx  = 2e5+5;
const int base = 26;

vi search(string t, string p){
    if(p.size() > t.size()) return vi();
    int n = t.size(), m = p.size(), len = n-m;
    int long long tv = 0LL, pv = 0LL, h = 1LL;

    for(int i=0; i<m-1; i++)
        h = (h * base) % mod;

    for(int i=0; i<m; i++){
        pv = (base * pv + p[i]) % mod;
        tv = (base * tv + t[i]) % mod;
    }

    vi ans; t += '$';
    for(int i=0; i<=len; i++){
        if(pv == tv){
            int j = 0;
            for(j=0; j<m; j++)
                if(t[i+j] != p[j])
                    break;
            if(j == m) ans.pb(i);
        }
        tv = ((tv - t[i]*h)*base + t[i+m]) % mod;
        if(tv < 0) tv += mod;
    }
    return move(ans);
}

int main(){
    vi ans = search("aaaabaaba", "aaa");
    for(auto p:ans)
        cout << p << " ";

    return 0;
}

