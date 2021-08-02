#include "bits/stdc++.h"
using namespace std;
using ll = long long;
using ii = pair<int,int>;

#define ff first
#define se second

const int mx = 1e6 + 5;

struct state{
    int len, link, fpos; ll tot;
    map<char, int> next;
} st[mx << 1];

long long res = 0;
int sz, last, cnt[mx<<1];

inline void sa_extend(char c){
    int cur = sz++, p = last; cnt[cur] = 1;
    st[cur] = {st[p].len+1, -1, st[p].len+1};
    for(; ~p && !st[p].next.count(c); p=st[p].link){
        st[p].next[c] = cur;
        st[cur].tot += st[p].tot;
        res += st[p].tot;
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
            st[cln].len = st[p].len+1;
            st[cln].tot = 0;
            for(; ~p && st[p].next[c]==q; p=st[p].link){
                st[p].next[c] = cln;
                st[q].tot -= st[p].tot;
                st[cln].tot += st[p].tot;
            }st[q].link = st[cur].link = cln;
        }
    }last = cur;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie( nullptr );

    string s; while(cin >> s){

        for(int i=0; i<sz; i++)
            cnt[i]=0, st[i].next.clear();

        sz = 1; last = 0; res = 0;
        st[0] = {0,-1}; st[0].tot = 1;

        for(char &c : s){
            sa_extend(c);
            cout << res << "\n";
        }
    }

    return 0;
}

