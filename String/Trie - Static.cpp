#include<bits/stdc++.h>
using namespace std;
using ll = long long;

const int child = 26;
const int mx = 5e5 + 5;
const int mxt = mx * child;

int sz, t[mxt][child], cnt[mxt];

inline void init(){
    sz = 1; cnt[sz] = 0;
    memset(t[sz], 0, sizeof t[sz]);
}

inline void clr(int p, int u){
    t[p][u] = ++sz; cnt[sz] = 0;
    memset(t[sz], 0, sizeof t[sz]);
}

inline int get_val(char c){
    return c - 'a';
}

inline void add(string &s){
    int p = 1;
    for(char c : s){
        int u = get_val(c);
        if(!t[p][u]) clr(p, u);
        p = t[p][u];
    }cnt[p]++;
}

inline bool query(string &s){
    int p = 1;
    for(char c : s){
        int u = get_val(c);
        if(!t[p][u])
            return false;
        p = t[p][u];
    }cnt[p] > 0;
}

int main(){

    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    init(); // must

    return 0;
}

