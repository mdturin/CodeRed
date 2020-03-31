#include "bits/stdc++.h"
using namespace std;

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

int main(int argc, const char** argv) {
    return 0;
}