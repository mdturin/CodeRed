#include<bits/stdc++.h>
using namespace std;

/**
    PI Table return array which indicates lengths of
    longest proper prefix which is also suffix
    For the pattern “AABAACAABAA”, 
    return : [0, 1, 0, 1, 2, 0, 1, 2, 3, 4, 5]
*/

vector<int> get_pi_tabel(string &pat){
    int n = pat.size();
    vector<int> pi(n, 0);
    for(int i=1,j=0; i<n; i++){
        while(j && pat[i] != pat[j])
            j = pi[j-1];
        if(pat[i] == pat[j]) j++;
        pi[i] = j;
    }return move(pi);
}

vector<int> KMP(string text, string pat){
    vector<int> pi = get_pi_tabel(pat), ans;
    for(int i=0, j=0; i<text.size(); i++){
        while(j && pat[j]!=text[i])
            j = pi[j-1];
        if(pat[j] == text[i]) j++;
        if(j == pat.size())
            ans.push_back(i-j+1);
    }return move(ans);
}

int main(){

    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    vector<int> ans = KMP("aaaaabbaa", "ab");

    for(int p : ans)
        cout << p << " ";
    cout << endl;

    return 0;
}

