#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int,int> pii;

const double eps=3e-8;
const int mx = 1e5+5;

vector<int> OddManacher(string &s){
    int n = s.size(); vector<int> ans(n);
    for(int i=0,l=0,r=-1; i<n; i++){
        int k = (i>r)?1:min(ans[l+r-i], r-i+1);
        while(k<=i && i+k<n && s[i-k]==s[i+k]) k++;
        ans[i] = k--; if(i+k>r) l=i-k, r=i+k;
    }return move(ans);
}

vector<int> EvenManacher(string &s){
    int n = s.size(); vector<int> ans(n);
    for(int i=0,l=0,r=-1; i<n; i++){
        int k = (i>r)?0:min(ans[l+r-i+1], r-i+1);
        while(k<=i && i+k<n && s[i-k-1]==s[i+k]) k++;
        ans[i] = k--; if(i+k>r) l=i-k-1, r=i+k;
    }return move(ans);
}

int main(){

    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    string s = "abbabbabb";
    vector<int> ans = OddManacher(s);
    vector<int> res = EvenManacher(s);

    for(int i=0; s[i]; i++)
        printf("%c ", s[i]); puts("");
    for(int u:ans)
        printf("%d ", u); puts("");
    for(int u:res)
        printf("%d ", u); puts("");
        
    return 0;
}

