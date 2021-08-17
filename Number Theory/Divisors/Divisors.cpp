#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const int mx = 1e6 + 5;
const int md = 1e9 + 7;

vector<ll> get_divisors(ll x){
    vector<ll> ans;
    int lim = sqrtl(x);
    for(ll i=1; i<=lim; i++){
        if(x%i == 0){
            ans.push_back(i);
            if(i != x/i)
                ans.push_back(x/i);
        }
    }
    sort(ans.begin(), ans.end());
    return move(ans);
}


int main(int argc, const char** argv) {

    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    vector<ll> d = get_divisors(1e6);
    for(int u : d)
        cout << u << " ";
    cout << endl;

    return 0;
}
