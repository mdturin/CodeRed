#include<bits/stdc++.h>
using namespace std;
using ll = long long;
using ii = pair<int,int>;

#define ff first
#define se second
#define pb push_back
#define all(x) (x).begin(),(x).end()

const int mod = 1e9+7;
const int inf = 1e9;
const int mx  = 1e6+5;

int tree[mx][26], idx;
char s[mx]; int ans[mx], pt[mx];
int len[mx], link[mx], t, occ[mx];

/// initialize
void init(){
    memset(ans, 0, sizeof ans);
    memset(occ, 0, sizeof occ);
    memset(tree, 0, sizeof tree);

    len[1] = -1; link[1] = 1;
    len[2] = 0;  link[2] = 1;
    idx = t = 2;
}

void extend(int p){
    while(s[p-len[t]-1] != s[p]) t=link[t];
    int x = link[t], c = s[p] - 'a';
    while(s[p-len[x]-1] != s[p]) x=link[x];
    if(!tree[t][c]){
        tree[t][c] = ++idx;
        len[idx] = len[t] + 2;
        link[idx] = (len[idx] == 1) ? 2 : tree[x][c];
        ans[idx] = 1 + ans[link[idx]];
    }pt[p] = t = tree[t][c]; ++occ[t];
}

deque<char> dq;
vector<string> str;
void fun(int i, bool odd){
    string st(dq.begin(), dq.end());
    if(dq.size()) str.push_back(st);

    for(int j=0; j<26; ++j){
        if(tree[i][j]){
            dq.push_front((char)(j + 'a'));
            if(!odd) 
                dq.push_back((char)(j + 'a'));

            fun(tree[i][j], 0);

            if(dq.size()) dq.pop_back();
            if(dq.size()) dq.pop_front();
        }
    }
}

int main(){

    ios_base::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);

    cin >> s;
    int n = strlen(s);

    init();
    for(int i=0; i<n; ++i) extend(i);
    
    dq.clear(); fun(1, 1);
    dq.clear(); fun(2, 0);

    sort(str.begin(), str.end());
    for(auto &it : str)
        cout << it << "\n";

    return 0;
}