#include<bits/stdc++.h>
using namespace std;

#define pb push_back
using vi = vector<int>;
vi kmpPiTabel(string &s){
    int n = s.size(), j=0;
    vector<int> pi(n,0);
    for(int i=1; i<n; i++){
        while(j && s[i] != s[j])
            j = pi[j-1];
        if(s[i] == s[j]) j++;
        pi[i] = j;
    }
    return move(pi);
}

vi KMP(string t, string p){
    vi pi = kmpPiTabel(p); vi ans;
    for(int i=0, j=0; i<t.size(); i++){
        while(j && p[j]!=t[i])
            j = pi[j-1];
        if(p[j] == t[i]) j++;
        if(j == p.size())
            ans.pb(i-j+1);
    }
    return move(ans);
}

int main(){
    vi ans = KMP("aaaaabbaa", "ab");
    for(auto p:ans)
        cout << p << " ";
    return 0;
}

