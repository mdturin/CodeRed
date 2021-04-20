#include "bits/stdc++.h"
using namespace std;

//for any k, 0 base, O(n);
int josephus(int n, int k){
    if(n == 1) return 0;
    return (josephus(n-1,k)+k)%n;
}

// for k=2, 0 base, O(log n);
using ll = long long;
ll josephus(ll n){
    ll p = 1; while(p<=n) p<<=1;
    return (n<<1) - p;
}

int main(int argc, const char** argv) {
    cout << josephus(14,2)+1 << endl;
    cout << josephus(14)+1 << endl;
    return 0;
}