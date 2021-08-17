#include <bits/stdc++.h>
using namespace std;
using ll = long long;

// Greatest Common Divisor (GCD)
template<typename T = int>
T gcd(T a, T b){
    return b == 0 ? a : gcd(b, a%b);}

// Least Common Multiple (LCM)
template<typename T = int>
ll lcm(T a, T b){
    return (ll)a / gcd(a, b) * b;}

int main(int argc, const char** argv) {

    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    cout << lcm(5, 10) << endl;

    return 0;
}
