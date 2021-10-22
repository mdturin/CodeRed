#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const int mx = 1e6 + 5;
const int md = 1e9 + 7;

bool is_prime(int x){
    if(x <= 3) return x >= 2;
    if(x % 2 == 0) return false;
    if(x % 6 % 4 != 1) return (x|1) == 3;
    for(int i=5; 1LL*i*i<=x; i+=2)
        if(x % i == 0)
            return false;
    return true;
}

int main(int argc, const char** argv) {

    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    cout << is_prime(9371) << "\n";

    return 0;
}
