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

vector<int> sa, lcp;
int n, sz, last, cnt[mx<<1];

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

void dfs(int u, int m){
    if(m == 0){
        sa.push_back(st[u].fpos - n);
        return;
    }for(auto p : st[u].next)
        dfs(p.second, m-1);
}

void Build_LCP(string &s){
    vector<int> pn(n+5, 0);
    lcp = vector<int>(n+5, 0);
    for(int i=0; i<n; i++) pn[sa[i]] = i;
    for(int i=0,j=0; i<n; i++){
        if(pn[i]==n-1){j=0; continue;}
        int k = sa[pn[i] + 1];
        while(i+j<n && j+k<n && s[i+j]==s[j+k]) j++;
        lcp[ pn[i]+1 ] = j; if( j ) j--;
    }
}

void Build_Suffix_Array(string s){
    build(s); sa_extend('#');
    s += "$"; n = s.size();
    for(int i=0; i<s.size(); i++)
        sa_extend(s[i]);

    dfs(0, n); // s.pop_back();
    sa.erase(find(sa.begin(), sa.end(), n));
    Build_LCP(s);

    for(int i=0; i<n; i++)
        cout << i << " "
             << sa[i] << " "
             << lcp[i] << " "
             << s.substr(sa[i])
             << "\n";
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(nullptr);

    string s = "abaab";
    Build_Suffix_Array(s);

    return 0;
}

