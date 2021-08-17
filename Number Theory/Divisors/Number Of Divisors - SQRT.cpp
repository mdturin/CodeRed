#include<bits/stdc++.h>
using namespace std;
using ll = long long;
using ull = unsigned long long;

const int mx = 1e6 + 5;
const int md = 1e9 + 7;

int mark[mx];
vector<int> prime;

void LinearSieve(){
    for(int i=2, j=0; i<mx; i++, j=0){
        if(!mark[i]){mark[i] = i; prime.push_back(i);}
        while(j<(prime.size()) && prime[j]<=mark[i] && (ll)i*prime[j]<mx)
            mark[i * prime[j]] = prime[j], j++;
    }
}

ull number_of_divisors(ull x){
    ull ans = 1LL;
    for(int p : prime){
        if(1LL*p*p > x) break;
        ll cnt = 1LL;
        while(x%p == 0)
            x /= p, cnt++;
        ans *= cnt;
    }

    if(x != 1) ans <<= 1;
    return ans;
}

int main(){

    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    LinearSieve(); // Store All Prime Upto MX

    int tc; cin >> tc;
    while(tc--){
        ull n; cin >> n;
        cout << number_of_divisors(n) << "\n";
    }

    return 0;
}
