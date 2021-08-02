#include "bits/stdc++.h"
using namespace std;

const int mx=2e6+5;

int n, fs; string s;
int ra[mx], tra[mx], c[mx];
int sa[mx], tsa[mx], lcp[mx];

void counting_sort(int k){
    int i, t, sum, m = max(256, n);
    memset(c, 0, sizeof c);
    for(i=0;     i<n; i++) c[i+k<n ? ra[i+k] : 0]++;
    for(i=sum=0; i<m; i++) t=c[i], c[i]=sum, sum+=t;
    for(i=0; i<n; i++)
        tsa[c[sa[i]+k<n ? ra[sa[i]+k] : 0]++] = sa[i];
    for(i=0; i<n; i++) sa[i] = tsa[i];
}

void buildSA(){
    register int i, k, r;
    for(i=0; i<n; i++) ra[i] = s[i];
    for(i=0; i<n; i++) sa[i] = i;
    for(k=1; k<n; k<<=1){
        counting_sort(k); counting_sort(0);
        tra[sa[0]] = r = 0;
        for(i=1; i<n; i++)
            tra[sa[i]] = (ra[sa[i]]   == ra[sa[i-1]] &&
                          ra[sa[i]+k] == ra[sa[i-1]+k]) ?
                          r : ++r;
        for(i=0; i<n; i++) ra[i] = tra[i];
        if(ra[sa[n-1]] == n-1) break;
    }
}

void buildLCP(){
    int i, l; ra[sa[0]] = -1;
    for(i=1; i<n; i++) ra[sa[i]] = sa[i-1];
    for(i=l=0; i<n; i++){
        if(ra[i] == -1){tra[i]=0; continue;}
        while(s[i+l] == s[ra[i]+l]) l++;
        tra[i] = l; if(l) l--;
    }for(i=0; i<n; i++) lcp[i] = tra[sa[i]];
}

void build(){
    s += "$";
    n = s.size();
    buildSA();
    buildLCP();
}

inline int get_root(int idx){
    return idx > fs;
}

string Longest_Common_Substring(string s1, string s2){
    fs = s1.size();
    s = s1 + "@" + s2;

    build();
    buildLCP();

    int ans = 0, pos = 0;
    for(int i=1; i<n; i++)
        if(get_root(sa[i-1]) != get_root(sa[i]))
            if(ans < lcp[i])
                ans = lcp[i], pos = sa[i];

    return s.substr(pos, ans);
}

int main(int argc, const char** argv){

    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    string s1, s2; cin >> s1 >> s2;
    cout << Longest_Common_Substring(s1, s2) << "\n";

    return 0;
}
