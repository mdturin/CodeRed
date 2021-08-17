#include <bits/stdc++.h>
using namespace std;

const int mx = 1e6 + 5;
const int md = 1e9 + 7;

template <typename T>
T power(T v, T p, T m=md) {
    v %= m; T r = 1;
    while (p > 0){
        if (p & 1)
            r = (1LL * r * v) % m;
        v = (1LL * v * v) % m; p >>= 1;
    }return r;
}

int main(int argc, const char** argv) {

    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    return 0;
}
