#include "bits/stdc++.h"
using namespace std;

const int mx = 1e6+5;
using vi = vector<int>;
using pii = pair<int,int>;

int n, pos[mx];
string s, ss[101];
int c[mx], cn[mx], cnt[mx];
int sa[mx], lcp[mx], pn[mx];

void build(){
    register int i, j, k;
    s += "$"; n = s.size();
    memset(cnt, 0, mx << 2);

    for(i=0; i<n; i++) cnt[ s[i] ]++;
    for(i=1; i<128; i++) cnt[i] += cnt[i-1];
    for(i=0; i<n; i++) sa[--cnt[s[i]]] = i;

    c[sa[0]] = 0; int cls = 1;
    for(i=1; i<n; c[sa[i++]]=cls-1)
        if(s[sa[i]] != s[sa[i-1]]) cls++;

    for(j=0,k=1; k<n; j++,k<<=1){
        for(i=0; i<n; i++){
            pn[i] = sa[i] - k;
            if(pn[i] < 0) pn[i] += n;
        }

        fill(cnt, cnt+cls, 0);
        for(i=0; i<n; i++) cnt[c[pn[i]]]++;
        for(i=1; i<cls; i++) cnt[i] += cnt[i-1];
        for(i=n-1; ~i; i--) sa[--cnt[c[pn[i]]]] = pn[i];

        cn[sa[0]] = 0; cls = 1;
        for(i=1; i<n; cn[sa[i++]]=cls-1){
            pii cur = {c[sa[i]],   c[(sa[i]   + k)%n]};
            pii pre = {c[sa[i-1]], c[(sa[i-1] + k)%n]};
            if(cur != pre) cls++;
        }for(int i=0; i<n; i++) c[i] = cn[i];
    }
}

void buildLCP(){
    memset(lcp, 0, mx<<2);
    for(int i=0; i<n; i++) pn[sa[i]] = i;
    for(int i=0, j=0; i<n; i++){
        if(pn[i]==n-1){j=0; continue;}
        int k = sa[pn[i] + 1];
        while(i+j<n && j+k<n && s[i+j]==s[j+k] && s[i+j]!='$') j++;
        lcp[ pn[i]+1 ] = j; if( j ) j--;
    }
}

int main(int argc, const char** argv) {

    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int m, tc; bool flag = false;
    cin >> tc; while(tc--){
        cin >> m;
        s.clear(); s = "";
        for(int i=0,j=0; i<m; i++){
            cin >> ss[i];
            s += ss[i] + "$";
            while(j < s.size())
                pos[j++] = i;
        }s.pop_back();

        build();
        buildLCP();

        vi vis(m, 0);
        int ans = 0, unq = 0;

        for(int lw=m, hh=m; hh<n; lw++){
            while(unq < m){
                int idx = pos[sa[hh]];
                if(vis[idx]++ == 0) unq++;
                hh++;
            }
            int cur = 1e9, p = lw+1;
            for(int i=lw+1; i<hh; ++i)
                if(lcp[i] < cur)
                    cur = lcp[i], p = i;
            if(cur > ans) ans = cur;
            int idx = pos[sa[lw]];
            if(--vis[idx] == 0) unq--;
        }cout << ans << "\n";
    }

    return 0;
}

