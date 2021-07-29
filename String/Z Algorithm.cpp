#include <bits/stdc++.h>
using namespace std;

/** 
Z - Algorithm : z[i] is the length of the 
longest common prefix between s and s[i...n] 
*/

vector<int> zAlgo(string &s){
    int n = s.size(); vector<int> z(n);
    for(int i=1, l=0, r=0; i<n; i++){
        if(i <= r) z[i] = min(r-i+1, z[i-l]);
        while(i+z[i]<n && s[z[i]] == s[i+z[i]])
            z[i]++;
        if(i+z[i]-1 > r) l = i, r = i + z[i] - 1;
    }return move(z);
}

int stringMatching(string &pat, string &text){
    string modifiedTest = pat + '$' + text;
    vector<int> ans = zAlgo(modifiedTest);
    int res = 0;
    for(int u : ans)
        if(u == pat.size())
            res++;
    return res;
}

int main(){

    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    string pat = "hello";
    string text = "helloWorldhello!!";
    cout << stringMatching(pat, text) << "\n";

    return 0;
}
