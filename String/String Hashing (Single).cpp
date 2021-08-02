#include<bits/stdc++.h>
using namespace std;

const int mx = 1e6 + 10;
using ull = unsigned long long;

ull base = 31, pw[mx];
inline void init(){
    pw[0] = 1;
    for(int i=1; i<mx; i++)
        pw[i] = (1LL * pw[i-1] * base);
}

struct HASH{
    int n; ull H[mx], RH[mx];
    inline void build(string &s){
        n = s.size(); RH[0] = H[0] = 0;
        for(int i=0; i<n; i++)  H[i+1] = H[i]  * base + s[i];
        for(int i=0; i<n; i++) RH[i+1] = RH[i] * base + s[n-i-1];
    }
    inline ull  getV(){return (H[n]);}
    inline ull  getH(int i, int sz){return ( H[i+sz] -  H[i] * pw[sz]);}
    inline ull getRH(int i, int sz){return (RH[i+sz] - RH[i] * pw[sz]);}
}HS1, HS2;

int main(){

    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    init(); /// MUST

    string s; cin >> s; HS1.build(s);
    string t; cin >> t; HS2.build(t);

    ull ht = HS2.getV(); int ans = 0;
    for(int i=0; i<=s.size()-t.size(); i++)
        if(HS1.getH(i, t.size()) == ht)
            ans++;
    cout << ans << "\n";

    return 0;
}
