#include<bits/stdc++.h>
using namespace std;
using ll = long long;

const int mx = 1e6 + 5;
const int md = 1e9 + 7;

int mark[mx];
vector<int> prime;

void LinearSieve(){
    for(int i=2, j=0; i<mx; i++, j=0){
        if(!mark[i]){mark[i] = i; prime.push_back(i);}
        while(j<prime.size() && prime[j]<=mark[i] && (ll)i*prime[j]<mx)
            mark[i * prime[j]] = prime[j], j++;
    }
}

ll sum_of_divisors(ll x){
    ll ans = 1;
    while(x > 1){
        int p = mark[x];
        ll y = p;
        while(x % p == 0)
            x /= p, y *= (ll)p;
        ans *= (y-1)/(p-1);
    }return ans;
}

int main(){

    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    LinearSieve();
    cout << sum_of_divisors(220) << endl;

    return 0;
}

