#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const int mx = 1e6 + 5;
const int md = 1e9 + 7;

int phi[mx];
void phi_sieve(){
    for(int i=1; i<mx; i++) phi[i] = i;
    for(int i=2; i<mx; i++)
    if(phi[i] == i)
        for(int j=i; j<mx; j+=i)
            phi[j] -= phi[j]/i;
}

int main(int argc, const char** argv) {

    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    phi_sieve();
    int n; while(cin >> n){
        assert(n < mx);
        cout << phi[n] << "\n";
    }

    return 0;
}

