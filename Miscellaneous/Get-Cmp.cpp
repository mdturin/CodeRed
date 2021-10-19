#include<bits/stdc++.h>
using namespace std;

const int mod = 1e9 + 7;
const int mx  = 2e5 + 5;

template<typename T> struct get_cmp{
    function<T(const T, const T)> fsum = [&](const T u, const T v){return u + v;};
    function<T(const T, const T)> fmax = [&](const T u, const T v){return max(u, v);};
    function<T(const T, const T)> fmin = [&](const T u, const T v){return min(u, v);};
    function<T(const T, const T)> fgcd = [&](const T u, const T v){return __gcd(u, v);};
};get_cmp<int> cmp;

int main(){

    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    return 0;
}