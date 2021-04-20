#include "bits/stdc++.h"
using namespace std;

using ll = long long;

// greatest common divisor (gcd)
ll gcd(ll a, ll b){return b==0?a:gcd(b, a%b);}

// least common multiple (lcm)
ll lcm(ll a, ll b){return a/gcd(a,b) * b;}

int main(int argc, const char** argv) {
    return 0;
}