#include<bits/stdc++.h>
using namespace std;

const int md = 1e9 + 7;
const int mx = 1e5 + 7;

using ll = long long;
using pll = pair<ll, ll>;

// Must Call Build Function
namespace HashSpace{

    const ll B = 347;
    vector<pll> pw(mx);
    const ll MOD1 = 1e9+7;
    const ll MOD2 = 1e9+9;
    const pll M = {MOD1, MOD2};

    pll operator+ (pll a, ll x)     {return {a.first + x, a.second + x};}
    pll operator- (pll a, ll x)     {return {a.first - x, a.second - x};}
    pll operator* (pll a, ll x)     {return {a.first * x, a.second * x};}
    pll operator+ (pll a, pll x)    {return {a.first + x.first, a.second + x.second};}
    pll operator- (pll a, pll x)    {return {a.first - x.first, a.second - x.second};}
    pll operator* (pll a, pll x)    {return {a.first * x.first, a.second * x.second};}
    pll operator% (pll a, pll m)    {return {a.first % m.first, a.second % m.second};}

    // init function, must need to call first;
    void build(){
        pw[0] = {1, 1};
        for(int i=1; i<mx; ++i)
            pw[i] = (pw[i-1] * B) % M;
    }

    // Return 1 index hash list
    vector<pll> GetHashList(string &s){
        vector<pll> ans(s.size()+1);
        ans[0] = {0, 0};
        for(int i=1; i<=s.size(); ++i)
            ans[i] = (ans[i-1] * B + s[i-1]) % M;
        return move(ans);
    }

    // Return 1 index reverse hash list
    vector<pll> GetHashListR(string &s){
        int n = s.size();
        vector<pll> ans(n+1);
        ans[0] = {0, 0};
        for(int i=1; i<=n; ++i)
            ans[i] = (ans[i-1] * B + s[n-i]) % M;
        return move(ans);
    }

    // Calculates hash value for s[l...r] (1 indexed)
    pll GetSubstringHash(vector<pll> &H, int l, int r){
        return ((H[r] - H[l-1] * pw[r-l+1])%M + M) % M;}

    // Calculates reverse hash value for s[l...r] (1 indexed)
    pll GetSubstringHashR(vector<pll> &RH, int n, int l, int r){
        return GetSubstringHash(RH, n-r+1, n-l+1);}
}

int main(){

    ios_base::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);

    HashSpace::build();

    string s = "HelloWorld";
    auto H = HashSpace::GetHashList(s);
    auto RH = HashSpace::GetHashListR(s);

    for(auto &x : H){
        cout << x.first << " " << x.second << endl;
    }
    
    auto val = HashSpace::GetSubstringHash(H, 6, 10);
    cout << val.first << " " << val.second << endl;

    string str = "World";
    H = HashSpace::GetHashList(str);
    cout << H.back().first << " "
         << H.back().second << endl;

    return 0;
}