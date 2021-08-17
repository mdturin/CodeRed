#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const int mx = 1e6 + 5;
const int md = 1e9 + 7;

int get_phi(int n){
    int res = n;
    for(int p=2; 1LL*p*p<=n; p++){
        if(n%p) continue;
        res -= (res/p);
        while(n%p == 0) n /= p;
    }
    if(n>1) res -= (res/n);
    return res;
}

int main(int argc, const char** argv) {

    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    cout << get_phi(1e8) << "\n";

    return 0;
}
