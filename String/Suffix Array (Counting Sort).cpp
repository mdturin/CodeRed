#include "bits/stdc++.h"
using namespace std;

const int mx=1e5+5;

int n; string s;
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
    }
    for(i=0; i<n; i++) lcp[i] = tra[sa[i]];
}

void build(){
    s += "$";
    n = s.size();
    buildSA();
    buildLCP();
}

int main(int argc, const char** argv) {

    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    s = "gagagacacaca"; build();

    for(int i=0; i<n; i++)
        cout << setw(3) << i << ' '
             << setw(3) << sa[i] << ' '
             << setw(3) << lcp[i] << ' '
             << s.substr(sa[i]) << "\n";

    return 0;
}