#include "bits/stdc++.h"
using namespace std;

using ll = long long;
const ll mod = 1e9+7;
const int mx = 1e5+5;

template <typename T>
T power(T val, T p, T mod) {
    val %= mod;
    T result = 1;
    while (p > 0) {
        if (p & 0x1)
            result = (result*val)%mod;
        val = (val*val)%mod;
        p >>= 1;
    }
    return result;
}

// simple way :)
ll inverse(ll x){return power(x, mod-2, mod);}

// you can find all inverse in O(n)
int inv[mx];
void moduleMod(){
    inv[1] = 1%mod;
    for(int i=2; i<mx; i++)
        inv[i] = (mod - (mod/i) * inv[mod%i]%mod)%mod;
}

int main(int argc, const char** argv) {
    return 0;
}