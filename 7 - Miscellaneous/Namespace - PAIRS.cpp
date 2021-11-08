#include<bits/stdc++.h>
using namespace std;

using ll  = long long;
using pll = pair<ll, ll>;

namespace pairs{
    #define F  first
    #define S  second
    #define PT template<typename T>

    PT pll operator + (pll x, T y){return {x.F+y, x.S+y};}
    PT pll operator - (pll x, T y){return {x.F-y, x.S-y};}
    PT pll operator * (pll x, T y){return {x.F*y, x.S*y};}
    pll operator + (pll x, pll y){return {x.F+y.F, x.S+y.S};} 
    pll operator - (pll x, pll y){return {x.F-y.F, x.S-y.S};} 
    pll operator * (pll x, pll y){return {x.F*y.F, x.S*y.S};} 
    pll operator % (pll x, pll y){return {x.F%y.F, x.S%y.S};} 

    PT pll power(pll a, T p, pll M){
        pll ans = {1, 1};
        while(p > 0){
            if(p & 1) 
                ans = (ans * a) % M;
            p >>= 1; a = (a * a) % M;
        }return ans;
    }

    pll inv(pll a, pll M){
        return power(a, 1LL*(M.F-1)*(M.S-1)-1, M);}

    ostream & operator << (ostream &os, pll x){
        return os << "(" << x.first << ", " << x.second << ")";}
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);

    return 0;
}