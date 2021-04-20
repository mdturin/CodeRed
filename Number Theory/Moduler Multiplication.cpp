#include "bits/stdc++.h"
using namespace std;

using ll = long long;
ll multiply(ll a, ll b, ll mod){
    ll res = 0; a %= mod; b %= mod;
    while(b){
        if(b & 0x1)
            res = (res + a)%mod;
        b >>= 1;
        if(a < mod-a) a<<=1;
        else a -= (mod-a);
    }
    return res;
}

int main(int argc, const char** argv) {
    return 0;
}