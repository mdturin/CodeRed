#include<bits/stdc++.h>
using namespace std;
const int mx = 2e7 + 5;

long long d[mx];
void sieve_div(){
    for(int i=1; i<mx; ++i)
    for(int j=i; j<mx; j+=i) d[j] += i;
    for(int i=3; i<mx; ++i) d[i] += d[i-1];
}

long long sum(int i, int j){return d[j] - d[i-1];}

int main(){

    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    sieve_div();
    int n; while(cin >> n, n)
        cout << d[n] << "\n";

    return 0;
}


