#include "bits/stdc++.h"
using namespace std;

#define sq(x) (x*x) 
using ll = long long;
using pii = pair<int,int>;

const int mx = 1e5+5;
const int mod = 1e9+7;

/**
    Cycle Finding
    Complexity : O(mod)
    lets assume,
        first value = x0;
        and the next value is f(x0)
        
    We have to find the index and 
    the total length of cycle
    
    We can use floyd cycle algo,
    for finding the number of index,
    from starting index and the total
    length of the cycle.
*/

/// lets say f(x) = (2x^2 + 3x + 5)%97;
ll f(ll x){
    return (2*sq(x) + 3*x + 5)%97;}

pii isCycleFloyd(ll x){
    ll t = f(x);
    ll h = f(f(x));
    while(t != h){
        t = f(t);
        h = f(f(h));
    }
    int cycle_index = 0; h = x;
    while(t != h){
        t = f(t);
        h = f(h);
        cycle_index++;
    }
    int total_length = 1; h = f(t);
    while(t != h){
        h = f(h);
        total_length++;
    }
    return {cycle_index, total_length};
}

int main(int argc, const char** argv) {
    return 0;
}