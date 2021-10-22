#include<bits/stdc++.h>
using namespace std;
using ll = long long;
using ii = pair<int,int>;

#define ff first
#define se second

const int K  = 4;
const int mx = 2e6 + 5;
const int INF = 0x3f3f3f3f;

char s[mx], ss[mx];
struct Suffix_Automata{
    int last = 1, tot = 1;
    int c[mx], a[mx], l[mx], res[mx];
    int nxt[mx][K], link[mx], len[mx];

    inline void init(){
        for(int i=0; i<=tot; i++){
            memset(nxt[i], 0, sizeof nxt[i]);
            link[i] = len[i] = c[i] = a[i] = l[i] = res[i] = 0;
        }tot = last = 1;
    }

    inline int idx(char ch){
        if(ch == 'A') return 0;
        if(ch == 'C') return 1;
        if(ch == 'G') return 2;
        if(ch == 'T') return 3;
    }

    inline void add(int x){
        int p = last, cur = ++tot;
        last = cur; len[cur] = len[p] + 1;
        while(p && !nxt[p][x])
            nxt[p][x] = cur, p = link[p];
        if(!p) link[cur] = 1;
        else{
            int q = nxt[p][x];
            if(len[p]+1 == len[q]) link[cur] = q;
            else{
                int cln = ++tot;
                len[cln] = len[p] + 1;
                memcpy(nxt[cln], nxt[q], sizeof nxt[q]);
                link[cln] = link[q];
                link[q] = link[cur] = cln;
                while(nxt[p][x] == q)
                    nxt[p][x] = cln, p = link[p];
            }
        }
    }

    inline void Sort(int n){
        for(int i=1; i<=tot; ++i) c[len[i]]++;
        for(int i=1; i<=n;   ++i) c[i] += c[i-1];
        for(int i=1; i<=tot; ++i) a[c[len[i]]--] = i;
        memset(res, INF, sizeof res);
    }

    inline void Solve(int n){
        int p = 1, ans = 0;
        memset(l, 0, sizeof l);
        for(int i=1; i<=n; ++i){
            int x = idx(ss[i]);
            if(nxt[p][x]) p = nxt[p][x], ++ans;
            else{
                while(p && !nxt[p][x]) p = link[p];
                if(!p) p = 1, ans = 0;
                else ans = len[p]+1, p=nxt[p][x];
            }l[p] = max(l[p], ans);
        }
        for(int i=tot; i; --i){
            int x = a[i];
            res[x] = min(res[x], l[x]);
            if(l[x] && link[x])
                l[link[x]] = len[link[x]];
        }
    }

    inline int get_result(){
        int ans = 0;
        for(int i=1; i<=tot; i++)
            ans = max(ans, res[i]);
        return ans;
    }
}SAM;

int main(){

    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, tc; scanf("%d", &tc);
    while(tc--){
        SAM.init();
        scanf("%d", &n);

        scanf("%s", s+1);
        int m = strlen(s+1);
        for(int i=1; i<=m; ++i)
            SAM.add(SAM.idx(s[i]));
        SAM.Sort(m);

        for(int i=2; i<=n; ++i){
            scanf("%s", ss+1);
            m = strlen(ss + 1);
            SAM.Solve(m);
        }printf("%d\n", SAM.get_result());
    }

    return 0;
}

