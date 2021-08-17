#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const int mx = 1e6 + 5;
const int md = 1e9 + 7;

template<typename T = int>
vector<T> get_divisors(T x){
    vector<T> ans;
    T lim = sqrtl(x);
    for(T i=1; i<=lim; i++){
        if(x % i) continue;
        ans.push_back(i);
        if(i != x/i)
            ans.push_back(x/i);
    }sort(ans.begin(), ans.end());
    return move(ans);
}

int main(int argc, const char** argv) {

    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    vector<int> d = get_divisors<int>(1e6);
    for(int u : d)
        cout << u << " ";
    cout << endl;

    return 0;
}
