#include "bits/stdc++.h"
using namespace std;
#define rint register int

#define ff first
#define se second
const int mx = 1e5+5;
using ii = pair<int,int>;

struct state {
    int len,link,fpos;
    map<char,int>next;
} st[mx << 1];
int sz, last, cnt[mx<<1];

void sa_extend(char c) {
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
    }
    last = cur;
}

vector<int> vec[mx];
void build(string &s){
    for(rint i=0; i<sz; i++) 
        cnt[i]=0, st[i].next.clear();

    st[0] = {0,-1}; sz = 1; last = 0;
    for(rint i=0; i<s.size(); i++) 
        sa_extend(s[i]);
}

void countHelper(int n){
    for(rint i=sz-1; i>0; i--)
        vec[ st[i].len ].push_back(i);
    for(rint i=n; i>0; i--){
        for(int p : vec[i]){
            if(st[p].link == -1) continue;
            cnt[st[p].link] += cnt[p];
            st[st[p].link].fpos = max(
                st[p].fpos,
                st[ st[p].link ].fpos
            );
        }
        vec[i].clear();
    }
}

vector<int> terminals;
void findTerminals(){
    int p = last;
    while(p > 0) {
        terminals.push_back(p);
        p = st[p].link;
    }
}

int dss[mx<<1]; /// distinct substring
int dssFun(int u){
    if(dss[u]) return dss[u];

    dss[u] = 1;
    for(auto p : st[u].next)
        dss[u] += dssFun(p.second);
    return dss[u];
}

int totLen[mx<<1];
int totFun(int u){
    if(totLen[u]) return totLen[u];

    totLen[u] = dss[u]-1;
    for(auto p : st[u].next)
        totLen[u] += totFun(p.second);
    return totLen[u];
}

vector<char> kthSub;
int kthSubString(int u, int k){
    if(k == 0) return 1;
    if(dss[u]-1 < k) return -1;
    for(auto p : st[u].next){
        if(dss[p.se] < k) k -= dss[p.se];
        else{
            kthSub.push_back(p.ff);
            kthSubString(p.se, k-1);
            return 1;
        }
    }
    return 0;
}

int kthSubString2(int k){
    if(k == 0) return 1;
    if(dss[0]-1 < k) return 0;

    int u = 0, i;
    while( k ){
        for(i='a'; i<='z'; i++){
            int v = st[u].next[i];
            if(!v) continue;
            if(dss[v] < k) k -= dss[v];
            else break;
        }
        kthSub.push_back(i);
        k--; u = st[u].next[i];
    }
    return 1;
}

int smallestCyclicShift(string &s){

    int len = s.size();

    /// resetting
    st[0] = {0,-1}; sz = 1; last = 0;
    for(int i=0; i<len; i++) sa_extend(s[i]);
    for(int i=0; i<len; i++) sa_extend(s[i]);

    int u = 0;
    for(int i=0; i<len; i++)
        u = st[u].next.begin()->se;
    return st[u].fpos - len + 1; /// 0-index
}

int firstOccur(string s, string p){
    build(s); int u = 0;
    for(int i=0; i<p.size(); i++)
        u = st[u].next[p[i]];
    return st[u].fpos - p.size() + 1;
}

int numOfOccur(string s, string p){
    build(s); 
    countHelper(s.size());

    int u = 0;
    for(int i=0; i<p.size(); i++)
        u = st[u].next[p[i]];
    return cnt[u];
}

string lcs(string s, string p){
    build(s);
    int u, l, ans, pos;
    u = l = ans = pos = 0;
    for(int i=0; i<p.size(); i++){
        while(u && !st[u].next.count(p[i]))
            u = st[u].link, l = st[u].len;
        if(st[u].next.count(p[i]))
            u = st[u].next[p[i]], l++;
        if(l > ans) ans = l, pos = i;
    }
    return p.substr(pos-ans+1, ans);
}

int main(int argc, const char** argv) {

    srand( time(0) );

    ios_base::sync_with_stdio(0);
    cin.tie( nullptr );

    string s = "ababa"; build(s);
    
    findTerminals();
    for(int u : terminals)
        cout << u << " ";
    cout << "\n";

    cout << dssFun(0) << "\n"; /// with empty string
    cout << totFun(0) << "\n";

    for(int i=0; i<15; i++){
        kthSub.clear();
        cout << i << " --> ";

        if(!kthSubString2(i)){
            cout << "no substring\n\n";
            continue;
        }

        if(!kthSub.size())
            cout << "null";
        for(auto c : kthSub)
            cout << c;
        cout << "\n\n";
    } 

    cout << smallestCyclicShift(s) << "\n\n";
    cout << firstOccur("worldhelloworldhello", "hello") << "\n\n";
    cout << numOfOccur("worldhelloworldhelloworl", "world") << "\n\n";
    cout << lcs("abracadabra", "dabrasdfabra") << "\n\n";

    return 0;
}
