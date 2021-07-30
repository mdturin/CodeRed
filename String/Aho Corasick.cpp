#include<bits/stdc++.h>
using namespace std;

using ll = long long;
using vi = vector<int>;

const int mx = 2e5+5;
const int mod = 1e9+7;
const double eps = 1e-8;
const int INF = 0x3f3f3f3f;

const int mxc = 26; // MUST SET MAXIMUM CHILD
struct state{
    int link; vector<int> nxt, leaf;
    state(int p=0):leaf(0),link(p),nxt(mxc,0){}
};vector<state> trie; // MUST CLEAR & EMPLACE BACK

// DEFINE CHILD VALUE
int get_child(char c){
    return c - 'a';
}

void add(string &word, int idx){
    int u = 0;
    for(char &ch : word){
        int c = get_child(ch);
        if(!trie[u].nxt[c]){
            trie[u].nxt[c] = trie.size();
            trie.emplace_back();
        }u = trie[u].nxt[c];
    }trie[u].leaf.push_back(idx);
}

void build(){
    queue<int> q;
    for(int i=0; i<mxc; i++){
        int u = trie[0].nxt[i];
        if(u){
            q.push(u);
            trie[u].link = 0;
        }
    }

    while(q.size()){
        int u = q.front(); q.pop();
        for(int i=0; i<mxc; i++)
        if(trie[u].nxt[i]){
            int v = trie[u].link;
            while(v && !trie[v].nxt[i])
                v = trie[v].link;
            v = trie[v].nxt[i];
            trie[trie[u].nxt[i]].link = v;
            for(int &id:trie[v].leaf)
                trie[trie[u].nxt[i]].leaf.push_back(id);
            q.push(trie[u].nxt[i]);
        }
    }
}

int findNext(int u, int c){
    while(u && !trie[u].nxt[c])
        u = trie[u].link;
    return trie[u].nxt[c];
}

int ans[mx];
void search(string &text){
    int u = 0;
    for(char &ch : text){
        int c = get_child(ch);
        u = findNext(u, c);
        for(int &v:trie[u].leaf)
            ans[v]++;
    }
}

int q;
string text, pat;

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(nullptr);

    int tc, cs=1; cin >> tc;
    while(tc--){

        trie.clear();
        trie.emplace_back();

        cout << "Case " << cs++ << ":\n";
        cin >> q >> text;
        for(int i=0; i<q; i++)
            cin >> pat, add(pat, i), ans[i] = 0;

        build();
        search(text);

        for(int i=0; i<q; i++)
            cout << ans[i] << '\n';
    }

    return 0;
}

