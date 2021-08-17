#include <bits/stdc++.h>
using namespace std;

const int mx = 1e6 + 5;
const int md = 1e9 + 7;

int divisors[mx];
inline void divisors_sieve(){
    for(int i=1; i<mx; ++i)
    for(int j=i; j<mx; j+=i)
        divisors[j]++;
}

int main(){

    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    divisors_sieve();
    for(int i=1; i<=10; ++i)
        cout << divisors[i] << " ";

    return 0;
}

