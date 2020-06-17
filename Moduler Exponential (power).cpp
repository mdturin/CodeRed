#include "bits/stdc++.h"
using namespace std;

template <typename T>
T power(T v, T p, T m) {
    v %= m; T r = 1;
    while (p > 0) {
        if (p & 0x1)
            r = (r*1LL*v)%m;
        v = (v*v)%m; p >>= 1;
    }
    return r;
}

int main(int argc, const char** argv) {
    return 0;
}
