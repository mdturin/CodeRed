#include<bits/stdc++.h>
using namespace std;

using ll = long long;
using vi = vector<int>;
using pii = pair<int,int>;

const int mx = 1e5+5;
const int mod = 1e9+7;
const double eps = 1e-8;
const int INF = 0x3f3f3f3f;

#define ff first
#define se second
#define clr(a) memset(a, 0, sizeof (a))

int lim;
class Automata{
public:
    struct data{
        int link, len, fpos, cnt, next[27];
        data(int _li=-1, int _le=0, int _c=0, int _p=0):
            link(_li), len(_le), cnt(_c), fpos(_p){clr(next);}
    }*node;

    int num, last;
    set< pii > base;
    int *tLen, *dist;

    void reset(){
        clr(dist);
        num=1; last=0;
        node[0]=data();
    }

    Automata(){}
    Automata(int mxLen){
        mxLen += 7; mxLen <<= 1;
        tLen = new int[mxLen];
        dist = new int[mxLen];
        node = new data[mxLen];
        reset();
    }

    void add(char ch, int idx){
        int cur=num++, k=ch-'a', p=last;
        node[cur] = data(-1, node[p].len+1, 1, idx);
        base.insert({node[cur].len, cur});

        for(; p!=-1 && !node[p].next[k]; p=node[p].link)
            node[p].next[k] = cur;

        if(p == -1) node[cur].link = 0;
        else{
            int q = node[p].next[k];
            if(node[p].len+1 == node[q].len)
                node[cur].link = q;
            else{
                int clone = num++;
                node[clone] = node[q];
                node[clone].len = node[p].len+1;
                node[clone].cnt = 0;
                node[clone].fpos = node[q].fpos;
                base.insert({node[clone].len, clone});

                for(; p!=-1 && node[p].next[k]==q; p=node[p].link)
                    node[p].next[k] = clone;
                node[q].link = node[cur].link = clone;
            }
        }
        last = cur;
    }

    void countSubStr(){
        for(auto it=base.rbegin(); it!=base.rend(); it++)
            node[node[it->se].link].cnt += node[it->se].cnt;
    }

    void distSub(int u=0){
        if(dist[u]) return; dist[u] = 1;
        for(int i=0; i<26; i++){
            int v = node[u].next[i];
            if(v){distSub(v); dist[u]+=dist[v];}
        }
    }

    void totalLength(int u=0){
        if(tLen[u]) return;
        for(int i=0; i<26; i++){
            int v = node[u].next[i];
            if(v){totalLength(v); tLen[u] += dist[v]+tLen[v];}
        }
    }

    void KthString(int k, int u, vector<char> &ans){
        if(k == 0) return;
        for(int i=0; i<26; i++){
            int v = node[u].next[i];
            if(v == 0) continue;
            if(dist[v] < k) k -= dist[v];
            else{
                ans.push_back(i + 'a');
                k--; KthString(k, v, ans);
                return;
            }
        }
    }

    int minimumRotate(int u=0, int taken=0){
        if(taken == lim) return node[u].fpos; /// lim = string size
        for(int i=0; i<26; i++){
            if(node[u].next[i]){
                int res = minimumRotate(node[u].next[i], taken+1);
                if(res != -1) return res;
            }
        }
        return -1;
    }

    int firstPosition(string p){
        int i = 0, cur = 0;
        while(i < p.size())
            cur = node[cur].next[p[i++]-'a'];
        return node[cur].fpos - p.size() + 1;
    }

    int numberOfOccurances(string p){
        int i = 0, cur = 0;
        while(i < p.size())
            cur = node[cur].next[p[i++]-'a'];
        return node[cur].cnt;
    }

    pii lcs(string p){
        int v = 0, l = 0, best = 0, pos = 0;
        for(int i=0; i<p.size(); i++){
            while(v && !node[v].next[p[i]-'a'])
                v = node[v].link, l = node[v].len;
            if(node[v].next[p[i]-'a'])
                v = node[v].next[p[i]-'a'], l++;
            if(l > best) best = l, pos = i;
        }
        return pii(pos-best+1, best);
    }
};

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    string s; cin >> s;
    int n = s.size();

    Automata mata = Automata(n);
    for(int i=0; i<n; i++)
        mata.add(s[i], i);

/**
    for smallest cyclic shift
    [ for better complexity try booth algorithms ]

    lim = n;
    mata = Automata(n+n);
    for(int i=0; i<lim; i++) mata.add(s[i], i);
    for(int i=0; i<lim; i++) mata.add(s[i], lim+i);

    int ans = minimumRotate(0, 0);
    ans = ans - lim + 1;
    cout << ans << "\n";
*/

    mata.distSub(0);
    cout << mata.dist[0] << "\n";

    mata.totalLength(0);
    cout << mata.tLen[0] << "\n";

    int tot = mata.dist[0];
    for(int i=1; i<tot; i++){
        vector<char> ans;
        mata.KthString(i, 0, ans);
        for(char c:ans) cout << c;
        cout << '\n';
    }

    string p; cin >> p;
    cout << mata.firstPosition(p) << "\n";

    mata.countSubStr();
    cout << mata.numberOfOccurances(p) << "\n";

    cin >> p;
    pii ans = mata.lcs(p);
    cout << p.substr(ans.ff, ans.se) << "\n";

    return 0;
}
