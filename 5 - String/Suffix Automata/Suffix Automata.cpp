#include "bits/stdc++.h"
using namespace std;
using ll = long long;
using ii = pair<int,int>;

#define ff first
#define se second

const int mx = 1e6 + 5;

struct state{
    int len, link, fpos;
    map<char, int> next;    /// Child, TLE? Use Static
    long long dist_substr;  /// Distinct Substring
} st[mx << 1];

int sz, last, cnt[mx<<1];
long long tot_dist_substr;  /// # of total distinct substring

inline void sa_extend(char c){
    int cur = sz++, p = last; cnt[cur] = 1;
    st[cur] = {st[p].len+1, -1, st[p].len+1};
    for(; ~p && !st[p].next.count(c); p=st[p].link){
        st[p].next[c] = cur;
        tot_dist_substr += st[p].dist_substr;
        st[cur].dist_substr += st[p].dist_substr;
    }
    if(p == -1) st[cur].link = 0;
    else{
        int q = st[p].next[c];
        if(st[p].len+1 == st[q].len){
            st[cur].link = q;
        }else{
            int cln = sz++;
            cnt[cln] = 0;
            st[cln] = st[q];
            st[cln].dist_substr = 0;
            st[cln].len = st[p].len+1;
            for(; ~p && st[p].next[c]==q; p=st[p].link){
                st[p].next[c] = cln;
                st[q].dist_substr -= st[p].dist_substr;
                st[cln].dist_substr += st[p].dist_substr;
            }st[q].link = st[cur].link = cln;
        }
    }last = cur;
}

inline void build(string &s){
    for(int i=0; i<sz; i++)
        cnt[i]=0, st[i].next.clear();
    sz = 1; last = tot_dist_substr = 0;
    st[0] = {0,-1}; st[0].dist_substr = 1;
    for(int i=0; i<s.size(); i++){
        sa_extend(s[i]);
//        cout << tot_dist_substr << "\n";
    }
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie( nullptr );

    string s = "abcdef";
    build(s);

    return 0;
}
