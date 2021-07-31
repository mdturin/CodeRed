#include "bits/stdc++.h"
using namespace std;
using ii = pair<int,int>;

#define ff first
#define se second

const int mx = 1e5 + 5;

struct state{
    int len,link,fpos;
    map<char, int>next;
} st[mx << 1];
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

string Longest_Common_Substring(string &pat){
    int u, l, ans, pos;
    u = l = ans = pos = 0;
    for(int i=0; i<pat.size(); i++){
        while(u && !st[u].next.count(pat[i]))
            u = st[u].link, l = st[u].len;
        if(st[u].next.count(pat[i]))
            u = st[u].next[pat[i]], l++;
        if(l > ans) ans = l, pos = i;
    }return pat.substr(pos-ans+1, ans);
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie( nullptr );

    string s = "hello_helloworld";
    string p = "gelloword";

    build(s);
    cout << Longest_Common_Substring(p) << "\n";

    return 0;
}

