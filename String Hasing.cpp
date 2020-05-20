#include<bits/stdc++.h>
#include<ext/pb_ds/assoc_container.hpp>

using namespace std;
using namespace __gnu_pbds;

const int mx = 1e6 + 10;
#define rint register int
using ull = unsigned long long;

struct chash {
    const int RANDOM = (long long)(make_unique<char>().get()) ^ chrono::high_resolution_clock::now().time_since_epoch().count();
    static unsigned long long hash_f(unsigned long long x) {
        x += 0x9e3779b97f4a7c15;
        x = (x ^ (x >> 30)) * 0xbf58476d1ce4e5b9;
        x = (x ^ (x >> 27)) * 0x94d049bb133111eb;
        return x ^ (x >> 31);
    }
    ull operator()(ull x) const { return hash_f(x)^RANDOM; }
};

struct HASH{
    int n; ull base=31, pw[mx], H[mx], RH[mx];
    HASH(){pw[0]=1; for(rint i=1; i<mx; i++) pw[i]=(pw[i-1]*base);}
    inline void build(string &s){
        n = s.size(); RH[0] = H[0] = 0;
        for(rint i=0; i<n; i++)  H[i+1] = H[i]  * base + s[i];
        for(rint i=0; i<n; i++) RH[i+1] = RH[i] * base + s[n-i-1];
    }
    inline ull  getV(){return (H[n]);}
    inline ull  getH(int i, int sz){return ( H[i+sz] -  H[i] * pw[sz]);}
    inline ull getRH(int i, int sz){return (RH[i+sz] - RH[i] * pw[sz]);}
}HS, HS2; gp_hash_table<ull, int> hTable;

void Trail1(string &s, string &p){
    HS.build(s); HS2.build(p);
    ull ph = HS2.getV();

    int ans = 0;
    for(int i=s.size()-p.size(); i>=0; i--){
        ull sh = HS.getH(i, p.size());
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
