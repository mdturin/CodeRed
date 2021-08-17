#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const int mx = 1e6 + 5;
const int md = 1e9 + 7;

template<typename T = int>
vector<T> get_factorize(T n){
    vector<T> f;
    while(n%2 == 0)
        f.push_back(2), n >>= 1;
    for(T i=3; (ll)i*i<=n; i+=2)
        while(n%i == 0)
            f.push_back(i), n /= i;
    if(n>1) f.push_back(n);
    return move(f);
}

int main(int argc, const char** argv) {

    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    vector<int> f = get_factorize<int>(1e8);
    for(int u : f)
        cout << u << " ";

    return 0;
}
