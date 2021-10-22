#include<bits/stdc++.h>
using namespace std;

const int mx = 1e6 + 10;

using ull = unsigned long long;
using pul = pair<ull, ull>;

ull p1=31, p2=97, pw1[mx], pw2[mx];
inline void init(){
    pw1[0] = pw2[0] = 1;
    for(int i=1; i<mx; i++){
        pw1[i] = (pw1[i-1] * p1);
        pw2[i] = (pw2[i-1] * p2);
    }
}

struct HASH{
    int n; ull H1[mx], H2[mx];
    inline void build(string &s){
        n = s.size(); H1[0] = H2[0] = 0;
        for(int i=0; i<n; i++) H1[i+1] = H1[i] * p1 + s[i];
        for(int i=0; i<n; i++) H2[i+1] = H2[i] * p2 + s[i];
    }
    inline pul getV(){return pul(H1[n],H2[n]);}
    inline pul getH(int i, int sz){
        return pul(H1[i+sz] - H1[i] * pw1[sz],
                   H2[i+sz] - H2[i] * pw2[sz]);
    }
}HS1, HS2;

int main(){

    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    init(); /// MUST

    string s; cin >> s; HS1.build(s);
    string t; cin >> t; HS2.build(t);

    pul ht = HS2.getV(); int ans = 0;
    for(int i=0; i<=s.size()-t.size(); i++)
        if(HS1.getH(i, t.size()) == ht)
            ans++;
    cout << ans << "\n";
}
