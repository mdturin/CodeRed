#include "bits/stdc++.h"
using namespace std;

using vi = vector<int>;
using ii = pair<int,int>;

const int mx = 1e6+5;
const int lgn= __lg(mx)+5;

string s; int n;
int par[lgn][mx];
int sa[mx], lcp[mx];
int tpar[mx], tsa[mx], cnt[mx];

void build(){

    s+="$"; n=s.size();
    register int i, k;
    int cls = 1; ii x, y;
    memset(cnt, 0, mx<<2);
    
    for(i=0; i<n;   i++) cnt[ s[i] ]++;
    for(i=1; i<256; i++) cnt[i] += cnt[i-1];
    for(i=0; i<n;   i++) sa[ --cnt[ s[i] ] ] = i;
    for(i=0; i<n; par[0][sa[i++]] = cls-1)
        if(i && s[sa[i]] != s[sa[i-1]]) cls++;

    for(k=0; (1<<k)<n; k++){
        for(i=0; i<n; i++){
            tsa[i] = sa[i] - (1<<k);
            if(tsa[i]<0) tsa[i] += n;}
        
        memset(cnt, 0, cls<<2);
        for(i=0; i<n;   i++) cnt[ par[k][tsa[i]] ]++;
        for(i=1; i<cls; i++) cnt[i] += cnt[i-1];
        for(i=n-1; ~i;  i--) sa[--cnt[par[k][tsa[i]]]] = tsa[i];
        
        tpar[sa[0]] = 0; cls = 1;
        for(i=1; i<n; tpar[sa[i++]] = cls-1){
            x = {par[k][sa[i]],   par[k][(sa[i]   + (1<<k))%n]};
            y = {par[k][sa[i-1]], par[k][(sa[i-1] + (1<<k))%n]};
            if(x != y) cls++;
        }for(i=0; i<n; i++) par[k+1][i] = tpar[i];
    }
}

void buildLCP(){
    memset(lcp, 0, mx<<2);
    for(int i=0; i<n; i++) tpar[sa[i]] = i;
    for(int i=0, j=0; i<n; i++){
        if(tpar[i]==n-1){j=0; continue;}
        int k = sa[tpar[i] + 1];
        while(i+j<n && j+k<n && s[i+j]==s[j+k]) j++;
        lcp[ tpar[i]+1 ] = j; if( j ) j--;
    }
}

// compare subarray in O(1)
int compare(int i, int j, int len){
    int k = __lg(len);
    ii x = {par[k][i], par[k][(i+len-(1<<k))%n]};
    ii y = {par[k][j], par[k][(j+len-(1<<k))%n]};
    return (x < y) ? -1 : (x > y);
}

// LCP of any to index in O( log n )
int LCP(int i, int j){
    if(i == j) return n-j-1; // make sure what u return
    int ans = 0, k = __lg(n);
    for(int v=(1<<k); k>=0 && i<n && j<n; k--,v>>=1)
        if(par[k][i] == par[k][j])
            ans+=v, i+=v, j+=v;
    return ans;
}

int lower_bound(int idx, int len){
    int lw = 1, hh = s.size() - 1, ans = 0;
    while(lw <= hh){
        int mid = (lw + hh) / 2;
        if(compare(sa[mid], idx, len) >= 0)
            ans = mid, hh = mid - 1;
        else lw = mid + 1;
    }return ans;
}

int upper_bound(int idx, int len){
    int lw = 1, hh = s.size() - 1, ans = 0;
    while(lw <= hh){
        int mid = (lw + hh) / 2;
        if(compare(sa[mid], idx, len) <= 0)
            ans = mid + 1, lw = mid + 1;
        else hh = mid - 1;
    }return ans;
}

int main(int argc, const char** argv) {

    s = "abracadabra";

    build();
    buildLCP();

    cout << s << "\n"; 
    for(int i=0; i<s.size(); i++)
        cout << setw(3) << i << ' '
             << setw(3) << sa[i] << ' '
             << setw(3) << lcp[i] << ' '
             << s.substr(sa[i]) << "\n";

    for(int i=0; i<n; i++)
    for(int j=i; j<n; j++)
        cout << i << ' ' << j << ' ' << LCP(sa[i], sa[j]) << "\n";

    return 0;
}