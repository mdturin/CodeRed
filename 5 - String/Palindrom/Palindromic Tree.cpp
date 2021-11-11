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

char s[mx]; 
int tree[mx][26], idx, t;
int ans[mx], pt[mx], en[mx];
int len[mx], link[mx], occ[mx];

/// initialize
void init(){
    memset(ans, 0, sizeof ans);
    memset(occ, 0, sizeof occ);
    memset(tree, 0, sizeof tree);

    len[1] = -1; link[1] = 1;
    len[2] = 0;  link[2] = 1;
    idx = t = 2;
}

/// extending palindromic tree
void extend(int p){
    while(s[p-len[t]-1] != s[p]) t=link[t];
    int x = link[t], c = s[p] - 'a';
    while(s[p-len[x]-1] != s[p]) x=link[x];
    if(!tree[t][c]){
        tree[t][c] = ++idx;
        len[idx] = len[t] + 2;
        link[idx] = (len[idx] == 1) ? 2 : tree[x][c];
        ans[idx] = 1 + ans[link[idx]];
    }pt[p] = t = tree[t][c]; en[t] = p; ++occ[t];
}

/// distinct number of palindrom
void distinct_number_of_palindrom(){
    cin >> s;
    int n = strlen(s); init();
    for(int i=0; i<n; i++)
        extend(i);
    cout << (idx-2) << "\n";
}

/// number of palindrom sub-string ends in every position
void number_of_palindrom_sub_string_ends_in_every_position(){
    cin >> s;
    int n = strlen(s); init();
    for(int i=0; i<n; i++){
        extend(i);
        cout << i << " " << ans[t] << "\n";
    }
}

/// ApIO 2014 - Palindrome
/// find maximum value of ∣P∣ * occ(P)
void apio_2014_palindrome(){
    cin >> s;
    int n = strlen(s); init();
    for(int i=0; i<n; i++) extend(i);
    for(int i=idx; i>2; i--)
        occ[link[i]] += occ[i];
    int ans = 0;
    for(int i=2; i<=idx; i++)
        ans = max(ans, len[i] * occ[i]);
    cout << ans << "\n";
}

int main(){

    ios_base::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);



    return 0;
}

