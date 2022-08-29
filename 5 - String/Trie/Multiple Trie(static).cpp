/**
 * @file Multiple Trie(static)
 * @author Md Turin
 * @brief 
 * @date 2022-08-30
 * 
 * @copyright Copyright (c) 2022
 * @problem: Vugol Search - ICPC Preli 2018
 * 
 */

#include<bits/stdc++.h>
using namespace std;
using ll = long long;

const int child = 26;
const int mx = 2e5 + 5;
const int mxt = mx * child;

int sz, t[mx][child], cnt[mx];

inline void init(){
    sz = 1; cnt[sz] = 0;
    memset(t[sz], 0, sizeof t[sz]);
}

inline void clr(int p, int u){
    t[p][u] = ++sz; cnt[sz] = 0;
    memset(t[sz], 0, sizeof t[sz]);
}

inline int get_val(char c){return c - 'a';}

inline void add(string &s, int root, int val){
    int p = root;
    cnt[p] = max(cnt[p], val);
    for(char &c : s){
        int u = get_val(c);
        if(!t[p][u]) clr(p, u);
        p = t[p][u];
        cnt[p] = max(cnt[p], val);
    }
}

inline int query(string &s, int root){
    int p = root;
    int ans = cnt[p];
    for(int i=0; i<s.size(); ++i){
        int u = get_val(s[i]);
        if(!t[p][u]) return ans;
        p = t[p][u];
        ans = max(ans, i + 1 + cnt[p]);
    }return ans;
}

int main(){

    string s; init();
    map<string, int> mp;
    vector<int> roots(1, 1);

    int n;
    vector<int> a(n);

    cin >> n;
    for(int i=0; i<n; ++i)
        cin >> a[i];

    for(int i=0; i<n; ++i){
        cin >> s;
        add(s, roots[0], 0);

        string org = s; 
        sort(s.begin(), s.end());

        if(mp.find(s) == mp.end()){
            clr(0, 0);
            mp[s] = roots.size();
            roots.push_back(sz);
        }

        add(org, roots[mp[s]], a[i]);
    }

    int q; cin >> q; 
    while(q--){
        cin >> s;
        int ans = query(s, roots[0]);

        string org = s;
        sort(s.begin(), s.end());
        int res = query(org, roots[mp[s]]);

        cout << max(ans, res) << "\n";
    }

    return 0;
}