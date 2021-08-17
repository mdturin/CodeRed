#include <bits/stdc++.h>
using namespace std;

// Greatest Common Divisor (GCD)
template<typename T = int>
T gcd(T a, T b){
    return b == 0 ? a : gcd(b, a%b);}

int main(int argc, const char** argv) {

    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    cout << gcd(5, 10) << endl;
    cout << __gcd(5, 10) << endl; // builtin

    return 0;
}
