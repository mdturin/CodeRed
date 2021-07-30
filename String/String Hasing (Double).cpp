#include<bits/stdc++.h>
#include<ext/pb_ds/assoc_container.hpp>

using namespace std;
using namespace __gnu_pbds;

const int mx = 1e6 + 10;
#define rint register int
using ull = unsigned long long;
using pul = pair<ull, ull>;

struct chash {
    const int RANDOM = (long long)(make_unique<char>().get()) ^ chrono::high_resolution_clock::now().time_since_epoch().count();
    static unsigned long long hash_f(unsigned long long x) {
        x += 0x9e3779b97f4a7c15;
        x = (x ^ (x >> 30)) * 0xbf58476d1ce4e5b9;
        x = (x ^ (x >> 27)) * 0x94d049bb133111eb;
        return x ^ (x >> 31);
    }
    ull operator()(pul x) const { return (hash_f(x.first)*31 + hash_f(x.second))^RANDOM; }
};

struct HASH{
    int n; ull p1=31, p2=97, pw1[mx], pw2[mx], H1[mx], H2[mx];
    HASH(){pw1[0]=pw2[0]=1; for(rint i=1; i<mx; i++) pw1[i]=(pw1[i-1]*p1), pw2[i]=(pw2[i-1]*p2);}
    inline void build(string &s){
        n = s.size(); H1[0] = H2[0] = 0;
        for(rint i=0; i<n; i++) H1[i+1] = H1[i] * p1 + s[i];
        for(rint i=0; i<n; i++) H2[i+1] = H2[i] * p2 + s[i];
    }
    inline pul getV(){return pul(H1[n],H2[n]);}
    inline pul getH(int i, int sz){
        return pul(H1[i+sz] - H1[i] * pw1[sz],
                   H2[i+sz] - H2[i] * pw2[sz]);
    }
}HS, HS2; gp_hash_table<pul, int, chash> hTable;

void Trail1(string &s, string &p){
    HS.build(s); HS2.build(p);
    pul ph = HS2.getV();

    int ans = 0;
    for(int i=s.size()-p.size(); i>=0; i--){
        pul sh = HS.getH(i, p.size());
        if(sh == ph) ans++;
    }
    cout << ans << "\n";
}

void Trail2(string &s, string &p){
    hTable.clear();
    HS.build(s); HS2.build(p);
    int n = s.size(), m = p.size();
    for(int i=n-m; i>=0; i--)
        hTable[ HS.getH(i,m) ]++;
    cout << hTable[ HS2.getV() ] << "\n";
}

int main(){

    string s, p;
    cin >> s >> p;

    /**
        find the number of string P are
        sub-string in string S
    */

    Trail1(s, p);
    Trail2(s, p);

    return 0;
}
