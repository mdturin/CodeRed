#include "bits/stdc++.h"
using namespace std;
using ii = pair<int,int>;

#define ff first
#define se second

string res;
const int mx = 1e5 + 5;

struct state{
    int len,link,fpos;
    map<char, int>next;
} st[mx << 1];

int dss[mx<<1];
int sz, last, cnt[mx<<1];

inline void sa_extend(char c){
    int cur = sz++, p = last; cnt[cur] = 1;
    st[cur] = {st[p].len+1, -1, st[p].len+1};
    for(; ~p && !st[p].next.count(c); p=st[p].link)
        st[p].next[c] = cur;
    if(p == -1) st[cur].link = 0;
    else {
        int q = st[p].next[c];
        if(st[p].len+1 == st[q].len) st[cur].link = q;
        else {
            int cln = sz++;
            cnt[cln] = 0;
            st[cln] = st[q];
            st[cln].len = st[p].len+1;

            for(; ~p && st[p].next[c]==q; p=st[p].link)
                st[p].next[c] = cln;
            st[q].link = st[cur].link = cln;
        }
    }last = cur;
}

inline void build(string &s){
    for(int i=0; i<sz; i++)
        cnt[i]=0, st[i].next.clear();
    st[0] = {0,-1}; sz = 1; last = 0;
    for(int i=0; i<s.size(); i++)
        sa_extend(s[i]);
}

int Distinct_Number_Of_Substring(int u){
    if(dss[u]) return dss[u];
    dss[u] = 1;
    for(auto p : st[u].next)
        dss[u] += Distinct_Number_Of_Substring(p.second);
    return dss[u];
}

// Must Call Distinct Number Of Substring
bool Kth_Substring_Recursive(int u, int k){
    if(k == 0) return true;
    if(dss[u]-1 < k) return false;
    for(auto p : st[u].next){
        if(dss[p.se] < k) k -= dss[p.se];
        else{
            res.push_back(p.ff);
            Kth_Substring_Recursive(p.second, k-1);
            return true;
        }
    }return false;
}

bool Kth_Substring_Iterative(int k){
    if(k == 0) return true;
    if(dss[0]-1 < k) return false;

    int u = 0; char i;
    while( k > 0 ){
        for(i='a'; i<='z'; i++){
            auto it = st[u].next.find(i);
            if(it == st[u].next.end())
                continue;
            int v = it->second;
            if(dss[v] < k) k -= dss[v];
            else break;
        }res.push_back(i);
        k--; u = st[u].next[i];
    }return true;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie( nullptr );

    string s = "abcdef";

    build(s);
    Distinct_Number_Of_Substring(0);

    while(res.size()) res.pop_back();
    if(Kth_Substring_Iterative(10))
        cout << res << "\n";

    while(res.size()) res.pop_back();
    if(Kth_Substring_Recursive(0, 10))
        cout << res << "\n";


    return 0;
}

